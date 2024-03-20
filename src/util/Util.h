//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include "../model/Task.h"
#include <unordered_map>
#include <cppconn/resultset.h>
class Util {
public:
    static Task::Date GetCurrentDate();

    static Task::Date FormatDate(Task::Date currentData);

    static bool CompareDate(Task::Date current, Task::Date data);

    static std::string ConvertEnumToString(Task::Status status);

    static std::string ConvertEnumToString(Task::Priority priority);

    static Task::Status ConvertStringToStatus(std::string status);

    static Task::Priority ConvertStringToPriority(std::string priority);

    static Task* MappingTask(sql::ResultSet* res);

};



#endif //UNTITLED_UTIL_H
