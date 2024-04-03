#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
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
    SpaceCraft(string file_name)
    {
        _position[0] = 0.0;
        _position[1] = 0.0;
        _position[2] = 0.0;

        _kd_tree = KdTree();

        LoadPlanets(file_name);

        _orientation = _kd_tree.FindNearestNeighbor(_position);
    }

    /// @brief Updates internal position of spacecraft based commanded position
    /// @param command_position input position
    void UpdatePosition(float command_position[3])
    {
        _position[0] += command_position[0];
        _position[1] += command_position[1];
        _position[2] += command_position[2];

        _orientation = _kd_tree.FindNearestNeighbor(_position);
    }

    /// @brief Prints orientation and position of spacecraft
    void PrintStatus()
    {
        cout << "Space craft (x,y,z) position: " << _position[0] << ", " << _position[1] << ", " << _position[2]
             << endl;
        cout << "Closest planet to space craft: " << _orientation << endl;
    }

    void AddPlanet(float position[3], string name)
    {
        _kd_tree.AddTreeNode(position, name);

        // Store planets in _planets map
        Planet new_planet = {};
        new_planet.position[0] = position[0];
        new_planet.position[1] = position[1];
        new_planet.position[2] = position[2];
        new_planet.name = name;
        _planets.insert(make_pair(name, new_planet));
    }

    void LoadPlanets(string file_name)
    {
        ifstream csv_file(file_name);
        if (csv_file.is_open())
        {
            string line;
            while (getline(csv_file, line))
            {
                stringstream ss(line);
                string str;

                getline(ss, str, ',');
                string name = str;
                float position[3];
                getline(ss, str, ',');
                position[0] = stof(str);
                getline(ss, str, ',');
                position[1] = stof(str);
                getline(ss, str, ',');
                position[2] = stof(str);

                AddPlanet(position, name);
            }
            csv_file.close();
        }
        else
        {
            cout << "Unable to load planets in system" << endl;
        }
    }

    // TESTING ONLY FUNCTION
    string BruteForceFindClosestPlanet()
    {
        float min_distance = numeric_limits<float>::max();
        string min_planet = "";
        for (auto &planet : _planets)
        {
            float distance = sqrt(
                pow(_position[0] - planet.second.position[0], 2) + pow(_position[1] - planet.second.position[1], 2) + pow(_position[2] - planet.second.position[2], 2));
            if (distance == min_distance)
            {
                // Combine names if they are the same distance away
                min_planet += planet.first;
            }
            else if (distance < min_distance)
            {
                min_distance = distance;
                min_planet = planet.first;
            }
        }
        return min_planet;
    }

public:
    string _orientation; /// name of planet closest to spacecraft

private:
    float _position[3];           /// x, y, z coordinates of spacecraft
    KdTree _kd_tree;              /// kd tree model for planets
    map<string, Planet> _planets; /// dictionary of planets surrounding spacecraft
};