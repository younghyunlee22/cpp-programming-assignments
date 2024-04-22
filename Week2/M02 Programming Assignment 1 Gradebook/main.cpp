#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  ifstream infile;
  infile.open("gradebook.txt");

  // Table heading output
  cout << left;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');
  cout << "| " << setw(15) << "Student Num"
       << "| " << setw(30) << "Student Name"
       << "| " << setw(10) << "Percent"
       << "| " << setw(10) << "Grade"
       << "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');

  int studentNum;
  string firstName, lastName, grade;
  double percent;

  // Read and write first line
  infile >> studentNum >> firstName >> lastName >> percent >> grade;
  cout << "| " << setw(15) << studentNum
       << "| " << setw(30) << firstName + " " + lastName
       << "| " << setw(8) << right << fixed << setprecision(3) << percent * 100 << "% "
       << "| " << setw(10) << left << grade << "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');

  // Read and write second line
  infile >> studentNum >> firstName >> lastName >> percent >> grade;
  cout << left;
  cout << "| " << setw(15) << studentNum
       << "| " << setw(30) << firstName + " " + lastName
       << "| " << setw(8) << right << fixed << setprecision(3) << percent * 100 << "% "
       << "| " << setw(10) << left << grade << "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');

  // Read and write third line
  infile >> studentNum >> firstName >> lastName >> percent >> grade;
  cout << left;
  cout << "| " << setw(15) << studentNum
       << "| " << setw(30) << firstName + " " + lastName
       << "| " << setw(8) << right << fixed << setprecision(3) << percent * 100 << "% "
       << "| " << setw(10) << left << grade << "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');

  // Read and write fourth line
  infile >> studentNum >> firstName >> lastName >> percent >> grade;
  cout << left;
  cout << "| " << setw(15) << studentNum
       << "| " << setw(30) << firstName + " " + lastName
       << "| " << setw(8) << right << fixed << setprecision(3) << percent * 100 << "% "
       << "| " << setw(10) << left << grade << "|" << endl;
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;
  cout << setfill(' ');

  // Read and write fifth line
  infile >> studentNum >> firstName >> lastName >> percent >> grade;
  cout << left;
  cout << "| " << setw(15) << studentNum
       << "| " << setw(30) << firstName + " " + lastName
       << "| " << setw(8) << right << fixed << setprecision(3) << percent * 100 << "% "
       << "| " << setw(10) << left << grade << "|" << endl;
  cout << left;

  // Closing table borders
  cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-"
       << "+" << endl;

  // Close the files
  infile.close();

  return 0;
}