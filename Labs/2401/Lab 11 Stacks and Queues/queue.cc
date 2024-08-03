/*************************************************************************
	Kyle Chiasson			Spring 2024
*************************************************************************/

#include <cstdlib>
#include <iostream>
#include <queue>
#include "queue.h"

using namespace std;

bool Chore::operator < (const Chore& other) const{
    return this->priority < other.priority;
}

void Chore::input(std::istream& ins){
    if(&ins == &cin){
        cout << "Chore Description: ";
        getline(ins >> ws, description);
        cout << "Priority level: ";
        ins >> priority;
    }else{
        getline(ins >> ws, description);
        ins >> priority;
    }
    
}

void Chore::output(std::ostream& outs) const { 
    if(&outs == &cout){
        outs << "Chore Description: " << description << endl;
        outs << "Chore Priority: " << priority << endl;
    }else{
        outs << description << endl;
        outs << priority << endl;
    }
    
}

void GetFiveChores(std::istream& ins, std::ostream& outs){
    //define a queue and priority queue here
    priority_queue<Chore> pq;
    queue<Chore> q; 
    Chore chore;

    for(int i = 0; i < 5; i++){
        chore.input(ins);
        q.push(chore);
        pq.push(chore);
    }

    outs << "Outputting Queue:\n";
    for(int i = 0; i < 5; i++){
        //output of queue
        q.front().output(outs);
        q.pop();
    }

    outs << "Outputting Priority Queue:\n";
    for(int i = 0; i < 5; i++){
        //output of priority queue
        pq.top().output(outs);
        pq.pop();
    }
}