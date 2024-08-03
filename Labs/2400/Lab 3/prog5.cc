#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
   double ctof;  // equivalent Celsius temperature
   double ftoc;  // equivalent Fahrenheit temperature.
 
   double fah = 56.0;  //declare and initialize at the same time - page 48
   double cel = 20.0;

   ctof = (1.8 * cel) + 32;
   ftoc = (fah - 32) * 5/9;

   cout << fixed << setprecision(1);
   cout << cel << " degrees Celsius in Fahrenheit is " << ctof << endl;
   cout << fah << " degrees Fahrenheit in Celsius is " << ftoc << endl;

   return (EXIT_SUCCESS);
}
