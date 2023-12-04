#include "Clock.h"

Clock::Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void Clock::addHour() {
    hours = (hours + 1) % 24;
}

void Clock::addMinute() {
    minutes += 1;
    if (minutes == 60) {
        minutes = 0;
        addHour();
    }
}

void Clock::addSecond() {
    seconds += 1;
    if (seconds == 60) {
        seconds = 0;
        addMinute();
    }
}

void Clock::displayTime() {
    // Display 24-hour format
    std::cout << "24-hour format: ";
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds << std::endl;

    // Display 12-hour format
    std::cout << "12-hour format: ";
    int hour12 = (hours % 12) ? (hours % 12) : 12;
    std::string am_pm = (hours < 12) ? "AM" : "PM";
    std::cout << std::setfill('0') << std::setw(2) << hour12 << ":"
              << std::setw(2) << minutes << ":"
              << std::setw(2) << seconds << " " << am_pm << std::endl;
}