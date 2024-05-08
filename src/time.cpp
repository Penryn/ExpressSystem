#include "../include/time.h"


void Time::setTime(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

string Time::getTime() {
    return to_string(year) + "." + to_string(month) + "." + to_string(day);
}

int Time::getYear() {
    return year;
}

int Time::getMonth() {
    return month;
}

int Time::getDay() {
    return day;
}

