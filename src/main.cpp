#include "iostream"
#include "string"
#include "vector"

#include "./model/Task.h"
#include "./repository/TaskRepository.h"
//#include "util/Util.h"
#include "repository/UserRepository.h"
//#include "service/UserService.h"
#include "service/TaskService.h"

int main() {
    UserRepository userRepository;
    std::vector<User *> users = userRepository.GetAllUsers();
    for (User *user: users) {
        user->display();
    }

    Task::Date startDate = {12, 12, 2024};
    Task::Date deadline = {12, 12, 2024};
    Task *task = new Task(3, "Task 1", startDate, deadline, "Note 1");
//    taskRepository.addTask(task);
    TaskService taskService;
    taskService.addTask(task);
}
