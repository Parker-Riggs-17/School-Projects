#include "dnode.h"
#include "node_iterator.h"
#ifndef DLIST_H
#define DLIST_H

template <class T>
class dlist{
    public:
        typedef NODE_IT<T> iterator;

        dlist(){head = tail = nullptr;}

        /// BIG 3 ///
        ~dlist();
        dlist(const dlist& other);
        dlist& operator = (const dlist& other);

        /// OTHER FUNCTIONS ///
        int size(); // Returns size of list in ints
        void show();   // Display the list
        void reverse_show()const;   // Displays the list in reverse
        void front_insert(int num); // Insert an int at the front of the list
        void rear_insert(int num);  // Insert an int at the end of the list
        void front_remove();    // Remove the first element
        void rear_remove(); // Remove the last element

        /// OTHER FUNCTIONS PT 2 ///
        NODE_IT<T> begin();    // Returns an iterator pointing at the beginning of the list.
        NODE_IT<T> end();  // Returns an iterator pointing to the nullptr after last element.
        NODE_IT<T> r_begin();  // Returns an iterator pointing to the end of the list.
        NODE_IT<T> r_end();    // Returns an iterator pointing to the nullptr after last element.
        void insert_before(NODE_IT<T> tmpIt, int num); // Inserts an int before the specified iterator.
        void insert_after(NODE_IT<T> tmpIt, int num);     // Inserts an int after the specified iterator.
        void remove(NODE_IT<T> tmpIt);  // Removes an iterator.

    private:
        Dnode<T>* head;
        Dnode<T>* tail;
};

#include "dlist.template"

#endif