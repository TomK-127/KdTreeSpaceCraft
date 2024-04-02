#ifndef KdNode_H
#define KdNode_H

// #include <KdTree.h>
#include <string>
#include <vector>

using namespace std;

class KdNode
{
public:
    /// @brief Constructor for node in KdTree
    /// @param position x, y, z coordinates of node
    /// @param name name of planet/node
    KdNode(float position[3], string name)
    {
        _position[0] = position[0];
        _position[1] = position[1];
        _position[2] = position[2];
        _name = name;
        _left = NULL;
        _right = NULL;
    };

    float _position[3];  /// x, y, z coordinates of node
    KdNode* _left;       /// left child
    KdNode* _right;      /// right child
    string _name;
};

#endif