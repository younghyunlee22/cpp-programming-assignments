/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 3/22/2024
 * Purpose: Binary to decimal conversion
 */

#include <iostream>

using namespace std;

int main()
{
  int b1, b2, b3, b4, b5;
  // prompts:
  cout << "Enter the 1st binary digit: " << endl;
  cin >> b1;
  cout << "Enter the 2nd binary digit: " << endl;
  cin >> b2;
  cout << "Enter the 3rd binary digit: " << endl;
  cin >> b3;
  cout << "Enter the 4th binary digit: " << endl;
  cin >> b4;
  cout << "Enter the 5th binary digit: " << endl;
  cin >> b5;

  int decimal = b1 * 16 + b2 * 8 + b3 * 4 + b4 * 2 + b5 * 1;
  // Final output:
  //    print all of the entered digits  " converted to decimal is " print the calculated number
  cout << b1 << b2 << b3 << b4 << b5 << " converted to decimal is " << decimal << endl;

  return 0;
}
