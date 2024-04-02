#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
// #include "KdTree.h"

using namespace std;

struct Planet
{
    float position[3];
    string name;
};

class SpaceCraft
{
public:
    /// @brief Constructor for SpaceCraft object
    /// @param file_name name of csv file containing planets
    SpaceCraft(string file_name)
    {
        _position[0] = 0.0;
        _position[1] = 0.0;
        _position[2] = 0.0;

        _orientation = "";
    }

    /// @brief Updates internal position of spacecraft based commanded position
    /// @param command_position input position
    void UpdatePosition(float command_position[3])
    {
        _position[0] += command_position[0];
        _position[1] += command_position[1];
        _position[2] += command_position[2];
    }

    /// @brief Prints orientation and position of spacecraft
    void PrintStatus()
    {
        cout << "Space craft (x,y,z) position: " << _position[0] << ", "
             << _position[1] << ", " << _position[2] << endl;
        cout << "Closest planet to space craft: " << _orientation << endl;
    }

public:
    string _orientation; /// name of planet closest to spacecraft

private:
    float _position[3]; /// x, y, z coordinates of spacecraft
};