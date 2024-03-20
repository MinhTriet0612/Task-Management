
#ifndef FULLSTACKAPP_USER_H
#define FULLSTACKAPP_USER_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Task.h"
class User {
private:
    int id;
    std::string userName;
    std::string password;
    std::vector<Task*> tasksList;

public:
    User();
    User(int id, const std::string userName, const std::string password);
    User(const std::string userName, const std::string password);
    int getId() const;

    void setId(int id);

    const std::string &getUserName() const;

    void setUserName(const std::string &userName);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    const std::vector<Task *> &getTasksList() const;

    void setTasksList(const std::vector<Task *> &tasksList);

    void addTask(Task* task);
    void display();
};


#endif //FULLSTACKAPP_USER_H