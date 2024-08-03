#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../header_lab6.h"
#include "catch.hpp"

using namespace std;

void disp_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << "\n";
}

bool ll_eq_arr(node* head, int *arr, int size) {
	node* cursor = head;

	disp_arr(arr, size);

	bool passed = true;
	for (int i = 0; i < size; i++) {
		if (cursor == NULL) {
			return false;
		}
		if (cursor->data != arr[i]) {
			passed = false;
		}
		cursor = cursor->next;
	}
	
	return passed;
}

TEST_CASE("Testing...") {
	int arr [10] = {1, 3, 5, 3, 1, 7, 7, 5, 9, 2};
	node* head = new node;
	head->data = arr[0];
	node* cursor = head;
	for (int i = 1; i < 10; i++) {
		cursor->next = new node;
		cursor = cursor->next;
		cursor->data = arr[i];
	}
	cursor->next = NULL;
	cout << "Original list: ";
	show_list(head);

	SECTION("remove_repeats") {
		cout << "Testing remove_repeats...\n";

		int rm_rpts_arr [6] = {1, 3, 5, 7, 9, 2};

		remove_repeats(head);
		cout << "Your remove repeats output: ";
		show_list(head);
		
		cout << "Desired remove repeats output: ";
		bool passed = ll_eq_arr(head, rm_rpts_arr, 6);

		REQUIRE(passed == true);

		cout << "remove_repeats passed.\n";
	}

	SECTION("split_list") {
		cout << "Testing split_list...\n";
		remove_repeats(head);
		cout << "Removed repeats: ";
		show_list(head);
		
		int lesser_arr1 [4] = {1, 3, 5, 2};
		int greater_arr1 [1] = {9};

		int lesser_arr2 [4] = {1, 3, 5, 2};
		int greater_arr2 [2] = {7, 9};
		
		node* lesser1 = NULL;
		node* greater1 = NULL;
		node* lesser2 = NULL;
		node* greater2 = NULL;

		split_list(head, lesser1, greater1, 7);
		split_list(head, lesser2, greater2, 6);

		cout << " ----- Split at 7.\n";

		cout << "Your lesser list: ";
		show_list(lesser1);
		cout << "Desired lesser list: ";
		bool L1_passed = ll_eq_arr(lesser1, lesser_arr1, 4);
		cout << "Your greater list: ";
		show_list(greater1);
		cout << "Desired greater list: ";
		bool G1_passed = ll_eq_arr(greater1, greater_arr1, 1);

		cout << " ----- Split at 6.\n";

		cout << "Your lesser list: ";
		show_list(lesser2);
		cout << "Desired lesser list: ";
		bool L2_passed = ll_eq_arr(lesser2, lesser_arr2, 4);
		cout << "Your greater list: ";
		show_list(greater2);
		cout << "Desired greater list: ";
		bool G2_passed = ll_eq_arr(greater2, greater_arr2, 2);

		REQUIRE(L1_passed == true);
		REQUIRE(G1_passed == true);
		REQUIRE(L2_passed == true);
		REQUIRE(G2_passed == true);

		cout << "split_list passed.\n";
	}
}
