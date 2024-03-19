//
// Created by minhtriet on 19/03/2024.
//

#include <cppconn/sqlstring.h>
#include "Task.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>

Task::Task() {}


void Task::display() const {
    std::cout << "Title: " << this->getTitle() << std::endl;
    std::cout << "Date: " << this->getDate().day << "/" << this->getDate().month << "/" << this->getDate().year << std::endl;
    std::cout << "Description: " << this->getDescription() << std::endl;
    std::cout << "Status: " << this->getStatus() << std::endl;
    std::cout << "Priority: " << this->getPriority() << std::endl;
    std::cout<< "User ID: " << this->getUserId() << std::endl;
    std::cout<< "-----------------------------" << std::endl;
}

Task::Task(int userId, std::string title, Date date, std::string description) {
    this->user_id = userId;
    this->title = title;
    this->date = date;
    this->description = description;
    this->status = TODO;
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

void Task::setStatus(std::string status) {
//    Task::status = status;
}

Task::Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(std::string priority) {
//    Task::priority = priority;
}

