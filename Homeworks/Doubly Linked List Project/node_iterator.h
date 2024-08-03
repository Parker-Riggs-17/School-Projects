#include "dnode.h"
#ifndef NODEIT_H
#define NODEIT_H

template <class T>
class NODE_IT{
    public:
        NODE_IT(Dnode<T>* c = nullptr){current = c;}

        /// Pre/Post-Fix & Other Operator Functions ///
        NODE_IT operator ++ ();
        NODE_IT operator ++ (int);
        NODE_IT operator -- ();
        bool operator != (const NODE_IT& other)const;
        T operator * ()const;

        Dnode<T>* get_current()const{
            return current;
        }

    private:
        Dnode<T>* current;
};


#include "node_iterator.template"

#endif