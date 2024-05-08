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

    string getTime() ;

    int getYear() ;

    int getMonth();

    int getDay();
};