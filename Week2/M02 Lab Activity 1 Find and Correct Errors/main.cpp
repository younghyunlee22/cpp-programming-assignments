/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 3/27/2024
 * Purpose: M02 Lab Activity A
 */

// main.cpp : This is the source file for M02 Lab Activity A. It contains errors, which you
// are to find and correct. Be sure to replace this text with the heading documentation as provided
// for in the assignment in Ivy Learn

#include <iostream>
#include <iomanip> //this header provides the setprecision() manipulator for formatting output
using namespace std;

int main()
{
  // This program computes the volume of a cylinder when the lengths of the radius and the height
  // are input by the user.

  double radius, height, volume;

  cout << "Enter the length of the radius: ";
  cin >> radius;
  cout << "Enter the length of the height: ";
  cin >> height;

  volume = 3.14 * radius * radius * height;
  // This formula is the correct formula for the volume of a cylinder. Instead of squaring the radius,
  // it's simply multiplied by itself here. You can use pow() for computing exponent, but need to #include <cmath> to do so.

  cout << fixed << showpoint << setprecision(2);
  cout << "The volume of the cylinder to two decimal places is: " << volume << endl;

  return 0;
}