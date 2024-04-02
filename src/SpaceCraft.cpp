#include "../include/SpaceCraft.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

SpaceCraft::SpaceCraft(string file_name)
{
    _position[0] = 0.0;
    _position[1] = 0.0;
    _position[2] = 0.0;

    _orientation = "";
}

void SpaceCraft::UpdatePosition(float command_position[3])
{
    _position[0] += command_position[0];
    _position[1] += command_position[1];
    _position[2] += command_position[2];
}

void SpaceCraft::PrintStatus()
{
    cout << "Space craft orientation: " << _orientation << " with (x,y,z) position:" << _position[0] << ", "
         << _position[1] << ", " << _position[2] << endl;
}