/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 3/29/2024
 * Purpose: Calendar Events
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  // Write to a file
  ofstream outFile("events.txt");

  // Event details
  string eventName1, eventName2, eventName3, eventName4, eventName5;
  int month1, month2, month3, month4, month5;
  int day1, day2, day3, day4, day5;
  int year1, year2, year3, year4, year5;

  // Get details for the first event
  cout << "Enter the first event name: ";
  getline(cin, eventName1);
  cout << "Enter the month for the event: ";
  cin >> month1;
  cout << "Enter the day for the event: ";
  cin >> day1;
  cout << "Enter the year for the event: ";
  cin >> year1;
  cin.ignore(); // To consume the newline character before using getline for the next event name

  // Get details for the second event
  cout << "Enter the second event name: ";
  getline(cin, eventName2);
  cout << "Enter the month for the event: ";
  cin >> month2;
  cout << "Enter the day for the event: ";
  cin >> day2;
  cout << "Enter the year for the event: ";
  cin >> year2;
  cin.ignore();

  // Get details for the third event
  cout << "Enter the third event name: ";
  getline(cin, eventName3);
  cout << "Enter the month for the event: ";
  cin >> month3;
  cout << "Enter the day for the event: ";
  cin >> day3;
  cout << "Enter the year for the event: ";
  cin >> year3;
  cin.ignore();

  // Get details for the fourth event
  cout << "Enter the fourth event name: ";
  getline(cin, eventName4);
  cout << "Enter the month for the event: ";
  cin >> month4;
  cout << "Enter the day for the event: ";
  cin >> day4;
  cout << "Enter the year for the event: ";
  cin >> year4;
  cin.ignore();

  // Get details for the fifth event
  cout << "Enter the fifth event name: ";
  getline(cin, eventName5);
  cout << "Enter the month for the event: ";
  cin >> month5;
  cout << "Enter the day for the event: ";
  cin >> day5;
  cout << "Enter the year for the event: ";
  cin >> year5;

  // Write table
  // The first event
  outFile << left;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');
  outFile << "| " << setw(19) << "Event Name"
          << "| " << setw(11) << "Event Date"
          << "| " << setw(15) << "Reminder Date"
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');

  string eventDate1 = to_string(month1) + "/" + to_string(day1) + "/" + to_string(year1);
  string reminderDate1 = to_string(month1) + "/" + to_string(day1 - 1) + "/" + to_string(year1);

  outFile << "| " << setw(19) << eventName1
          << "| " << setw(11) << eventDate1
          << "| " << setw(15) << reminderDate1
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;

  // The second event
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');
  outFile << "| " << setw(19) << "Event Name"
          << "| " << setw(11) << "Event Date"
          << "| " << setw(15) << "Reminder Date"
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');

  string eventDate2 = to_string(month2) + "/" + to_string(day2) + "/" + to_string(year2);
  string reminderDate2 = to_string(month2) + "/" + to_string(day2 - 1) + "/" + to_string(year2);

  outFile << "| " << setw(19) << eventName2
          << "| " << setw(11) << eventDate2
          << "| " << setw(15) << reminderDate2
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;

  // The third event
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');
  outFile << "| " << setw(19) << "Event Name"
          << "| " << setw(11) << "Event Date"
          << "| " << setw(15) << "Reminder Date"
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');

  // The third event
  string eventDate3 = to_string(month3) + "/" + to_string(day3) + "/" + to_string(year3);
  string reminderDate3 = to_string(month3) + "/" + to_string(day3 - 1) + "/" + to_string(year3);

  outFile << "| " << setw(19) << eventName3
          << "| " << setw(11) << eventDate3
          << "| " << setw(15) << reminderDate3
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;

  // The fourth event
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');
  outFile << "| " << setw(19) << "Event Name"
          << "| " << setw(11) << "Event Date"
          << "| " << setw(15) << "Reminder Date"
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');

  string eventDate4 = to_string(month4) + "/" + to_string(day4) + "/" + to_string(year4);
  string reminderDate4 = to_string(month4) + "/" + to_string(day4 - 1) + "/" + to_string(year4);

  outFile << "| " << setw(19) << eventName4
          << "| " << setw(11) << eventDate4
          << "| " << setw(15) << reminderDate4
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;

  // The fifth event
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');
  outFile << "| " << setw(19) << "Event Name"
          << "| " << setw(11) << "Event Date"
          << "| " << setw(15) << "Reminder Date"
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;
  outFile << setfill(' ');

  string eventDate5 = to_string(month5) + "/" + to_string(day5) + "/" + to_string(year5);
  string reminderDate5 = to_string(month5) + "/" + to_string(day5 - 1) + "/" + to_string(year5);

  outFile << "| " << setw(19) << eventName5
          << "| " << setw(11) << eventDate5
          << "| " << setw(15) << reminderDate5
          << "| " << endl;
  outFile << "|" << setw(50) << setfill('-') << "-"
          << "|" << endl;

  // Close the file
  outFile.close();

  return 0;
}
