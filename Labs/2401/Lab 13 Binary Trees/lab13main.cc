/*
	CS 2401 Binary Tree Lab

	This file contains a struct definition for a binary tree node that stores strings.
	The inorder traversal, add, and size functions are already done for you.

	The add function inserts nodes in such a way that it creates a binary search tree.
	This means that:
		* All nodes to the left of the current node are less than or equal to the current node
		* All nodes to the right of the current node are greater than the current node

	You need to fill in the main and functions required in the lab document.
*/

#include<iostream>
#include<fstream>
#include<string>
#include "btreelab.h"

using namespace std;

int main(){
    Bnode* root = NULL;
	ifstream ins;
	string name;
	string targ;

	// Opens names.txt and check if file fails to open. //
	ins.open("names.txt");	
	if(ins.fail()){
		cout << "Names.txt failed to open." << endl;
		exit(0);
	}

	// While loop to load names into tree //
	while(!ins.eof()){
		getline(ins >> ws, name);
		add(root, name);
	}

	inorder(root);

	cout << "Input a name to search for: ";
	cin >> targ;

	cout << "Your name appears " search_greater(root, targ) << " times." << endl;
	return 0;
}