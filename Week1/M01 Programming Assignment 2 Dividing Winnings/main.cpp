/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 3/22/2024
 * Purpose: Dividing Winnings
 */

#include <iostream>

using namespace std;

int main()
{
  int jackpot, numWinners;
  // Prompts:
  cout << "Enter the jackpot amount: " << endl;
  cin >> jackpot;
  cout << "Enter the number of winners: " << endl;
  cin >> numWinners;

  // output:
  // "The first winner gets: $" 2 times the amount of the other winners
  // "All the other winners get: $" the rest of the money divided up

  // numWinners - 1 to get the number of all the other winners than the first winner.
  // Adding 2 because the first winner's portion is like that of two normal winners.
  double equalParts = (numWinners - 1) + 2;
  double normalPrize = jackpot / equalParts;
  double firstPrize = normalPrize * 2;

  cout << "The first winner gets: $" << firstPrize << endl;
  cout << "All the other winners get: $" << normalPrize << endl;

  return 0;
}