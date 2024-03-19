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
};

#endif