#include <map>
#include <string>
#include <vector>
#include "KdTree.h"

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
    SpaceCraft(string file_name);

    /// @brief Updates internal position of spacecraft based commanded position
    /// @param command_position input position
    void UpdatePosition(float command_position[3]);

    /// @brief Prints orientation and position of spacecraft
    void PrintStatus();

public:
    string _orientation;  /// name of planet closest to spacecraft

private:
    float _position[3];  /// x, y, z coordinates of spacecraft
};