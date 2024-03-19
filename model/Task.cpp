//
// Created by minhtriet on 19/03/2024.
//

#include "Task.h"

Task::Task() {}


void Task::display() const {
    std::cout << "Title: " << this->getTitle() << std::endl;
    std::cout << "Date: " << this->getDate().day << "/" << this->getDate().month << "/" << this->getDate().year << std::endl;
    std::cout << "Description: " << this->getDescription() << std::endl;
    std::cout << "Status: " << this->getStatus() << std::endl;
    std::cout << "Priority: " << this->getPriority() << std::endl;
}

Task::Task(int userId, std::string title, Date date, std::string description) {
    this->user_id = userId;
    this->title = title;
    this->date = date;
    this->description = description;
    this->status = static_cast<Task::Status>(0);
    this->priority = static_cast<Task::Priority>(0);
}

int Task::getUserId() const {
    return user_id;
}

void Task::setUserId(int userId) {
    user_id = userId;
}

const std::string &Task::getTitle() const {
    return title;
}

void Task::setTitle(const std::string &title) {
    Task::title = title;
}

const Task::Date &Task::getDate() const {
    return date;
}

void Task::setDate(const Task::Date &date) {
    Task::date = date;
}

const std::string &Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string &description) {
    Task::description = description;
}

Task::Status Task::getStatus() const {
    return status;
}

void Task::setStatus(Task::Status status) {
    Task::status = status;
}

Task::Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(Task::Priority priority) {
    Task::priority = priority;
}

