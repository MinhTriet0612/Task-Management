#pragma once
#ifndef FULLSTACKAPP_TASKREPOSITORY_H
#define FULLSTACKAPP_TASKREPOSITORY_H

#include <vector>
#include "../model/Task.h"

class TaskRepository {
private:

public:
    TaskRepository();

    std::vector<Task *> getTasksByUserId(int userId);

    Task *getTaskById(int taskId, int userId);

    void addTask(Task *task);

    void updateTask(Task *task, int userId);

    void deleteTaskByUserId(int userId, int taskId);
};

#endif