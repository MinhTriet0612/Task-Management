#include <iostream>

using namespace std;

#include "model/Task.h"
#include "model/User.h"
int main() {
    std::vector<Task> tasks;

    Task task1 = Task(1, "Task 1", Task::Date{1, 1, 2024}, "Description 1");
    task1.display();
}
