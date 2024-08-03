#include <iostream>
#include <string>

struct Node{
    std::string data;
    Node *next;
};

class Lilist{
    public:
        Lilist() {head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();

    private:
        Node *head;
};

void Lilist::add(std::string item){
    Node *tmp;

    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    } else{
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next);
        // This loop just advances the pointer to the last node in the list
        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next)
        std::cout << tmp -> data << " ";
    std::cout << std::endl;
}

Node* Lilist::search(std::string target){
    Node *cursor;

    cursor = head;
    while(cursor -> next != NULL){
        if(cursor -> data == target)
            return cursor;
        cursor = cursor -> next;
    }
    return NULL;
}

void Lilist::move_front_to_back(){
    Node *cursor;
    Node *firstNode;

    cursor = head;
    firstNode = head;
    head = head -> next;
    while(cursor -> next != NULL)
        cursor = cursor -> next;

    cursor -> next = firstNode;
    firstNode -> next = NULL;
}
