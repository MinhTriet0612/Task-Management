//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_USERREPOSITORY_H
#define UNTITLED_USERREPOSITORY_H

#include "../model/User.h"

class UserRepository {
public:
    UserRepository();

    void AddUser(User user);

    void RemoveUser(int user_id);

    void UpdateUser(User user);

    User *GetUserById(int id);

    User *GetUserByUsername(std::string username);

    std::vector<User *> GetAllUsers();

    bool IsUserExist(std::string username);

    User *login(std::string username, std::string password);

    void Save();

    void Load();
};


#endif //UNTITLED_USERREPOSITORY_H
