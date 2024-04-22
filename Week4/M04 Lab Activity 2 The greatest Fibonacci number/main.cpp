/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 4/17/2024
 * Purpose: The greatest Fibonacci number
 */

/*
Modify the program listing for the Fibonacci sequence in chapter 5 of "C++ Programming: Program Design Including Data Structures"
so that it accepts the first two values from the user,
but instead of the nth Fibonacci number, requests the highest value to be reported.
That is, if the user asks for the highest value to be 15,000,
then the program should output the greatest Fibonacci number less than or equal to 15,000.
*/

#include <iostream>

using namespace std;

int main()
{
  // Declare variables
  int previous1;
  int previous2;
  int current;
  int highestValue;

  // User input for the first two Fibonacci numbers
  cout << "Enter the first two Fibonacci numbers: ";
  cin >> previous1 >> previous2;
  cout << endl;

  // Echo output
  cout << "The first two Fibonacci numbers are "
       << previous1 << " and " << previous2
       << endl;

  // User input for the highest value
  cout << "Enter the highest value of the desired Fibonacci number: ";
  cin >> highestValue;
  cout << endl;

  // While the sum of previous1 and previous2 is less than or equal to the highest value that user input
  while ((previous1 + previous2) <= highestValue)
  {
    current = previous1 + previous2; // Get a fibonacci number
    previous1 = previous2;
    previous2 = current;
  }

  // Output the highest Fibonacci number
  cout << "The greatest Fibonacci number less than or equal to "
       << highestValue << " is " << current
       << endl;

  return 0;
}
