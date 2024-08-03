#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dnode{
    public:
        Dnode(T d = T(), Dnode* p = nullptr, Dnode* n = nullptr){
            data_field = d;
            prev_field = p;
            next_field = n;
        }

        /// ACCESSOR FUNCTIONS ///
        T data()const{return data_field;}
        Dnode* next()const{return next_field;}
        Dnode* prev()const{return prev_field;}

        /// MUTATORS ///
        void set_data(T d){data_field = d;}
        void set_next(Dnode* n){next_field = n;}
        void set_prev(Dnode* p){prev_field = p;}

    private:
        T data_field;
        Dnode* next_field;
        Dnode* prev_field;
};

#endif