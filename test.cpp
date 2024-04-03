#include <iostream>
#include <sstream>
#include <string>
#include "src/SpaceCraft.cpp"

using namespace std;

int main()
{
    // Create a spacecraft initialized from a planets csv file
    SpaceCraft space_craft("data/planets_3.csv");
    space_craft.PrintStatus();

    // Generate random +/-10 command positions 500 times. Check with brute force if the result is
    // correct.
    float command_position[3];
    int mismatch_count = 0;
    for (int i = 0; i < 500; i++)
    {
        command_position[0] = rand() % 21 - 10;
        command_position[1] = rand() % 21 - 10;
        command_position[2] = rand() % 21 - 10;
        space_craft.UpdatePosition(command_position);
        space_craft.PrintStatus();

        string actual_closest = space_craft.BruteForceFindClosestPlanet();
        if (actual_closest != space_craft._orientation)
        {
            mismatch_count++;
            cout << "Expected, actual orientation: " << actual_closest << ", " << space_craft._orientation << endl;
        }
    }

    // Print mismatch count
    cout << "Mismatch count: " << mismatch_count << endl;

    return 0;
}