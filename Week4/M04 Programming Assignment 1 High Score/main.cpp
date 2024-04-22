/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/12/2024
 * Purpose: High Score
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  ifstream inFile;

  // Initialize the variables to read data from the file and use
  string username;
  int score;

  // Initialize the variables to keep track of
  int goldScore = 0, silverScore = 0, bronzeScore = 0;
  string goldUser = "", silverUser = "", bronzeUser = "";

  inFile.open("scores.txt");

  // table heading
  cout << "IvyGames Tournament Results:" << endl;
  cout << setw(35) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cout << "| " << setw(15) << left << "Username"
       << "| " << setw(15) << "Score"
       << "|" << endl;

  // while loop
  while (inFile >> username >> score) // while there's data to read
  {
    if (score > goldScore) // if the current score data is greater than the current goldScore
    {
      bronzeScore = silverScore; // make bronzeScore hold the current silverScore
      bronzeUser = silverUser;
      silverScore = goldScore; // make silverScore hold the current goldScore
      silverUser = goldUser;
      goldScore = score; // make goldScore hold the current score data
      goldUser = username;
    }
    else if (score > silverScore)
    {
      bronzeScore = silverScore;
      bronzeUser = silverUser;
      silverScore = score;
      silverUser = username;
    }
    else if (score > bronzeScore)
    {
      bronzeScore = score;
      bronzeUser = username;
    }

    cout << setw(35) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << username
         << "| " << setw(15) << score
         << "|" << endl;
  }
  cout << setw(35) << setfill('-') << "-" << endl;
  cout << setfill(' ');

  cout << endl
       << "The gold medal winner is " << goldUser << " with " << goldScore << " points.\n";
  cout << "The silver medal winner is " << silverUser << " with " << silverScore << " points.\n";
  cout << "The bronze medal winner is " << bronzeUser << " with " << bronzeScore << " points.\n";
  cout << "Congratulations to the winners! See you at the next tournament." << endl;

  inFile.close();
}