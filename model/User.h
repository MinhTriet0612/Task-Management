//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_USER_H
#define UNTITLED_USER_H

#include <vector>
#include "iostream"
#include "string"
class User {
private:
    int id;
    std::vector<int> taskID;
    std::string userName;
    std::string password;

public:
    User();
    User(int id, std::string userName, std::string password, std::vector<int> taskId);

    const std::vector<int> &getTaskId() const;

    void setTaskId(const std::vector<int> &taskId);

    const std::string &getUserName() const;

    void setUserName(const std::string &userName);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);
};


#endif //UNTITLED_USER_H
