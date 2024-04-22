/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/12/2024
 * Purpose: Binary to decimal conversion
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int num, decimalValue = 0, power = 0;

  cout << "Welcome to the binary number converter 2.0." << endl;
  cout << "You will enter a binary number 1 digit at a time starting at the right and the program will convert the number to decimal." << endl;

  string prompt = "Enter the 1st binary digit (Enter -1 to complete the conversion): ";
  cout << prompt;

  while (cin >> num && num != -1)
  { // Valid input num && num is not the sentinel value
    if (!cin)
    { // Check if input failed
      cout << "You entered something that is not a number." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << prompt; // Show the prompt again
      continue;
    }

    if (num != 0 && num != 1)
    { // Validation for binary digits
      cout << "A binary digit can only be a 1 or 0." << endl;
      cout << prompt;
      continue;
    }

    decimalValue += num * pow(2, power++); // If valid num, update power and decimalValue

    // Update the prompt for the next input
    switch (power)
    {
    case 1:
      prompt = "Enter the 2nd binary digit (Enter -1 to complete the conversion): ";
      break;
    case 2:
      prompt = "Enter the 3rd binary digit (Enter -1 to complete the conversion): ";
      break;
    case 3:
      prompt = "Enter the 4th binary digit (Enter -1 to complete the conversion): ";
      break;
    case 4:
      prompt = "Enter the 5th binary digit (Enter -1 to complete the conversion): ";
      break;
    case 5:
      prompt = "Enter the 6th binary digit (Enter -1 to complete the conversion): ";
      break;
    case 6:
      prompt = "Enter the 7th binary digit (Enter -1 to complete the conversion): ";
      break;
    case 7:
      prompt = "Enter the 8th binary digit (Enter -1 to complete the conversion): ";
      break;
    case 8:
      prompt = "Enter the 9th binary digit (Enter -1 to complete the conversion): ";
      break;
    default:
      if (power > 8)
      {
        prompt = "Enter the " + to_string(power + 1) + "th binary digit (Enter -1 to complete the conversion): ";
      }
      break;
    }
    cout << prompt;
  }

  cout << "Your number in decimal is " << decimalValue << endl;

  return 0;
}
