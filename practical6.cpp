#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

// Use the std namespace
using namespace std;

// Define the PersonalRecord struct
struct PersonalRecord {
    string name;
    string dob;  // Format: YYYY-MM-DD
    string phone;

    // Constructor for ease of object creation
    PersonalRecord(string n, string d, string p)
        : name(n), dob(d), phone(p) {}
};

// Function to display the personal records
void displayRecords(vector<PersonalRecord>& records) {
    for (auto& record : records) {
        cout << "Name: " << record.name
             << ", DOB: " << record.dob
             << ", Phone: " << record.phone << endl;
    }
}

// Main function
int main() {
    // Create a vector of personal records
    vector<PersonalRecord> records = {
        {"Alice Johnson", "1990-05-15", "555-1234"},
        {"Bob Smith", "1985-10-20", "555-5678"},
        {"Charlie Brown", "1992-03-30", "555-8765"},
        {"Diana Lee", "1988-07-10", "555-4321"}
    };

    // Sorting the records by name using the built-in sort function
    sort(records.begin(), records.end(), [](PersonalRecord& a, PersonalRecord& b) {
        return a.name < b.name;  // Sort by name alphabetically
    });

    cout << "Sorted Records by Name:" << endl;
    displayRecords(records);

    // Searching for a record by name (using find_if)
    string searchName = "Bob Smith";
    auto it = find_if(records.begin(), records.end(), [&searchName](PersonalRecord& record) {
        return record.name == searchName;
    });

    if (it != records.end()) {
        cout << "\nRecord found for " << searchName << ":"
             << "\nName: " << it->name
             << ", DOB: " << it->dob
             << ", Phone: " << it->phone << endl;
    } else {
        cout << "\nRecord not found for " << searchName << endl;
    }

    return 0;
}

