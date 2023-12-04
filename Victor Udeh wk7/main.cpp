#include "GroceryTracker.h"

// Implementation of the readFromFile method
void GroceryTracker::readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    std::string item;
    // Read each item from the file and update the map
    while (inFile >> item) {
        itemsFrequency[item]++;
    }
    inFile.close();

    // Write the frequency data to the backup file, frequency.dat
    std::ofstream outFile("frequency.dat");
    for (auto& [key, val] : itemsFrequency) {
        outFile << key << " " << val << std::endl;
    }
    outFile.close();
}

GroceryTracker::GroceryTracker(const std::string& filename) {
    // Read data from the input file and populate the itemsFrequency map
    readFromFile(filename);
}

void GroceryTracker::findSpecificItem() {
    std::string item;
    std::cout << "Enter the item to search for: ";
    std::cin >> item;

    // Print the frequency of the specified item
    int count = itemsFrequency[item];
    std::cout << "Frequency of " << item << ": " << count << std::endl;
}

void GroceryTracker::displayAllItems() {
    // Print each item and its frequency
    for (auto& [item, count] : itemsFrequency) {
        std::cout << item << " " << count << std::endl;
    }
}

void GroceryTracker::displayHistogram() {
    // Print a histogram for each item
    for (auto& [item, count] : itemsFrequency) {
        std::cout << item << " " << std::string(count, '*') << std::endl;
    }
}

int main() {
    // Create an instance of the GroceryTracker class
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice = 0;
    // Main loop to display the menu and handle user input
    while (choice != 4) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search for specific item frequency.\n";
        std::cout << "2. Display frequency of all items.\n";
        std::cout << "3. Display histogram.\n";
        std::cout << "4. Exit.\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle user choice
        switch (choice) {
        case 1:
            tracker.findSpecificItem();
            break;
        case 2:
            tracker.displayAllItems();
            break;
        case 3:
            tracker.displayHistogram();
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
