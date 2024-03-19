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
    std::vector<Task*> getTaskById(int taskId);
    std::vector<Task*> getTasks();
    std::vector<Task*> getTasksByUserId(int userId);
    std::vector<Task*> getTasksByStatus(Task::Status status);
    std::vector<Task*> getTasksByPriority(Task::Priority priority);
    std::vector<Task*> getTasksByDate(Task::Date date);
    std::vector<Task*> getTasksByDateRange(Task::Date startDate, Task::Date endDate);
    std::vector<Task*> getTasksByDateRangeAndStatus(Task::Date startDate, Task::Date endDate, Task::Status status);
    std::vector<Task*> getTasksByDateRangeAndPriority(Task::Date startDate, Task::Date endDate, Task::Priority priority);
};

#endif