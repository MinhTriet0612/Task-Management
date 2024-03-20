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

std::string Util::ConvertEnumToString(Task::Status status) {
    std::unordered_map<Task::Status, std::string> const statusMap = {
            {Task::TODO,        "TODO"},
            {Task::IN_PROGRESS, "IN_PROGRESS"},
            {Task::DONE,        "DONE"}
    };

    auto it = statusMap.find(status);
    while (it != statusMap.end()) {
        if (it->first == status) {
            return it->second;
        }
    }
}

std::string Util::ConvertEnumToString(Task::Priority priority) {

    std::unordered_map<Task::Priority, std::string> const priorityMap = {
            {Task::IN_DAY,   "IN_DAY"},
            {Task::IN_WEEK,  "IN_WEEK"},
            {Task::IN_MONTH, "IN_MONTH"}
    };

    auto it = priorityMap.find(priority);
    while (it != priorityMap.end()) {
        if (it->first == priority) {
            return it->second;
        }
    }
}


Task::Status Util::ConvertStringToStatus(std::string status) {
    std::unordered_map<std::string, Task::Status> const statusMap = {
            {"TODO",        Task::TODO},
            {"IN_PROGRESS", Task::IN_PROGRESS},
            {"DONE",        Task::DONE}
    };

    auto it = statusMap.find(status);
    while (it != statusMap.end()) {
        if (it->first == status) {
            return it->second;
        }
    }
}


Task::Priority Util::ConvertStringToPriority(std::string priority) {
    std::unordered_map<std::string, Task::Priority> const priorityMap = {
            {"IN_DAY",   Task::IN_DAY},
            {"IN_WEEK",  Task::IN_WEEK},
            {"IN_MONTH", Task::IN_MONTH}
    };

    auto it = priorityMap.find(priority);
    while (it != priorityMap.end()) {
        if (it->first == priority) {
            return it->second;
        }
    }
}

Task *Util::MappingTask(sql::ResultSet *res) {
    Task *task = new Task();
    task->setId(res->getInt("id"));
    task->setTitle(res->getString("title"));
    task->setStatus(
            Util::ConvertStringToStatus(res->getString("status"))
    );
    task->setPriority(
            Util::ConvertStringToPriority(res->getString("priority"))
    );
    task->setUserId(res->getInt("user_id"));
    return task;
}