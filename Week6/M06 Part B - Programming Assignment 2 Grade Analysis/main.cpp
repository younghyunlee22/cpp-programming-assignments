/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 5/4/2024
 * Purpose: Grade Analysis
 */

/*
You are creating a program that reads grade information from a file named grades.txt.
There are at most 20 student records in a file; each student will have 5 test scores.
You will create a 2d array of doubles to hold the test score information.
It will have a max size of 20 rows and 5 columns.
After reading the data into the array, you will need to calculate statistics for each column and display them to the user.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // Open the file
  ifstream infile("grades.txt");

  // Create a 2D array to store the test scores
  double testScores[20][5];
  // Initialize the test scores to 0.0
  double testScore1, testScore2, testScore3, testScore4, testScore5;

  int numStudents = 0;

  // Read the test scores from the file and store them in the array
  // Stop reading when reaching the end of the file or after reading 20 students
  while (infile >> testScore1 >> testScore2 >> testScore3 >> testScore4 >> testScore5 && numStudents < 20)
  {
    testScores[numStudents][0] = testScore1;
    testScores[numStudents][1] = testScore2;
    testScores[numStudents][2] = testScore3;
    testScores[numStudents][3] = testScore4;
    testScores[numStudents][4] = testScore5;
    numStudents++;
  }

  // Close the file
  infile.close();

  // print testScores 2D array
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << testScores[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}