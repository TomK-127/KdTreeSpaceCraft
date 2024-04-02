#include "KdTree.h"
#include <cmath>
#include "KdNode.h"

KdTree::KdTree()
{
    _root = NULL;
}

void KdTree::AddTreeNode(float position[3], string name)
{
    KdNode* new_node = new KdNode(position, name);
    int depth = 0;
    if (_root == NULL)
    {
        _root = new_node;
    }
    else
    {
        KdNode* current_node = _root;
        while (current_node)
        {
            if (new_node->_position[depth % 3] >= current_node->_position[depth % 3])
            {
                if (current_node->_right == NULL)
                {
                    current_node->_right = new_node;
                    break;
                }
                else
                {
                    current_node = current_node->_right;
                }
            }
            else
            {
                if (current_node->_left == NULL)
                {
                    current_node->_left = new_node;
                    break;
                }
                else
                {
                    current_node = current_node->_left;
                }
            }
            depth++;
        }
    }
}

string KdTree::FindNearestNeighbor(float position[3])
{
    // Create target node from space craft position
    KdNode* target = new KdNode(position, "space_ship");
    KdNode* closest_node = FindNearestNeighbor(_root, target, 0);

    return closest_node->_name;
}

KdNode* KdTree::FindNearestNeighbor(KdNode* curr_node, KdNode* target, int depth)
{
    if (curr_node == NULL)
    {
        return NULL;
    }
    else
    {
        KdNode* next_node = NULL;
        KdNode* side_node = NULL;

        if (target->_position[depth % 3] >= curr_node->_position[depth % 3])
        {
            next_node = curr_node->_right;
            side_node = curr_node->_left;
        }
        else
        {
            next_node = curr_node->_left;
            side_node = curr_node->_right;
        }

        // Recurse down best branch. Select between this result and current node
        KdNode* best_neighbor = FindNearestNeighbor(next_node, target, depth + 1);
        best_neighbor = ClosestNodeToTarget(curr_node, best_neighbor, target);

        // Check r' - might need to traverse other side of tree
        float sq_distance_to_best = SqDistanceBetweenNodes(target, best_neighbor);
        float r_prime = target->_position[depth % 3] - curr_node->_position[depth % 3];
        if (sq_distance_to_best >= r_prime * r_prime)
        {
            // Recurse down other side of tree
            KdNode* aternative_to_best = FindNearestNeighbor(side_node, target, depth + 1);
            best_neighbor = ClosestNodeToTarget(aternative_to_best, best_neighbor, target);
        }

        return best_neighbor;
    }
}

KdNode* KdTree::ClosestNodeToTarget(KdNode* node_1, KdNode* node_2, KdNode* target)
{
    if (node_1 == NULL)
    {
        return node_2;
    }
    else if (node_2 == NULL)
    {
        return node_1;
    }
    else
    {
        if (SqDistanceBetweenNodes(node_1, target) < SqDistanceBetweenNodes(node_2, target))
        {
            return node_1;
        }
        else
        {
            return node_2;
        }
    }
}

float KdTree::SqDistanceBetweenNodes(KdNode* node_1, KdNode* node_2)
{
    float distance_x = node_1->_position[0] - node_2->_position[0];
    float distance_y = node_1->_position[1] - node_2->_position[1];
    float distance_z = node_1->_position[2] - node_2->_position[2];

    return pow(distance_x, 2) + pow(distance_y, 2) + pow(distance_z, 2);
}