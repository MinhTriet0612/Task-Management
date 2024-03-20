//
// Created by minhtriet on 19/03/2024.
//

#include "TaskService.h"

void TaskService::addTask(Task *task) {
    this->taskRepository.addTask(task);
}

std::vector<Task *> TaskService::getTasks(int user_id) {
    return this->taskRepository.getTasksByUserId(user_id);
}

void TaskService::updateTask(Task *task, int user_id) {
    this->taskRepository.updateTask(task, user_id);
}

void TaskService::deleteTask(int taskId, int user_id) {
    this->taskRepository.deleteTaskByUserId(user_id, taskId);
}

Task *TaskService::getTask(int taskId, int user_id) {
    return this->taskRepository.getTaskById(taskId, user_id);
}
