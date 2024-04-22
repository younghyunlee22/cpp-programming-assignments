/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 4/17/2024
 * Purpose: Sum of the remainders
 */

/*
For this activity, I'd like you to write a C++ program that asks the user to input an integer to divide by,
and an integer that is an upper limit,
and then computes and displays the sum of the remainders of the numbers from 1 to the limit.
You may use a for, do, or while loop to accomplish this.
*/

#include <iostream>

using namespace std;

int main()
{
  // Input variables
  int divisor, upperLimit;
  // Other variables
  int sum = 0;

  // Prompts, store inputs
  cout << "Enter an integer to divide by: " << endl;
  cin >> divisor;

  cout << "Enter an integer that is an upper limit: " << endl;
  cin >> upperLimit;

  // Loop starts
  // i represents the dividend - 1 through the upper limit
  int i;

  for (i = 1; i <= upperLimit; i++)
  {

    // calculate the remainder and add it to the sum
    sum += i % divisor;
  }

  // Output for the user
  cout << "The sum of the remainders is: " << sum << endl;

  return 0;
}
