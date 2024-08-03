/*************************************************************************
	A little class that holds a dynamic array of numbers.
	I have provided a start here, you need to write the function
		implementations. DO NOT remove the byte_count lines that are
		already in a few of the functions.


    John Dolan			Spring 2013		CS2401 Lab Assignment 4
	Patricia Lindner	Fall 2021
*************************************************************************/

#include <iostream>

size_t byte_count = 0;
class Numbers{
    public:
		Numbers();
		~Numbers();
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);
		unsigned long* reveal_address()const;
		void operator = (const Numbers &other);

    private: 
	unsigned long *data;
	std::size_t used;
	std::size_t capacity;

};

Numbers::Numbers(){
	byte_count += 5 * sizeof(unsigned long);
	capacity = 5;
	data = new unsigned long[capacity];
	used = 0;
}

Numbers::~Numbers(){
	delete []data;
	byte_count = byte_count - (capacity * sizeof(unsigned long));
}

void Numbers::add(unsigned long item){
	if(used == capacity){
		resize();
	}
	data[used] = item;
	used++;
}

void Numbers::resize(){
	unsigned long *tmp;
	tmp = new unsigned long[capacity + 5];
	for(size_t i = 0; i < capacity; i++){
		tmp[i] = data[i];
	}
	capacity += 5;
	delete []data;
	data = tmp;

	byte_count += 5 * sizeof(unsigned long);
}

void Numbers::remove_last(){
	if(used > 0){
		used--;
	}
}

void Numbers::display(std::ostream& outs){
	for(size_t i = 0; i < used; i++){
		std::cout << data[i] << " ";
	}
}

void Numbers::operator = (const Numbers &other){
	if(this == &other){ // Checks for self assignment
		return;
	}

	delete []data;

	used = other.used;
	capacity = other.capacity;

	data = new unsigned long[capacity];
	std::copy(other.data, other.data + other.used, data);

}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}