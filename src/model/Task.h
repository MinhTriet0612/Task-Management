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
        IN_DAY,
        IN_WEEK,
        IN_MONTH,
    };

    struct Date {
        int day;
        int month;
        int year;
    };

    Task();

    Task(int userId, std::string title, Date startDate, std::string description);

    int getUserId() const;

    void setUserId(int userId);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const Date &getStartDate() const;

    void setStartDate(const Date &startDate);

    const Date &getDeadline() const;

    void setDeadline(const Date &deadline);

    const std::string &getNote() const;

    void setNote(const std::string &note);

    Status getStatus() const;

    void setStatus(Status status);

    Priority getPriority() const;

    void setPriority(Priority priority);

    void display();

private:
    int id;
public:
    int getId() const;

    void setId(int id);

private:
    std::string title;
    struct Date startDate;
    struct Date deadline;
    std::string note;
    enum Status status;
    enum Priority priority;
    int user_id;
};


#endif //UNTITLED_TASK_H
