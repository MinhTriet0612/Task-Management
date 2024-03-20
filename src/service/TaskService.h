//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_TASKSERVICE_H
#define UNTITLED_TASKSERVICE_H

#include "../model/Task.h"
#include "../repository/TaskRepository.h"


class TaskService {
private:
    TaskRepository taskRepository = TaskRepository();
public:

    void addTask(Task *task);

    void updateTask(Task *task, int user_id);

    void deleteTask(int taskId, int user_id);

    std::vector<Task *> getTasks(int user_id);

    Task* getTask(int taskId, int user_id);

};


#endif //UNTITLED_TASKSERVICE_H
