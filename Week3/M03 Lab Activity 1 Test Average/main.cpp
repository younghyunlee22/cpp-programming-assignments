
/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 4/3/2024
 * Purpose: Test average
 */

/*For this activity, you are to create a C++ program which prompts the user to enter five test scores, then computes the test average and overall grade using the following scale:
A: at least 90%
B: at least 80% but less than 90%
C: at least 70% but less than 80%
D: at least 60% but less than 70%
F: below 60%

Your program should accept the inputted scores, compute the average of those scores, and output both the test average and the final letter grade. For this assignment, you are to use if-else statements for assigning the overall grade, and not the switch statement. Be sure to include appropriate comments in your source file, and submit your .cpp file and a screenshot of your output for grading.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int score1, score2, score3, score4, score5;
  double average;

  // input prompt
  cout << "Enter five test scores" << endl;

  // store inputs
  cin >> score1 >> score2 >> score3 >> score4 >> score5;

  // compute the average of those five scores
  average = (score1 + score2 + score3 + score4 + score5) / 5;

  // output the average
  cout << fixed << setprecision(2); // set precision to 2 decimal places
  cout << "The average is " << average << "%" << endl;

  // output the grade depending on the average

  if (average >= 90)
  {
    cout << "The overall grade is A.";
  }
  else if (average >= 80)
  {
    cout << "The overall grade is B.";
  }
  else if (average >= 70)
  {
    cout << "The overall grade is C.";
  }
  else if (average >= 60)
  {
    cout << "The overall grade is D.";
  }
  else
  {
    cout << "The overall grade is F.";
  }

  return 0;
}