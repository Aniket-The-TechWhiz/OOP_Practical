#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Step 1: Declare a map where keys are state names (string) and values are population (int)
    map<string, int> statePopulation;

    // Step 2: Insert some state names and their populations into the map
    statePopulation["California"] = 39512223;
    statePopulation["Texas"] = 28995881;
    statePopulation["Florida"] = 21477737;
    statePopulation["New York"] = 19453561;
    statePopulation["Pennsylvania"] = 12801989;

    // Step 3: Ask the user to input a state name
    string stateName;
    cout << "Enter the name of a state: ";
    getline(cin, stateName);

    // Step 4: Search for the state in the map
    map<string, int>::iterator it = statePopulation.find(stateName);

    // Step 5: Check if the state exists in the map
    if (it != statePopulation.end()) {
        // If found, display the population of the state
        cout << "The population of " << stateName << " is " << it->second << endl;
    } else {
        // If not found, inform the user that the state is not in the map
        cout << "State not found in the map." << endl;
    }

    return 0;
}

