//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_USERSERVICE_H
#define UNTITLED_USERSERVICE_H

#include "../model/User.h"
#include "../repository/UserRepository.h"
class UserService {
private:
    UserRepository userRepository = UserRepository();
public:
    UserService();
    void AddUser(User user);
    bool IsUserExist(std::string username);
    void changeUserPassword(int userID, std::string newPassword);
    User* login(std::string username, std::string password);
};


#endif //UNTITLED_USERSERVICE_H
