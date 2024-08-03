#include <iostream>
#include <string>
#include "assignment.h"
#include "node.h"

#ifndef PLANNER_H
#define PLANNER_H

class Planner{
    public:
    Planner(){head = tail = nullptr;}   //Default Constructor

    // BIG 3 //
    ~Planner();
    Planner(const Planner& other);
    Planner& operator = (const Planner& other);

    // Other Functions //
    void add(Assignment a); // Adds assignment IN ORDER by due date (Whats due closest to whats due furthest away)
    void display(std::ostream& outs)const;  // Displays All Assignments
    Assignment find(std::string assignmentName)const; // Finds an assignment given its name
    void remove(std::string assignmentName);    // Removes an assignment given its name
    int waiting()const; // Returns number of assignments waiting to be complete
    unsigned due_next()const;   // Returns the assignment that is due next
    unsigned average_wait()const; // Finds the average wait time for all assignments in seconds
    unsigned oldest()const; // Finds the oldest Assignment in the list
    unsigned newest()const;  // Finds the newest assignment in the list
    void find_all(DateTime d)const; // Finds all assignments due by the date entered

    // I/O Functions //
    void load(std::istream& ins);
    void save(std::ostream& outs)const;

    private:
    node* head;
    node* tail;
};

#endif