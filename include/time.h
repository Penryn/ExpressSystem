#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int year;
    int month;
    int day;

public:
    void setTime(int y, int m, int d) ;

    string getTime() const ;

    int getYear() const ;

    int getMonth() const;

    int getDay() const;
};