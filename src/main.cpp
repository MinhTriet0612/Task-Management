#include "iostream"
#include "string"
#include "vector"

#include "./model/Task.h"
#include "./repository/TaskRepository.h"
#include "util/Util.h"
#include "repository/UserRepository.h"
#include "service/UserService.h"
#include "service/TaskService.h"

int main() {

    TaskService taskService;
    int choice;

    User *user;
    std::string username;
    std::string password;


    UserService userService;


    // i have 2 options, login or register
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::cin.ignore();
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);
            user = userService.login(username, password);
            if (user->getUserName() == "") {
                std::cout << "Invalid username or password" << std::endl;
                return 0;
            }
            break;
        }
        case 2: {
            std::cin.ignore();
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);
            User user = User(username, password);
            userService.AddUser(user);
            std::cout << "User added successfully" << std::endl;
            return 0;
        }
        case 3: {
            std::cout << "Goodbye" << std::endl;
            return 0;
        }
    }

    while (true) {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome " << user->getUserName() << std::endl;
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. Update task" << std::endl;
        std::cout << "3. Delete task" << std::endl;
        std::cout << "4. View tasks" << std::endl;
        std::cout << "5. Change Password" << std::endl;
        std::cout << "6. Sort tasks via priority" << std::endl;
        std::cout << "7. Filter tasks via status" << std::endl;
        std::cout << "8. Filter tasks via title" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string title;
                std::string note;
                int day, month, year;
                std::cin.ignore();
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter note: ";
                std::getline(std::cin, note);
                std::cout << "Enter day: ";
                std::cin >> day;
                std::cout << "Enter month: ";
                std::cin >> month;
                std::cout << "Enter year: ";
                std::cin >> year;
                Task::Date startDate = {day, month, year};

                std::cout << "Enter day: ";
                std::cin >> day;
                std::cout << "Enter month: ";
                std::cin >> month;
                std::cout << "Enter year: ";
                std::cin >> year;

                Task::Date deadline = {day, month, year};
                Task *task = new Task();
                task->setTitle(title);
                task->setStartDate(startDate);
                task->setDeadline(deadline);
                task->setNote(note);
                task->setUserId(user->getId());
                taskService.addTask(task);
                std::cout << "Task added successfully" << std::endl;
                break;
            }
            case 2: {

                std::vector<Task *> tasks = taskService.getTasks(user->getId());

                for (Task *task: tasks) {
                    task->display();
                }
                int taskId;
                std::cout << "Enter task id: ";
                std::cin >> taskId;
                Task *task = taskService.getTask(taskId, user->getId());
                if (task->getTitle() == "") {
                    std::cout << "Task not found" << std::endl;
                    break;
                }
                std::string title;
                std::string note;
                int day, month, year;
                std::cin.ignore();
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter note: ";
                std::getline(std::cin, note);
                std::cout << "Start date:" << std::endl;
                std::cout << "Enter day: ";
                std::cin >> day;
                std::cout << "Enter month: ";
                std::cin >> month;
                std::cout << "Enter year: ";
                std::cin >> year;
                Task::Date startDate = {day, month, year};
                std::cout << "Deadline date:" << std::endl;
                std::cin >> day;
                std::cin >> month;
                std::cin >> year;
                Task::Date deadline = {day, month, year};

                std::cout << "Enter priority: ";
                std::cout << "0. IN_DAY" << std::endl;
                std::cout << "1. IN_WEEK" << std::endl;
                std::cout << "2. IN_MONTH" << std::endl;

                int priority;
                std::cin >> priority;

                std::cout << "Enter status: ";
                std::cout << "0. TODO" << std::endl;
                std::cout << "1. DOING" << std::endl;
                std::cout << "2. DONE" << std::endl;

                int status;
                std::cin >> status;

                task->setPriority(static_cast<Task::Priority>(priority));
                task->setTitle(title);
                task->setStartDate(startDate);
                task->setDeadline(deadline);
                task->setNote(note);
                taskService.updateTask(task, user->getId());

                std::cout << "Task updated successfully" << std::endl;
                break;
            }
            case 3: {
                int taskId;
                std::vector<Task *> tasks = taskService.getTasks(user->getId());
                for (Task *task: tasks) {
                    task->display();
                }
                std::cin.ignore();
                std::cout << "Enter task id: ";
                std::cin >> taskId;
                taskService.deleteTask(taskId, user->getId());
                std::cout << "Task deleted successfully" << std::endl;
                break;
            }

            case 4: {
                std::vector<Task *> tasks = taskService.getTasks(user->getId());
                for (Task *task: tasks) {
                    task->display();
                }
                break;
            }
            case 5: {
                std::string newPassword;
                std::cin.ignore();
                std::cout << "Enter new password: ";
                std::getline(std::cin, newPassword);
                userService.changeUserPassword(user->getId(), newPassword);
                std::cout << "Password changed successfully" << std::endl;
                break;
            }
            case 6: {
                std::vector<Task *> tasks = taskService.getTasks(user->getId());
                std::sort(tasks.begin(), tasks.end(), [](Task *a, Task *b) {
                    return a->getPriority() > b->getPriority();
                });
                for (Task *task: tasks) {
                    task->display();
                }
                break;
            }

            case 7: {
                std::vector<Task *> tasks = taskService.getTasks(user->getId());
                int status;
                std::cout << "Enter status: ";
                // i want to show a list of choice to pick status
                std::cout << "1. TODO" << std::endl;
                std::cout << "2. DOING" << std::endl;
                std::cout << "3. DONE" << std::endl;
                std::cin >> status;
                for (Task *task: tasks) {
                    if (task->getStatus() == status) {
                        task->display();
                    }
                }
                break;
            }

            case 8: {
                std::vector<Task *> tasks = taskService.getTasks(user->getId());
                std::string title;
                std::cin.ignore();
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                for (Task *task: tasks) {
                    if (task->getTitle().find(title) != std::string::npos) {
                        task->display();
                    }
                }
                break;
            }
            case 9: {
                std::cout << "Goodbye" << std::endl;
                return 0;
            }
        }
    }
    return 0;
}