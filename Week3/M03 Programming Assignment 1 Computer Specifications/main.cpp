/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/10/2024
 * Purpose: Computer Specifications - determine if a user has enough RAM to do certain tasks
 */

/*
Prompt the user for the amount of RAM their computer has in GB. Then you will display the list of tasks below that the user might do with the computer. Based on the task chosen, inform the user if the amount of RAM they have is sufficient.
You should have at least four lines of documentation.
*/

// strings for the menu
/*
"Choose the task you want to do on your computer from the following list:"
"1. Android Studio"
"2. Visual Studio Code"
"3. Gaming"
"4. Web Browsing with Chrome"
"5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)"
"6. Zoom"
"7. Email"
"8. Create and edit documents"
"9. Everything listed above"
*/

/*
Input Validation
The user will be entering a number for the RAM amount.  You will need to make sure that the user properly enters a number into the console by checking if they have input failure, and you will need to make sure the number is greater than 0. If the input fails either condition, the program should display an error message and exit early.

The way a user chooses a task is through a numbered menu.  You will need to make sure the user properly enters a number into the console by checking if they have input failure, and you will need to make sure the number entered is within the range of the menu options.  If the input fails either condition, then the program should display an error message and exit early.
*/

/*
| Task                                         | Minimum RAM Needed |
|----------------------------------------------|--------------------|
| 1. Android Studio                            | 12 GB              |
| 2. Visual Studio Code                        | 8 GB               |
| 3. Gaming                                    | 16 GB              |
| 4. Web Browsing with Chrome                  | 8 GB               |
| 5. Multiple Programming Tasks                | 20 GB              |
    (both Android and VS Code)
| 6. Zoom                                      | 8 GB               |
| 7. Email                                     | 6 GB               |
| 8. Create and edit documents                 | 6 GB               |
| 9. Everything listed above                   | 32 GB              |

7, 8: 6 GB
2, 4, 6: 8 GB
1: 12 GB
3: 16 GB
5: 20 GB
9: 32 GB

sufficiency check algorithm
if userRAM < 6
  any task is insufficient
else if userRAM < 8
  if task 1, 2, 3, 4, 5, 6, 9
    insufficient
  else
    sufficient
else if userRAM < 12
  if task 1, 3, 5, 9
    insufficient
  else
    sufficient
else if userRAM < 16
  if task 1, 5, 9
    insufficient
  else
    sufficient
else if userRAM < 20
  if task 5, 9
    insufficient
  else
    sufficient
else if userRAM < 32
  if task 9
    insufficient
  else
    sufficient
else
  any task is sufficient
*/

/*
program algorithm

prompt for user input for a RAM amount
store the user input (int)
input validation
  if not a number? err msg -> exit
  else if a number but less than 1? err msg -> exit
  else (a number and greater than or equal to 1)
    prompt for user input for a task (show the list of possible tasks)
    store the user input(int)
      if not a number? err msg -> exit
      else if a number but less than 1? or greater than 9? err msg -> exit
      else (a number and greater than or equal to 1)
        sufficiency check algorithm
*/

#include <iostream>
using namespace std;

int main()
{
  int userRAM;
  int taskNumber;

  cout << "Enter the amount of RAM in GB: ";
  cin >> userRAM;

  if (!cin || userRAM < 1)
  {                        // If there's input failure or the user RAM is less than 1 GB
    cin.clear();           // Clear the fail state
    cin.ignore(100, '\n'); // Ready to get user input again
    cout << "You have entered an invalid value. The program will unable to continue. Exiting." << endl;
    return -1;
  }

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
  { // taskNumber shoule be between 1 and 9.
    cin.clear();
    cin.ignore(100, '\n');
    cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
    return -1;
  }

  bool isSufficient = false; // flag to check if sufficient or not
  switch (taskNumber)
  { // I chose switch structure because I don't need the evaluation of a logical expression
  case 1:
    isSufficient = userRAM >= 12;
    break;
  case 2:
  case 4:
  case 6:
    isSufficient = userRAM >= 8;
    break;
  case 3:
    isSufficient = userRAM >= 16;
    break;
  case 5:
    isSufficient = userRAM >= 20;
    break;
  case 7:
  case 8:
    isSufficient = userRAM >= 6;
    break;
  case 9:
    isSufficient = userRAM >= 32;
    break;
  }

  if (isSufficient)
  {
    cout << "Congratulations! You have sufficient RAM for your task." << endl;
  }
  else
  {
    cout << "Sorry, the RAM you have is not sufficient." << endl;
  }

  return 0;
}