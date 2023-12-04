#include <iostream>
#include <fstream>
#include <string>

// Function to convert Fahrenheit to Celsius
int fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    // Open the input file for reading
    std::ifstream inputFile("FahrenheitTemperature.txt");
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Open the output file for writing
    std::ofstream outputFile("CelsiusTemperature.txt");
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    std::string city;
    int fahrenheitTemp;

    // Read each city and its temperature from the input file
    while (inputFile >> city >> fahrenheitTemp) {
        // Convert the temperature to Celsius
        int celsiusTemp = fahrenheitToCelsius(fahrenheitTemp);

        // Write the city and its temperature in Celsius to the output file
        outputFile << city << " " << celsiusTemp << std::endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "Conversion complete. Check CelsiusTemperature.txt for results." << std::endl;
    return 0;
}
