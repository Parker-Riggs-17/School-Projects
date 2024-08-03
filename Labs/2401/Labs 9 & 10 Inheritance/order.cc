// Parkers Code //
#include "order.h"

using namespace std;

// Getters

void Order::get_userName(){
    return userName;
}

void Order::get_totalCost(){
    return totalCost;
}

// Setters

void Order::set_userName(string newUserName){
    userName = newUserName;
}

void Order::set_TotalCost(double newTotalCost){
    totalCost = newTotalCost;
}

// Other Functions

void Order::addItem(list<Product*> item){
    totalCost += item -> get_price();
    items.push_back(item);
}

void Order::output(ostream& outs)const{
        outs << "Order For: " << userName << endl;
        outs << "Items:" << endl;
        list<Product*>::iterator it;
        for(it = items.begin(); it != items.end(); i++){
            outs << items -> data() << endl;
        }
        outs << "Total Cost: $" << totalCost << endl;
}

    // Andrews Code //
// #include <iomanip>
// #include "order.h"
// using namespace std;
// //getters
//     string Order::get_name()
//     {
//         return userName;
//     }
//     double Order::get_cost()
//     {
//         return totalCost;
//     }
//     list<Product*> Order::get_list()
//     {
//         return item_List;
//     }
// //setters
//     void Order::set_name(std::string name)
//     {
//         userName = name;
//     }
//     void Order::set_cost(double cost)
//     {
//         totalCost += cost;
//     }
// //regular functions
//     void Order::output(std::ostream &outs) const
//     {
//         outs << setw(30) << setfill('-') << "Your Order Summary" << endl;
//         outs << "Customer: " << userName << endl;
//         outs << "Total Cost: " << totalCost << endl;
//     for (std::list<Product*>::iterator it; it != item_List.end(); ++it)
//     {
//         outs << it -> data().output(outs);
//     }
//     }
//     void Order::input(std::istream &ins)
//     {
//         cout << "Hello! Please Enter your Name: " << endl;
//         ins >> userName;
//         int userChoice = 0;
//         while(userChoice != 9)
//         {
//             cout << "Please select from an item below" << endl;
//             cout << "1. Frame \n2. TurboCharger\n3. Catalytic Converter\n4. Wheels/Rims\n";
//             cout << "Enter '9' to quit the program" << endl;
//             ins >> userChoice;
//                 if(userChoice == 9)
//                 {
//                     cout << "Thank you for Visiting!" << endl;
//                     cout << "Program Closing..." << endl;
//                     exit(0);
//                 }
//                 else if(userChoice == 1)
//                 {
//                     Frame f1;
//                     f1.input(cin);
//                     list<Product*>::push_back(f1);
//                 }
//                 else if(userChoice == 2)
//                 {
//                     turboCharger t1;
//                     t1.input(cin);
//                     list<Product*>::push_back(t1);
//                 }
//                 else if(userChoice == 3)
//                 {
//                     Converter c1;
//                     c1.input(cin);
//                     list<Product*>::push_back(c1);
//                 }
//                 else if(userChoice == 4) //No wheel class pushed to main
//                 {
//                     // Wheels w1; 
//                     // w1.input(cin);
//                     // list<Product*>::push_back(w1);
//                 }
//                 else
//                 {
//                     userChoice = 0;
//                 }
//         }
//     }
