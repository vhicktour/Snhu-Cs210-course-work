#include <iostream>
#include <fstream>
#include <map>
#include <string>

class GroceryTracker {
private:
    // Map to store the frequency of each grocery item
    std::map<std::string, int> itemsFrequency;

    // Private method to read items from a file and populate the map
    void readFromFile(const std::string& filename);

public:
    // Constructor that accepts the filename as an argument
    GroceryTracker(const std::string& filename);

    // Method to search for a specific item and print its frequency
    void findSpecificItem();

    // Method to display all items and their frequencies
    void displayAllItems();

    // Method to display a histogram of item frequencies
    void displayHistogram();
};
