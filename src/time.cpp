#include "../include/time.h"


void Time::setTime(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

string Time::getTime() const {
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}

int Time::getYear() const {
    return year;
}

int Time::getMonth() const {
    return month;
}

int Time::getDay() const {
    return day;
}

bool Time::operator<(const Time &t) const {
    if (year < t.year) {
        return true;
    } else if (year == t.year) {
        if (month < t.month) {
            return true;
        } else if (month == t.month) {
            return day < t.day;
        }
    }
    return false;
}
