//
// Created by minhtriet on 19/03/2024.
//

#include "Task.h"
#include "../util/Util.h"

Task::Task() {}

void Task::display() {
    std::cout << "ID: " << this->getId() << std::endl;
    std::cout << "Title: " << this->getTitle() << std::endl;
    std::cout << "StartDate: " << this->getStartDate().day << "/" << this->getStartDate().month << "/"
              << this->getStartDate().year << std::endl;
    std::cout << "Deadline: " << this->getDeadline().day << "/" << this->getDeadline().month << "/"
              << this->getDeadline().year << std::endl;
    std::cout << "Note: " << this->getNote() << std::endl;
    std::cout << "Status: " << Util::ConvertEnumToString(this->getStatus()) << std::endl;
    std::cout << "Priority: " << Util::ConvertEnumToString(this->getPriority()) << std::endl;
    std::cout << "User ID: " << this->getUserId() << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

Task::Task(int userId, std::string title, Date startDate, Date deadline, std::string note) {
    this->user_id = userId;
    this->title = title;
    this->startDate = startDate;
    this->note = note;
    this->deadline = deadline;
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

const Task::Date &Task::getStartDate() const {
    return startDate;
}

void Task::setStartDate(const Task::Date &startDate) {
    Task::startDate = startDate;
}

const Task::Date &Task::getDeadline() const {
    return deadline;
}

void Task::setDeadline(const Task::Date &deadline) {
    Task::deadline = deadline;
}

const std::string &Task::getNote() const {
    return note;
}

void Task::setNote(const std::string &note) {
    Task::note = note;
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

int Task::getId() const {
    return id;
}

void Task::setId(int id) {
    Task::id = id;
}
