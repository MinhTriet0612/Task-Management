//
// Created by minhtriet on 19/03/2024.
//

#include "Util.h"

Task::Date Util::GetCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Task::Date currentDate;
    currentDate.day = ltm->tm_mday;
    currentDate.month = 1 + ltm->tm_mon;
    currentDate.year = 1900 + ltm->tm_year;
    return currentDate;
}

Task::Date Util::FormatDate(Task::Date currentDate) {
    if (currentDate.month < 10) {
        currentDate.month = '0' + currentDate.month;
    }
    if (currentDate.day < 10) {
        currentDate.day = '0' + currentDate.day;
    }
    return currentDate;
}

bool Util::CompareDate(Task::Date currentDate, Task::Date date) {
    if (currentDate.year > date.year) {
        return true;
    } else if (currentDate.year == date.year) {
        if (currentDate.month > date.month) {
            return true;
        } else if (currentDate.month == date.month) {
            if (currentDate.day > date.day) {
                return true;
            }
        }
    }
    return false;
}