#include "order.h"
#include "Product.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    list<Order> orders;
    Order currentOrder;
    bool running = true;

    while(running){
        cout << "Menu:" << endl;
        cout << "1. Add a product to the current order" << endl;
        cout << "2. Add the current order to the list" << endl;
        cout << "3. View list of all orders" << endl;
        cout << "4. Remove last order that has been completed" << endl;
        cout << "5. Exit the program" << endl << endl;
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;
        cin.ignore();    // Ignores the newline character.

        int c1Choice;
        switch(choice){
            case 1: // Add a product to the current order
                cout << "Adding a new product to the current order..." << endl;

                cout << "What product would you like to add?" << endl;
                cout << "1. Converter" << endl;
                cout << "2. Frame" << endl;
                cout << "3. Turbo Charger" << endl << endl;
                cout << "Enter Choice (1-3): ";
                cin >> c1Choice;
                cin.ignore();

                Product* productToAdd;
                switch(c1Choice){
                    case 1:
                        productToAdd = new Converter();
                        break;
                    case 2:
                        productToAdd = new Frame();
                        break;
                    case 3:
                        productToAdd = new turboCharger();
                        break;
                    default:
                        cout << "Invalid option, pick again." << endl;
                }
                if(productToAdd != nullptr){
                    currentOrder.addItem(productToAdd);
                }
                break;
            case 2: // Add the current order to the list
                cout << "Adding current order to the list..." << endl;

                orders.push_back(currentOrder);

                cout << "Order successfully added to list!" << endl;
                currentOrder = Order(); // Sets currentOrder to a new order in prep for next item
                break;
            case 3: // View a list of all orders
                for(list<Order>::iterator it = orders.begin(); it != orders.end(); it++){
                    (*it).output(cout);
                }
                break;
            case 4: // Removes an order that has been completed
                cout << "Removing last order completed..." << endl;
                list<Order>::iterator itr = orders.begin();

                while(itr != orders.end()){ // This assumes we want to remove the most recent order
                    if(itr -> get_totalCost() > 0.0){
                        orders.erase(itr);
                        cout << "Order removed successfully!";
                        break;
                    }else{
                        itr++;
                    }
                }
                cout << "No completed orders found to remove."
                orders.erase(itr); // Removes the item
                break;
            case 5:
                running = false;
                // Impliment code to save to file
                cout << "Exiting Program..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}