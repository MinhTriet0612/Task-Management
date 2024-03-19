//
// Created by minhtriet on 19/03/2024.
//

#include "UserRepository.h"
#include "../model/User.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

UserRepository::UserRepository() {
}

void UserRepository::AddUser(User user) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");

    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    stmt->execute("INSERT INTO user (username, password) VALUES"
                  " ('" + user.getUserName() + "', '" + user.getPassword() +
                  "')");

    delete stmt;
    delete con;
}

void UserRepository::RemoveUser(int user_id) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    stmt->execute("DELETE FROM user WHERE id = " +
                  std::to_string(user_id));

    delete stmt;
    delete con;
}

void UserRepository::UpdateUser(User user) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");

    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    stmt->execute("UPDATE user SET username = '" + user.getUserName() +
                  "', password = '" + user.getPassword() + "' WHERE id = " +
                  std::to_string(user.getId()));

    delete stmt;
    delete con;
}

User *UserRepository::GetUserById(int id) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");

    con->setSchema("FullStackApp");
    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT * FROM user WHERE id = " +
                             std::to_string(id));

    User *user = new User();
    while (res->next()) {
        user->setId(res->getInt("id"));
        user->setUserName(res->getString("username"));
        user->setPassword(res->getString("password"));
    }

    delete res;
    delete stmt;
    delete con;
    return user;
}

std::vector<User *> UserRepository::GetAllUsers() {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");

    con->setSchema("FullStackApp");
    stmt = con->createStatement();

    res = stmt->executeQuery("SELECT * FROM user");

    std::vector<User *> users;
    while (res->next()) {
        User *user = new User();
        user->setId(res->getInt("id"));
        user->setUserName(res->getString("username"));
        user->setPassword(res->getString("password"));
        users.push_back(user);
    }

    delete res;
    delete stmt;
    delete con;
    return users;
}

User* UserRepository::GetUserByUsername(std::string username) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");

    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM user WHERE username = '" + username + "'");

    User *user = new User();
    while (res->next()) {
        user->setId(res->getInt("id"));
        user->setUserName(res->getString("username"));
        user->setPassword(res->getString("password"));
    }
    return user;
}

void UserRepository::Save() {
}

void UserRepository::Load() {
}