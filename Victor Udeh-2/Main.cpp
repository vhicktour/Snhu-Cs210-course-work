// main.cpp

#include "Clock.h"

int main() {
    // Developer information
    std::cout << "Developer Name: Victor Udeh" << std::endl;
    std::cout << "Date: September 2023" << std::endl;

    int h, m, s;
    std::cout << "Enter initial time (HH MM SS): ";
    std::cin >> h >> m >> s;

    Clock myClock(h, m, s);
    char choice;

    do {
        myClock.displayTime();

        std::cout << "\nMenu:\n";
        std::cout << "1. Add Hour\n";
        std::cout << "2. Add Minute\n";
        std::cout << "3. Add Second\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                myClock.addHour();
                break;
            case '2':
                myClock.addMinute();
                break;
            case '3':
                myClock.addSecond();
                break;
            case '4':
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != '4');

    return 0;
}