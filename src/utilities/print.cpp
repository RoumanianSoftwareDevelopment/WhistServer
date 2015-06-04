#include "print.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

void PrintData()
{
    time_t t = time(nullptr);
    tm *time = localtime(&t);
    static vector<string> months = {"January", "February", "March", "April",
                                    "May", "June", "July", "August",
                                    "September", "October", "November",
                                    "December"};
    cout << "[";

    if (time->tm_mday < 10)
        cout << "0" << time->tm_mday << " ";
    else
        cout << time->tm_mday << " ";

    cout<< months[time->tm_mon] << " " << 1900 + time->tm_year << " ";

    if (time->tm_hour < 10)
        cout << "0" << time->tm_hour << ":";
    else
        cout << time->tm_hour << ":";

    if (time->tm_min < 10)
        cout << "0" << time->tm_min << ":";
    else
        cout << time->tm_min << ":";

    if (time->tm_sec < 10)
        cout << "0" << time->tm_sec << "]: ";
    else
        cout << time->tm_sec << "]: ";
}

