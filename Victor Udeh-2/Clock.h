#include <iostream>
#include <iomanip>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h = 0, int m = 0, int s = 0);
    void addHour();
    void addMinute();
    void addSecond();
    void displayTime();
};