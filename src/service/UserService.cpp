//
// Created by minhtriet on 19/03/2024.
//

#include "UserService.h"

UserService::UserService() {
}


bool UserService::IsUserExist(std::string username) {
    return userRepository.IsUserExist(username);
}

void UserService::AddUser(User user) {
    if (UserService::IsUserExist(user.getUserName())) {
        std::cout << "User already exists" << std::endl;
    } else {
        userRepository.AddUser(user);
    }
}

void UserService::changeUserPassword(int userID, std::string newPassword) {
    User *user = userRepository.GetUserById(userID);
    if (user != nullptr) {
        user->setPassword(newPassword);
        userRepository.UpdateUser(*user);
    } else {
        std::cout << "User not found" << std::endl;
    }
}