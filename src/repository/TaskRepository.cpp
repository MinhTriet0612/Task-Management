////
//// Created by minhtriet on 19/03/2024.
////
//
#include "TaskRepository.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "../model/Task.h"
#include "../util/Util.h"

TaskRepository::TaskRepository() {
}

std::vector<Task *> TaskRepository::getTasksByUserId(int userId) {
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
    res = stmt->executeQuery("SELECT * FROM task WHERE user_id = " + std::to_string(userId));
    std::vector<Task *> tasks;

    while (res->next()) {
        Task* task = Util::MappingTask(res);
        tasks.push_back(task);
    }

    delete stmt;
    delete con;
    delete res;

    return tasks;
}

