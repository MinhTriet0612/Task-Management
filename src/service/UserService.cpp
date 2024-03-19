//
// Created by minhtriet on 19/03/2024.
//

#include "UserService.h"
#include "../repository/UserRepository.h"

UserService::UserService() {
}


bool UserService::IsUserExist(std::string username) {
    return this->userRepository.GetUserByUsername(username) != nullptr;
}

void UserService::AddUser(User user) {
    if (UserService::IsUserExist(user.getUserName())) {
        std::cout << "User already exists" << std::endl;
    } else {
        userRepository.AddUser(user);
    }
}