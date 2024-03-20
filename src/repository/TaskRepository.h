#pragma once
//write that have orm
#ifndef FULLSTACKAPP_TASKREPOSITORY_H
#define FULLSTACKAPP_TASKREPOSITORY_H

#include <vector>
#include "../model/Task.h"

class TaskRepository {
private:

public:
    TaskRepository();

    static std::vector<Task *> getTasksByUserId(int userId);


//    std::vector<Task *> getTasksByStatus(Task::Status status);
//
//    std::vector<Task *> getTasksByDate(Task::Date date);
//
//    std::vector<Task *> getTasksByDateRange(Task::Date startDate, Task::Date endDate);
//
//    std::vector<Task *> getTasksByDateRangeAndStatus(Task::Date startDate, Task::Date endDate, Task::Status status);
//
//    std::vector<Task *>
//    getTasksByDateRangeAndPriorityAndStatus(Task::Date startDate, Task::Date endDate, Task::Priority priority);

    void addTask(Task *task);

    void updateTask(Task *task, int userId);

    void deleteTaskByUserId(int userId, int taskId);
};

#endif