#include <cstdlib>
#include <iostream>

struct node{
     int data;
     node* next;
};

/**
 * @brief remove nodes with repeated values in a linked list
 * 
 * @param head - a pointer to the beginning of a linked list
 */
void remove_repeats(node*& head) {
     if(head -> next == nullptr){
          return;
     }
     node* cursor = head;
     node* tailCursor = cursor;
     node* delCursor;
     cursor = cursor -> next;

     for(node* checkVal = head; checkVal != nullptr; checkVal = checkVal -> next){
          cursor = checkVal -> next;
          tailCursor = checkVal;
          while(cursor != nullptr){
               if(cursor -> data == checkVal -> data){
                    delCursor = cursor;
                    tailCursor -> next = cursor -> next;
                    cursor = cursor -> next;
                    delete delCursor;
               } else{
                    tailCursor = cursor;
                    cursor = cursor -> next;
               }
               
          }
          
     }
}

/**
 * @brief split the original list at a value present in the list
 * 
 * @param original - a pointer to the beginning of a linked list
 * @param lesser - a pointer to the beginning of the lesser value list
 * @param greater - a pointer to the beginning of the greater value list
 * @param split_value - a number to split the list on
 */
void split_list(const node* original, node*& lesser, node*& greater, int split_value) {
     lesser = nullptr;
     greater = nullptr;
     node* lesserTail = nullptr;
     node* greaterTail = nullptr;
     const node* cursor = original;

     while(cursor != nullptr){
          if(cursor -> data < split_value){
               if(lesser == nullptr){   // if lesser is empty
                    // Create a new node at lesser (beginning of list) then fill in
                    lesser = new node;
                    lesser -> data = cursor -> data;
                    lesser -> next = nullptr;
                    lesserTail = lesser;
               }else{
                    // Create a new node a the tail end of the linked list
                    lesserTail -> next = new node;
                    lesserTail = lesserTail -> next;
                    lesserTail -> data = cursor -> data;
                    lesserTail -> next = nullptr;
               }
          }
          else if(cursor -> data > split_value){
               if(greater == nullptr){   // if greater is empty
                    // Create a new node at greater (beginning of list) then fill in
                    greater = new node;
                    greater -> data = cursor -> data;
                    greater -> next = nullptr;
                    greaterTail = greater;
               }else{
                    // Create a new node a the tail end of the linked list
                    greaterTail -> next = new node;
                    greaterTail = greaterTail -> next;
                    greaterTail -> data = cursor -> data;
                    greaterTail -> next = nullptr;
               }
          }
          cursor = cursor -> next;
     }
};

/**
 * @brief builds a linked list of 2000 random integers, all in the range 1 - 500
 * 
 * @param head - a pointer to the beginning of a linked list
 */
void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = std::rand() % 500 + 1;

     cursor = head;
     for(int i = 0; i < 2000; ++i){
		cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = std::rand() % 500 + 1;
     }
     cursor -> next = NULL;
}

/**
 * @brief outputs the contents of a linked list to the screen
 * 
 * @param head - a pointer to the beginning of a linked list
 */
void show_list(const node* head){
     // This pointer cannot be used to change the data in the nodes that it points to
     const node* cursor = head;

     while(cursor !=  NULL){
		std::cout << cursor -> data << "  ";
		cursor = cursor -> next;
	}
	std::cout << std::endl;
}

/**
 * @brief returns the number of nodes in a linked list
 * 
 * @param head - a pointer to the beginning of a linked list
 * @return int - the number of nodes in the list
 */
int size(const node* head){
     // This pointer cannot be used to change the dat ain the nodes that it points to
	const node* cursor = head;
	int count = 0;

	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}

	return count;
}
