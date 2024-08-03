#include <iostream>
#include <string>
#include <ctime>
#include "planner.h"

using namespace std;

/// BIG 3 ///
Planner::~Planner(){
    node* cursor;

    while(head != nullptr){
        cursor = head;
        head = head -> next();
        delete cursor;
    }
}

Planner::Planner(const Planner& other){ 
    if(other.head == nullptr){
        head = nullptr;
        return;
    } else{
        node* src;
        head = new node(other.head -> data());
        tail = head;

        src = other.head -> next();
        while(src != nullptr){
            tail -> set_next(new node(src -> data()));
            src = src -> next();
            tail = tail -> next();
        }
    }
}

Planner& Planner::operator = (const Planner& other){ 
    if(this == &other){ // Check for self assignment
        return *this;
    }

    // Delete Old List 
    node* cursor;
    while(head != nullptr){
        cursor = head;
        head = head -> next();
        delete cursor;
    }

    // Make a copy
    if(other.head == nullptr){
        head = nullptr;
        return *this;
    } else{
        node* src;
        head = new node(other.head -> data());
        tail = head;

        src = other.head -> next();
        while(src != nullptr){
            tail -> set_next(new node(src -> data()));
            src = src -> next();
            tail = tail -> next();
        }
    }
}

/// OTHER FUNCTIONS ///
void Planner::add(Assignment a){
    node* cursor = head;
    node* tmp = new node(a);

    if(head == nullptr){    // If list is empty
        head = tmp;
    } else if(head -> data().get_due() > a.get_due()){  // if new assignment due date is earlier than head assignment
        tmp -> set_next(head);
        head = tmp;
    } else{
        while(cursor -> next() != nullptr && cursor -> next() -> data().get_due() < a.get_due()){   // If the next element is due sooner than the passed assignment
            cursor = cursor -> next();
        }
        tmp -> set_next(cursor -> next());
        cursor -> set_next(tmp);
    }
}

void Planner::display(ostream& outs)const{
    node* cursor = head;
    while(cursor != nullptr){
        outs << cursor -> data();
        cursor = cursor -> next();
    }
}

Assignment Planner::find(string assignmentName)const{
    node* cursor = head;
    Assignment tmp;

    while(cursor != nullptr){
        if(cursor -> data().get_name() == assignmentName){ 
            tmp = cursor -> data();
            return tmp;
        }
        cursor = cursor -> next();
    }
    cout << "Assignment name " << assignmentName << " not found.\n";    // If name is not found, will exit while loop. If name found, it will not exit while loop
    return Assignment();
}

void Planner::remove(string assignmentName){
    node* cursor = head;
    node* prev = nullptr;

    while(cursor != nullptr){
        if(cursor -> data().get_name() == assignmentName){  // Check to see if cursor is pointing to the correct assignment to remove
            if(prev == nullptr){ // If the node to remove is the head
                head = cursor -> next();
            } else{ // If node is anywhere else
                prev -> set_next(cursor -> next());
            }
            delete cursor;
            return;
        }
        prev = cursor;
        cursor = cursor -> next();
    }
    cout << "Assignment " << assignmentName << " not found." << endl;   // If the assignment name entered was not found in the list
}

int Planner::waiting()const{
    node* cursor = head; 
    int counter = 0;
    if(cursor == nullptr){  // If list is empty return 0 assignment waiting
        return counter;
    }
    while(cursor != nullptr){   // Iterate through each assignment adding 1 to counter each time
        counter++;
        cursor = cursor -> next();
    }
    return counter;
}

unsigned Planner::due_next()const{  // Because list SHOULD be in order we just find minutes_til_due of the head
    if(head == nullptr){
        // If list is empty
        return 0;
    } else{ // If list is not empty
        unsigned tmp = head -> data().minutes_til_due();
        return tmp;
    }

}

unsigned Planner::average_wait()const{
    node* cursor = head;
    int nodeCount;
    unsigned totalWait = 0;

    while(cursor != nullptr){
        totalWait += cursor -> data().minutes_waiting();    // Setting the total wait time to add on each elements waiting time 
        nodeCount++;    // Increasing nodeCount by 1 each loop to keep track of denominator
        cursor = cursor -> next();
    }
    unsigned avgWait = totalWait / nodeCount;   // Average division 
    return avgWait;
}

unsigned Planner::oldest()const{
    if(head == nullptr){    // If list is empty
        return 0;
    }
    node* cursor = head -> next();
    node* oldest = head;    // Defining oldest 

    while(cursor != nullptr){
        if(cursor -> data().minutes_waiting() > oldest -> data().minutes_waiting()){    // If the elements @ cursors minutes waiting is greater than the oldest's minutes waiting set oldest = to cursor
            oldest = cursor;
        }
        cursor = cursor -> next();
    }
    return oldest -> data().minutes_waiting();
}

unsigned Planner::newest()const{
    if(head == nullptr){    // If list is empty
        return 0;
    }
    node* cursor = head -> next();
    node* newest = head;

    while(cursor != nullptr){
        if(cursor -> data().minutes_waiting() < newest -> data().minutes_waiting()){ // If the elements @ cursors minutes waiting is less than the oldest's minutes waiting set oldest = to cursor
            newest = cursor;
        }
        cursor = cursor -> next();
    }
    return newest -> data().minutes_waiting();
}

void Planner::find_all(DateTime d)const{
    node* cursor = head;

    while(cursor != nullptr){ 
        if(cursor -> data().get_due() < d){ // Iterate through each element checking if the get due time is less than the due time entered
            cout << cursor -> data();
        }
        cursor = cursor -> next();
    }
}

/// I/O FUNCTIONS ///
void Planner::load(istream& ins){
    node* cursor = head;
    Assignment a;
    a.input(ins);
    
    while(ins.peek() != EOF){
        if(head == nullptr){  // If list is empty
            head = new node(a);
            cursor = head;
        } else{
            if(cursor -> next() == nullptr){    // If next node is nullptr (adding to back of list)
                cursor -> set_next(new node(a));
                cursor = cursor -> next();
            } else{
                cursor = cursor -> next();  // anything else
                cursor -> set_data(a);
            }
        }
        a.input(ins);
    }
}

void Planner::save(ostream& outs)const{
    node* cursor = head;

    while(cursor != nullptr){
        cursor -> data().output(outs);
        cursor = cursor -> next();
    }
}

