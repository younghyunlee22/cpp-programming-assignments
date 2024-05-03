// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // a Cstring is an array of type char. Here is an example:

  char message[30] = "This is how a CSting works.";
  cout << message << endl;
  char monthlist[15][12] = {"January", "February", "March", "April", "May",
                            "June", "July", "August", "September", "October", "November", "December"};

  // Month names should be no more than 14 letters, and we need to store 12 of them.
  // monthList is an array of type char[].
  // Since C++ can cout an entire Cstring as above, we just need to count from 0 to 11 in order to print these all out:

  for (int i = 0; i < 12; i++)
  {
    cout << left << setw(15) << monthlist[i] << endl;
  }

  /*I'd like you to complete this program using the above code as a start. You
  need to create an array of type int which
  should hold the number of days in each of the months of monthlist[][]. This is
  what's meant by a 'parallel array'--both
  elements of index 3, for example, should contain data related to the month of
  April (it's name, as above, and your array
  should store the number of days in April). Your completed program should print
  out the number of days
  in each month along with the name of each month. Here is an example of the
  output of your program--make sure that you use
  an additional array for the number of days in each month, as doing so is part
  of the specification of the assignment:
  This is how a CSting works.
  January 31
  February 28
  March 31
  April 30
  May 31
  June 30
  July 31
  August 31
  September 30
  October 31
  November 30
  December 31
  I included some manipulators in my cout statement (and included the header needed)
  to save you some effort in making the output
  look pretty. More than anything, I wanted to help everyone get a better handle on
  how Cstrings work, and how you can work
  with an array of them.
  */

  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < 12; i++)
  {
    cout << left << setw(15) << monthlist[i] << daysInMonth[i] << endl;
  }

  return 0;
}
