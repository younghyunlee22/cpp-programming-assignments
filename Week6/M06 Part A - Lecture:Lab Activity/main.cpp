/* Write a C++ program that asks the user for two initial values,
and then computes and stores the first 20 Fibonnacci numbers of that sequence
in an array named inputArray (20 values total--including the two input by the user).

// Then, copy those values into another array, named outputArray, in reverse order
(Hint: if you use a for loop with i counting from 0 to 19, then (19-i) will count from 19 to 0).
Once you've done this, read the values from outputArray and display them on the screen.

// Include an inline comment stating what the time efficiency of each part of the program is--
you should state in big-O notation (as an example, something like O(n^2) )
what the time required to compute and store the values is,
and then also what the time required to copy the values is.
/*/

#include <iostream>

using namespace std;

int main()
{

  // Declare input and output arrays with size of 20
  int inputArray[20];  // O(1)
  int outputArray[20]; // O(1)

  // Declare user input variables and initialize them
  int inputNum1 = 0; // O(1)
  int inputNum2 = 0; // O(1)

  // Ask the user for two initial values and store them in the input array
  cout << "Enter the first number: " << endl; // O(1)
  cin >> inputNum1;                           // O(1)
  inputArray[0] = inputNum1;                  // O(1)

  cout << "Enter the second number: " << endl; // O(1)
  cin >> inputNum2;                            // O(1)
  inputArray[1] = inputNum2;                   // O(1)

  // Compute the next 18 fibonacci sequence
  for (int i = 2; i < 20; i++)
  {
    inputArray[i] = inputArray[i - 1] + inputArray[i - 2]; // O(n)
  }

  // Copy all the values into outputArray
  for (int i = 0; i < 20; i++)
  {
    outputArray[i] = inputArray[19 - i]; // O(n)
  }

  // Output the values of outputArray
  for (int i = 0; i < 20; i++)
  {
    cout << outputArray[i] << endl; // O(n)
  }

  return 0;
}