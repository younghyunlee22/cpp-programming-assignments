/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 3/29/2024
 * Purpose: Calculate total bill
 */

// M02LabActivity2.cpp
/*
The program below computes the total bill for a purchase made using a 'percent off' coupon, with a sales
tax of 7% applied to it. Correct any errors to get the program to run correctly, and then modify the program to
read values from the user for the total amount of the purchase and the coupon discount rate.
Bonus: modify the program to output to the screen as well as to a file.

The correct output value for the supplied values is $59.92. (total 80)
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream outfile("bill.txt");

  float total, couponrate;
  const float taxrate = 0.07;

  cout << "Enter the total price: ";
  cin >> total;

  cout << "Enter the coupon rate: ";
  cin >> couponrate;

  cout << "The total amount due is $" << (1 - couponrate) * total * (1 + taxrate) << "." << endl;

  outfile << "The total amount due is $" << (1 - couponrate) * total * (1 + taxrate) << "." << endl;

  outfile.close();

  return 0;
}