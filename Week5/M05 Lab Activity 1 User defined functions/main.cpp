/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/17/2024
 * Purpose: Computer Specifications(M03 assignment 1) - write user-defined functions
 */

#include <iostream>
using namespace std;

// Function to get the amount of RAM from the user and validate it
int getUserRAM()
{
  int userRAM;
  cout << "Enter the amount of RAM in GB: ";
  cin >> userRAM;

  if (!cin || userRAM < 1)
  {                        // If there's input failure or the user RAM is less than 1 GB
    cin.clear();           // Clear the fail state
    cin.ignore(100, '\n'); // Ready to get user input again
    cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
    return -1;
  }
  return userRAM;
}

// Function to get the task number from the user and validate it
int getTaskNumber()
{
  int taskNumber;
  cout << "Choose the task you want to do on your computer from the following list:\n"
       << "1. Android Studio\n"
       << "2. Visual Studio Code\n"
       << "3. Gaming\n"
       << "4. Web Browsing with Chrome\n"
       << "5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)\n"
       << "6. Zoom\n"
       << "7. Email\n"
       << "8. Create and edit documents\n"
       << "9. Everything listed above\n";
  cin >> taskNumber;

  if (!cin || taskNumber < 1 || taskNumber > 9)
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
    return -1;
  }
  return taskNumber;
}

// Function to check if the user's RAM is sufficient for a selected task
bool isRAMSufficient(int userRAM, int taskNumber)
{
  switch (taskNumber)
  {
  case 1:
    return userRAM >= 12;
  case 2:
  case 4:
  case 6:
    return userRAM >= 8;
  case 3:
    return userRAM >= 16;
  case 5:
    return userRAM >= 20;
  case 7:
  case 8:
    return userRAM >= 6;
  case 9:
    return userRAM >= 32;
  default:
    return false;
  }
}

int main()
{

  // Call the user-defined function, userRAM, to get the user's RAM
  // Store the return value to the variable userRAM
  int userRAM = getUserRAM();
  if (userRAM == -1)
    return -1;

  // Call the user-defined function, taskNumber, to get the task number
  // Store the return value to the variable taskNumber
  int taskNumber = getTaskNumber();
  if (taskNumber == -1)
    return -1;

  // Call the function, isRAMSufficient with the user's RAM and the task number as arguments
  // Store the return value to the variable isSufficient
  bool isSufficient = isRAMSufficient(userRAM, taskNumber);

  if (isSufficient) // Use the return value of the isRAMSufficient function in the expression of the conditional statement
  {
    cout << "Congratulations! You have sufficient RAM for your task." << endl;
  }
  else
  {
    cout << "Sorry, the RAM you have is not sufficient." << endl;
  }

  return 0;
}
