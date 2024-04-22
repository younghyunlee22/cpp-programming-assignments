/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/16/2024
 * Purpose: Ghost Hunting
 */

/*
analyze the results of some ghost hunts.
program starts
loop starts
- read data from ghosts.txt
  (three events in a file, 1 per line.
  event code, the number of times that event occurred)
  data to read: event code - char eventCode, number of times - int eventCount

  - calculate an haunting score for each event and the sum of all haunting scores
    - int hauntingScore = int eventCount * int points
    - int totalPoints += hauntingScore
loop ends

  - If the totalScore is greater than 15,
      - then "This place is haunted."
    - Otherwise,
      - "This place is probably not haunted."

- "Great job! On to the next one."
program ends

Ghost Hunting Events
Event	Event Code	Points
EVP (Electronic Voice Phenomena)	E	3
Shadows or Orbs	S	1
Footsteps	F	2
Full Body Apparition	A	5
Objects moving on own	O	5
Doors shutting on own	D	3
ThermoCamera hot or cold spots	T	2

ghost.txt
S 7
A 1
D 3

expected score
1*7 + 5*1 + 3*3 = 7 + 5 + 9 = 21
*/

/*Analyzing Ghost Hunt Data ... -> Before the loop starts
Found 7 instances of shadows or orbs. -> An event name is used. string eventName is needed.
Found 1 instances of a full body apparition.
Found 3 instances of doors shutting on their own.
The haunting score for this place is 21. -> After the loop ends
This place is haunted. -> If the haunting score is greater than 15
Great job! On to the next one. -> Before the program ends
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

  ifstream inFile;
  char eventCode;
  string eventName;
  int hauntingScore, eventCount, points, totalPoints;

  // Open the file
  inFile.open("ghosts.txt");

  cout << "Analyzing Ghost Hunt Data ..." << endl;

  // Loop starts
  // Read data from ghosts.txt
  while (inFile >> eventCode >> eventCount)
  {
    // Information on each event
    switch (eventCode)
    {
    case 'E':
      eventName = "EVP (Electronic Voice Phenomena)";
      points = 3;
      break;
    case 'S':
      eventName = "shadows or Orbs";
      points = 1;
      break;
    case 'F':
      eventName = "footsteps";
      points = 2;
      break;
    case 'A':
      eventName = "full Body Apparition";
      points = 5;
      break;
    case 'O':
      eventName = "objects moving on own";
      points = 5;
      break;
    case 'D':
      eventName = "doors shutting on own";
      points = 3;
      break;
    case 'T':
      eventName = "thermoCamera hot or cold spots";
      points = 2;
      break;
    };

    // Calculate an overall haunting score

    hauntingScore = eventCount * points;
    totalPoints += hauntingScore;

    cout << "Found " << eventCount << " instances of " << eventName << "." << endl;
  }
  // Loop ends

  // Selection structure
  if (hauntingScore > 15)
  {
    cout << "This place is haunted." << endl;
  }
  else
  {
    cout << "This place is probably not haunted." << endl;
  }
  cout << "Great job! On to the next one." << endl;

  // Close the file
  inFile.close();

  return 0;
}