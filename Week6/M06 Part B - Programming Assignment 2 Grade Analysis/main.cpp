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
#include <iomanip>

using namespace std;

void getHighScoreIndex(double scores[][5], int numRows, int colToAnalyze, int &highScoreIndex);
void getLowScoreIndex(double scores[][5], int numRows, int colToAnalyze, int &lowScoreIndex);
void getAverageScore(double scores[][5], int numRows, int colToAnalyze, double &average);
void getMedianScore(double scores[][5], int numRows, int colToAnalyze, double &median);
void selectionSort(double scoreColumn[], int numItems);

/*
getHighScoreIndex function
This function will take the array of scores along with the number of rows and the column that we want to analyze and will find the index for the highest score in the column.
This will be put in a reference parameter to be returned.
*/

void getHighScoreIndex(double scores[][5], int numRows, int colToAnalyze, int &highScoreIndex)
{

  // Initialize the highest score index to the first student
  int highestScoreIndex = 0;

  // Loop through each student's score in the specified column
  for (int i = 1; i < numRows; i++)
  {
    // Compare the current score with the score at the current highest index
    if (scores[i][colToAnalyze] > scores[highestScoreIndex][colToAnalyze])
    {
      // Update the highest score index if the current score is higher
      // this is to update the local variable
      highestScoreIndex = i;
    }
  }

  highScoreIndex = highestScoreIndex; // This line updates the reference parameter
}

void getLowScoreIndex(double scores[][5], int numRows, int colToAnalyze, int &lowScoreIndex)
{

  int lowestScoreIndex = 0;

  for (int i = 1; i < numRows; i++)
  {
    if (scores[i][colToAnalyze] < scores[lowestScoreIndex][colToAnalyze])
    {
      lowestScoreIndex = i;
    }
  }
  lowScoreIndex = lowestScoreIndex;
}

void getAverageScore(double scores[][5], int numRows, int colToAnalyze, double &average)
{

  double sum = 0.0;

  for (int i = 0; i < numRows; i++)
  {
    // Sum all scores in the specified column
    sum += scores[i][colToAnalyze];
  }

  // Calculate the average using the total number of students
  average = sum / numRows;
}

/*
getMedianScore function
This function takes the array of scores and finds the median for a single column.
The median is passed back using a reference parameter.
To find the median, you will need to copy the column to a 1-dimensional array of doubles.
Then you will need to sort that array and find the middle item.
If there are an even number of items in the array,
then you will need to average the two middle items to find the median.
*/

void getMedianScore(double scores[][5], int numRows, int colToAnalyze, double &median)
{

  // Create a 1D array to store the column of scores
  double columnScores[20];

  // Copy the column of scores to the 1D array
  for (int i = 0; i < numRows; i++)
  {
    columnScores[i] = scores[i][colToAnalyze];
  }

  // Sort the 1D array of scores
  selectionSort(columnScores, numRows);

  // Calculate the median
  if (numRows % 2 == 0)
  {
    // If there are an even number of items, average the two middle items
    median = (columnScores[numRows / 2 - 1] + columnScores[numRows / 2]) / 2;
  }
  else
  {
    // If there are an odd number of items, the median is the middle item
    median = columnScores[numRows / 2];
  }
}

/*This function takes a 1d array of doubles and sorts it using selection sort.*/
void selectionSort(double scoreColumn[], int numItems)
{

  int index;
  int smallestIndex;
  int location;
  double temp;

  for (index = 0; index < numItems - 1; index++)
  {
    // Initialize smallestIndex at the start of the unsorted section
    smallestIndex = index;

    // Step a: Find the index of the smallest element in the unsorted section
    for (location = index + 1; location < numItems; location++)
    {
      if (scoreColumn[location] < scoreColumn[smallestIndex])
      {
        smallestIndex = location;
      }
    }

    // Step b: Swap the found smallest element with the first element in the unsorted section
    temp = scoreColumn[smallestIndex];
    scoreColumn[smallestIndex] = scoreColumn[index];
    scoreColumn[index] = temp;
  }
}

int main()
{
  // Open the file
  ifstream infile("grades.txt");

  // Create a 2D array to store the test scores
  double scores[20][5];

  int numStudents = 0;

  // Read the test scores from the file and store them in the scores array
  // Stop reading when reaching the end of the file or after reading 20 students
  while (!infile.eof() && numStudents < 20)
  {
    for (int j = 0; j < 5; j++)
    {
      infile >> scores[numStudents][j];
    }
    if (infile)
      numStudents++; // Only increment if read was successful
  }

  // Close the file
  infile.close();

  // print scores 2D array
  // for (int i = 0; i < 20; i++)
  // {
  //   for (int j = 0; j < 5; j++)
  //   {
  //     cout << scores[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // Calculate statistics for each column
  double highScore, lowScore, averageScore, medianScore;

  cout << "Grade Statistics:" << endl;

  for (int i = 0; i < 5; i++)
  {
    int highScoreIndex, lowScoreIndex;

    getHighScoreIndex(scores, numStudents, i, highScoreIndex);
    getLowScoreIndex(scores, numStudents, i, lowScoreIndex);
    getAverageScore(scores, numStudents, i, averageScore);
    getMedianScore(scores, numStudents, i, medianScore);

    highScore = scores[highScoreIndex][i];
    lowScore = scores[lowScoreIndex][i];

    cout << fixed << setprecision(2);
    cout << "Test " << i + 1 << ":" << endl;
    cout << "Highest Score: " << highScore << endl;
    cout << "Lowest Score: " << lowScore << endl;
    cout << "Average Score: " << averageScore << endl;
    cout << "Median Score: " << medianScore << endl;
    cout << endl;
  }

  return 0;
}