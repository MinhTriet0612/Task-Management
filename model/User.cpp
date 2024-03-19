//
// Created by minhtriet on 19/03/2024.
//

#include "User.h"

const std::vector<int> &User::getTaskId() const {
    return taskID;
}

void User::setTaskId(const std::vector<int> &taskId) {
    taskID = taskId;
}

const std::string &User::getUserName() const {
    return userName;
}

void User::setUserName(const std::string &userName) {
    User::userName = userName;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

User::User(int id, std::string userName, std::string password, std::vector<int> taskId) {
    this->password = password;
    this->taskID = taskId;
    this->userName = userName;
    this->id = id;
}

User::User() {}
