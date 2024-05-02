/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/26/2024
 * Purpose: Custom Cars
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Creating an enum

enum carColorType
{
  SUNSET,
  CHERRY,
  PHANTOM,
  TITANIUM,
  GEAUX,
  LIGHTNING,
  FOREST,
  MIDNIGHT,
  PASSION,
  ROOT,
  STORM,
  OCEAN,
  GLACIAL
};

// This function will prompt the user using a numbered menu system for a color for the part of the car indicated by the string.  It will map the number entered by the user to a enumerator which is returned.

carColorType getColor(string part)
{
  int colorNum;
  // Prompt the user to choose a color for the part of the car
  cout << "Please choose a color for the " << part << endl;

  // Colors in string
  cout << "1. Sunset Orange" << endl;
  cout << "2. Cherry Bomb" << endl;
  cout << "3. Phantom Black" << endl;
  cout << "4. Titanium Silver" << endl;
  cout << "5. Geaux Gold" << endl;
  cout << "6. Lightning Yellow" << endl;
  cout << "7. Forest Green" << endl;
  cout << "8. Midnight Blue" << endl;
  cout << "9. Passion Purple" << endl;
  cout << "10. Root Beer" << endl;
  cout << "11. Storm Surge" << endl;
  cout << "12. Ocean's Rip" << endl;
  cout << "13. Glacial White" << endl;

  cin >> colorNum;

  // Input validation
  while (!cin || colorNum < 1 || colorNum > 13)
  {
    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }

    cout << "Please enter the number next to the color you want to choose: " << endl;
    cin >> colorNum;
  }

  // Map the number entered by the user to a enumerator
  switch (colorNum)
  {
  case 1:
    return SUNSET; // return the corresponding enumerator
  case 2:
    return CHERRY;
  case 3:
    return PHANTOM;
  case 4:
    return TITANIUM;
  case 5:
    return GEAUX;
  case 6:
    return LIGHTNING;
  case 7:
    return FOREST;
  case 8:
    return MIDNIGHT;
  case 9:
    return PASSION;
  case 10:
    return ROOT;
  case 11:
    return STORM;
  case 12:
    return OCEAN;
  case 13:
    return GLACIAL;
  }
}

// This function will take a carColorType variable and turn it into a string that can be printed.
string printColor(carColorType carColor)
{

  switch (carColor) // Take a carColorType variable
  {
  case SUNSET:
    return "Sunset Orange"; // Turn it into a string
  case CHERRY:
    return "Cherry Bomb";
  case PHANTOM:
    return "Phantom Black";
  case TITANIUM:
    return "Titanium Silver";
  case GEAUX:
    return "Geaux Gold";
  case LIGHTNING:
    return "Lightning Yellow";
  case FOREST:
    return "Forest Green";
  case MIDNIGHT:
    return "Midnight Blue";
  case PASSION:
    return "Passion Purple";
  case ROOT:
    return "Root Beer";
  case STORM:
    return "Storm Surge";
  case OCEAN:
    return "Ocean's Rip";
  case GLACIAL:
    return "Glacial White";
  }

  return 0;
}

int main()
{
  char orderYN;
  // Prompt the user for the body color, top color, and trim color

  cout << "Welcome to the car customizer!" << endl;

  carColorType bodyColor = getColor("body"); // This holds the enumerator for the color chosen by the user
  carColorType topColor = getColor("top");
  carColorType trimColor = getColor("trim");

  // Display the choices back to the user
  cout << "You have chosen " << printColor(bodyColor) << " for the body, " << printColor(topColor) << " for the top, and " << printColor(trimColor) << " for the trim." << endl;

  cout << "Do you want to continue with your order? " << endl;
  cin >> orderYN;

  while (!cin || (orderYN != 'Y' && orderYN != 'y' && orderYN != 'N' && orderYN != 'n'))
  {
    if (!cin)
    {
      cin.clear();
      cin.ignore(100, '\n');
    }
    cout << "Please enter Y or N." << endl;
    cin >> orderYN;
  }

  // The output file will list the top color on the first line as its enumerator value, then the body color on the middle line as its enumerator value, and finally the trim color on the last line as its enumerator value.

  if (orderYN == 'Y' || orderYN == 'y')
  {
    // Output file
    ofstream outfile("order.txt");

    // Write the value of the enumerators to the file

    outfile << topColor << endl;
    outfile << bodyColor << endl;
    outfile << trimColor << endl;

    outfile.close();
  }

  return 0;
}