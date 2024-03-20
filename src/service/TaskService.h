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
//
//    void updateTask(Task *task, int user_id);
//
//    void deleteTask(int taskId, int user_id);
//
    std::vector<Task *> getTasks(int user_id);

//    Task getTaskById(int taskId);
//
//    std::vector<Task> getTasksByUserId(int userId);
//
//    std::vector<Task> getTasksByStatus(Task::Status status);
//
//    std::vector<Task> getTasksByPriority(Task::Priority priority);
//
//    std::vector<Task> getTasksByDate(Task::Date startday);
//
//    std::vector<Task> getTasksByDateRange(Task::Date startDate, Task::Date endDate);
//
//    std::vector<Task> getTasksByDateRangeAndStatus(Task::Date startDate, Task::Date endDate, Task::Status status);
//
//    std::vector<Task> getTasksByDateRangeAndPriority(Task::Date startDate, Task::Date endDate, Task::Priority priority);


};


#endif //UNTITLED_TASKSERVICE_H
