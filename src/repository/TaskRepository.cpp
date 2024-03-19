////
//// Created by minhtriet on 19/03/2024.
////
//
//#include "TaskRepository.h"
//#include "mysql_connection.h"
//// i want to connect to databse
//
//TaskRepository::TaskRepository() {
//    this->taskRepository = TaskRepository();
//}
//
//void TaskRepository::addTask(Task task) {
//    this->taskRepository.addTask(task);
//}
//
//void TaskRepository::updateTask(Task task) {
//    this->taskRepository.updateTask(task);
//}
//
//
//void TaskRepository::deleteTask(int taskId) {
//    this->taskRepository.deleteTask(taskId);
//}

#include "TaskRepository.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "../model/Task.h"
TaskRepository::TaskRepository() {
}


std::vector<Task*> TaskRepository::getTaskById(int taskId) {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root" , "" );
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM task WHERE id = " + std::to_string(taskId));
    std::vector<Task*> tasks;
    while (res->next()) {
        Task* task = new Task();
        task->setUserId(res->getInt("id"));
        task->setTitle(res->getString("title"));
//        task->setStatus(res->getString("status"));
//        task->setPriority(res->getString("priority"));
        task->setUserId(res->getInt("user_id"));
        tasks.push_back(task);
    }
    return tasks;
}