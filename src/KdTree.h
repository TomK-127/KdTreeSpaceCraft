#include <iostream>
#include "KdNode.h"

using namespace std;

class KdTree
{
public:
    KdTree();

    /// @brief Creates a new node and inserts it into the kd tree
    /// @param position x, y, z coordinates of node
    /// @param name of planet/node
    void AddTreeNode(float position[3], string name);

    /// @brief Entry into recursive search down kd tree for nearest neighbor
    /// @param position x, y, z coordinates of target location from which to search
    /// @return name of planet/node closest to target location
    string FindNearestNeighbor(float position[3]);

private:
    /// @brief Recursive search down kd tree for nearest neighbor
    /// @param curr_node node of subtree being searched
    /// @param target node to search for nearest neighbor
    /// @param depth of current node in kd tree
    /// @return closest node to target node
    KdNode* FindNearestNeighbor(KdNode* curr_node, KdNode* target, int depth);

    /// @brief Finds the closest node to a target node
    /// @param node_1 first node to compare
    /// @param node_2 second node to compare
    /// @param target node to find closest node to
    /// @return closest node to target node
    KdNode* ClosestNodeToTarget(KdNode* node_1, KdNode* node_2, KdNode* target);

    /// @brief Calculates the square distance between two nodes
    /// @param node_1 first node to compare
    /// @param node_2 second node to compare
    /// @return square distance between nodes
    float SqDistanceBetweenNodes(KdNode* node_1, KdNode* node_2);

private:
    KdNode* _root;  /// root node of kd tree
};