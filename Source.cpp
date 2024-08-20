//**Brytnea Severance
//**August 19, 2024
//**CS-210 Project 3 
//**This program analyzes the text records generated throughout the day.
//**These records list items purchased in chronological order from the time the store opens to the time it closes.


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Function to create a backup file with the frequency of each item
void createBackupFile(const map<string, int>& itemCount);

int main() {
    // File path to the input file
    ifstream inputFile("U:\\Visual Studio 2019\\Projects\\ProjectThree\\Project3\\Project3\\Debug\\CS210_Project_Three_Input_File.txt");

    // Vector to store the items read from the file
    vector<string> items;
    string line;

    // Attempt to open the input file and read its contents
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            items.push_back(line); // Add each line (item) to the vector
        }
        inputFile.close(); // Close the file after reading
    }
    else {
        // Print an error message if the file cannot be opened
        cout << "Unable to open file" << endl;
        return 1; // Exit the program with an error code
    }

    // Create a map to count the frequency of each item
    map<string, int> itemCount;
    for (const auto& item : items) {
        itemCount[item]++; // Increment the count for each item
    }

    // Create a backup data file to store the frequency of items
    createBackupFile(itemCount);

    int choice; // Variable to store the user's menu choice

    do {
        // Display the menu options to the user
        cout << "Menu:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print all items with frequencies" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's menu choice
        switch (choice) {
        case 1: {
            // Option 1: Search for an item and display its frequency
            string searchItem;
            cout << "Enter item to search for: ";
            cin >> searchItem;
            if (itemCount.find(searchItem) != itemCount.end()) {
                // If the item is found, display the frequency
                cout << searchItem << " appears " << itemCount[searchItem] << " times." << endl;
            }
            else {
                // If the item is not found, inform the user
                cout << searchItem << " not found." << endl;
            }
            break;
        }
        case 2: {
            // Option 2: Print all items with their respective frequencies
            for (const auto& pair : itemCount) {
                cout << pair.first << ": " << pair.second << endl;
            }
            break;
        }
        case 3: {
            // Option 3: Print a histogram of item frequencies
            for (const auto& pair : itemCount) {
                cout << pair.first << ": " << string(pair.second, '*') << endl;
            }
            break;
        }
        case 4:
            // Option 4: Exit the program
            cout << "Exiting program." << endl;
            break;
        default:
            // Handle invalid menu choices
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); // Repeat until the user chooses to exit

    return 0; // Exit the program successfully
}

// Function to create a backup file that stores item frequencies
void createBackupFile(const map<string, int>& itemCount) {
    // Open the backup file for writing
    ofstream backupFile("U:\\Visual Studio 2019\\Projects\\ProjectThree\\Project3\\Project3\\Debug\\frequency.dat");
    if (backupFile.is_open()) {
        // Write each item and its frequency to the backup file
        for (const auto& pair : itemCount) {
            backupFile << pair.first << " " << pair.second << endl;
        }
        backupFile.close(); // Close the backup file
    }
    else {
        // Print an error message if the file cannot be created
        cout << "Unable to create backup file." << endl;
    }
}

