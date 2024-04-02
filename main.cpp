#include <iostream>
#include <sstream>
#include <string>
#include "src/SpaceCraft.cpp"

using namespace std;

int main()
{
    // Initialize with a csv file containing planet's x,y,z coordinates
    SpaceCraft space_craft("data/planets_1.csv");

    cout << "Welcome to the Kd-Tree Space Craft simulator!" << endl;
    space_craft.PrintStatus();

    // Enter a loop to accept user input
    while (true)
    {
        // Prompt the user for input
        string user_input;
        cout << "Enter command position (x y z) or 'exit' to quit: ";
        getline(cin, user_input);

        // Exit condition
        if (user_input == "exit")
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;  // Exit the loop
        }

        // Parse the user input
        stringstream user_input_stream(user_input);
        float command_position[3];

        if (!(user_input_stream >> command_position[0] >> command_position[1] >> command_position[2]))
        {
            cout << "Invalid input." << endl;
            space_craft.PrintStatus();
            continue;
        }

        // Process new position
        space_craft.UpdatePosition(command_position);
        space_craft.PrintStatus();
    }

    return 0;
}
