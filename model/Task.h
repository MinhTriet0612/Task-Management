//
// Created by minhtriet on 19/03/2024.
//

#ifndef UNTITLED_TASK_H
#define UNTITLED_TASK_H

//#pragma comment(lib, "rpcrt4.lib")

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Task {
public:
    enum Status {
        TODO,
        IN_PROGRESS,
        DONE
    };

    enum Priority {
        IN_TODAY,
        IN_WEEK,
        IN_MONTH,
    };

    struct Date {
        int day;
        int month;
        int year;
    };

    Task();

    Task(int userId, std::string title, Date date, std::string description);

    int getUserId() const;

    void setUserId(int userId);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const Date &getDate() const;

    void setDate(const Date &date);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    Status getStatus() const;

    void setStatus(Status status);

    Priority getPriority() const;

    void setPriority(Priority priority);

    void display() const;


private:
    int user_id;
    std::string title;
    struct Date date;
    std::string description;
    enum Status status;
    enum Priority priority;
};


#endif //UNTITLED_TASK_H
