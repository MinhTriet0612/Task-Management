#include "User.h"

User::User() {}

User::User(int id, const std::string userName, const std::string password) {
    this->id = id;
    this->userName = userName;
    this->password = password;
}

User::User(const std::string userName, const std::string password) {
    this->userName = userName;
    this->password = password;
}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    User::id = id;
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

const std::vector<Task *> &User::getTasksList() const {
    return tasksList;
}

void User::setTasksList(const std::vector<Task *> &tasksList) {
    User::tasksList = tasksList;
}

void User::addTask(Task *task) {
    if (this->tasksList.empty()) {
        this->tasksList = std::vector<Task *>();
    }
    this->tasksList.push_back(task);
}

void User::display() {
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "User: " << this->userName << std::endl;
    std::cout << "Password: " << this->password << std::endl;
    std::cout << "Tasks: " << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
