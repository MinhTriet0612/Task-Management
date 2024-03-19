//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include "../model/Task.h"

class Util {
public:
    static Task::Date GetCurrentDate();
    static Task::Date FormatDate(Task::Date currentData);
    static bool CompareDate(Task::Date current, Task::Date data);
};


#endif //UNTITLED_UTIL_H
