////
//// Created by minhtriet on 19/03/2024.
////
//
#include "TaskRepository.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
//#include "../model/Task.h"
#include "../util/Util.h"

//TaskRepository::TaskRepository() {
//}

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
        Task *task = Util::MappingTask(res);
        tasks.push_back(task);
    }

    delete stmt;
    delete con;
    delete res;

    return tasks;
}

void TaskRepository::addTask(Task *task) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
//    INSERT INTO task (user_id, title, startDate, note, status, priority, deadline) values(
//            3, "Nguyen Minh Triet" , '2024-12-12', "di hoc", "TODO", "IN_DAY", '2024-12-12'
//    )
//above code is template to inster data

    stmt->execute("INSERT INTO task (user_id, title, startDate, note, status, priority, deadline) values(" +
                  std::to_string(task->getUserId()) + ", '" + task->getTitle() + "', '" +
                  std::to_string(task->getStartDate().year) + "-" + std::to_string(task->getStartDate().month) + "-" +
                  std::to_string(task->getStartDate().day) + "', '" + task->getNote() + "', '" +
                  Util::ConvertEnumToString(task->getStatus()) + "', '" +
                  Util::ConvertEnumToString(task->getPriority()) + "', '" +
                  std::to_string(task->getDeadline().year) + "-" + std::to_string(task->getDeadline().month) + "-" +
                  std::to_string(task->getDeadline().day) + "')");

    delete stmt;
    delete con;
}

void TaskRepository::updateTask(Task *task, int userId) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    stmt->execute("UPDATE task SET title = '" + task->getTitle() +
                  "', start_date = '" + std::to_string(task->getStartDate().year) + "-" +
                  std::to_string(task->getStartDate().month) + "-" + std::to_string(task->getStartDate().day) +
                  "', note = '" + task->getNote() + "', status = '" +
                  Util::ConvertEnumToString(task->getStatus()) + "', priority = '" +
                  Util::ConvertEnumToString(task->getPriority()) + "' WHERE id = " +
                  std::to_string(task->getId()) + " AND user_id = " + std::to_string(userId));

    delete stmt;
    delete con;
}

void TaskRepository::deleteTaskByUserId(int userId, int taskId) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306",
                          "root",
                          "");
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    stmt->execute("DELETE FROM task WHERE id = " + std::to_string(taskId) + " AND user_id = " + std::to_string(userId));

    delete stmt;
    delete con;
}

TaskRepository::TaskRepository() {

}

