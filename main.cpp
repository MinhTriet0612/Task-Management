#include "iostream"
#include "string"
#include "vector"
// write for me a code that connect to mysql
#include "cppconn/resultset.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/driver.h"
#include "cppconn/connection.h"
#include "cppconn/metadata.h"
#include "model/Task.h"
#include "repository/TaskRepository.cpp"
#include "util/Util.h"
Task::Status getStatus(std::string status) {
    if (status == "TODO") {
        return Task::Status::TODO;
    } else if (status == "IN_PROGRESS") {
        return Task::Status::IN_PROGRESS;
    } else if (status == "DONE") {
        return Task::Status::DONE;
    }
}

Task::Priority getPriority(std::string priority) {
    if (priority == "IN_MONTH") {
        return Task::Priority::IN_MONTH;
    } else if (priority == "IN_DAY") {
        return Task::Priority::IN_DAY;
    } else if (priority == "IN_WEEK") {
        return Task::Priority::IN_WEEK;
    }
}

std::vector<Task *> getTasksById(int id) {

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "");
    con->setSchema("FullStackApp");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM task WHERE id = " + std::to_string(id));
    std::vector<Task *> tasks;
    while (res->next()) {
        Task *task = new Task();
        task->setUserId(res->getInt("id"));
        task->setTitle(res->getString("title"));
//        task->setStatus((const char *) getStatus(res->getString("status")));
//        task->setPriority((const char *) getStatus(res->getString("priority")));
        task->setUserId(res->getInt("user_id"));
        tasks.push_back(task);
    }
    return tasks;
}

int main() {
    Task::Date date = Util::GetCurrentDate();
    std::cout << date.day << "/" << date.month << "/" << date.year << std::endl;
}