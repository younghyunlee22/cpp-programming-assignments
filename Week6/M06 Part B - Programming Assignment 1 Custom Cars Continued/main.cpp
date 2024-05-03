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

int enumValue(carColorType carColor)
{

  switch (carColor) // Take a carColorType variable
  {
  case SUNSET:
    return 0; // ;
  case CHERRY:
    return 1;
  case PHANTOM:
    return 2;
  case TITANIUM:
    return 3;
  case GEAUX:
    return 4;
  case LIGHTNING:
    return 5;
  case FOREST:
    return 6;
  case MIDNIGHT:
    return 7;
  case PASSION:
    return 8;
  case ROOT:
    return 9;
  case STORM:
    return 10;
  case OCEAN:
    return 11;
  case GLACIAL:
    return 12;
  }

  return 0;
}

int menu()
{

  int menuNum = 0;

  cout << "Please choose an option from the menu: " << endl;
  cout << "1. Read Existing Order" << endl;
  cout << "2. Add New Order" << endl;
  cout << "3. Quit" << endl;

  cin >> menuNum;

  // Input validation
  while (!cin || menuNum < 1 || menuNum > 3)
  {
    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }

    cout << "Please enter the number next to the menu you want to choose: " << endl;
    cin >> menuNum;
  }

  return menuNum;
}

// Read an existing order
void readOrder()
{
  // Prompt the user for the customer last name
  string customerLastName;
  cout << "Enter the customer last name for the order: " << endl;
  cin >> customerLastName;

  // Read the file
  string filename = customerLastName + ".txt";
  ifstream infile(filename.c_str());

  int topColor;
  int bodyColor;
  int trimColor;

  infile >> topColor;
  infile >> bodyColor;
  infile >> trimColor;

  cout << "here is the order for " << customerLastName << endl;
  cout << "Top Color: " << printColor(static_cast<carColorType>(topColor)) << endl;
  cout << "Body Color: " << printColor(static_cast<carColorType>(bodyColor)) << endl;
  cout << "Trim Color: " << printColor(static_cast<carColorType>(trimColor)) << endl;

  infile.close();
}

/*
The second option will be to add a new order.  You will need to keep 2 parallel arrays.  The first will be an array of strings.  These will be the customer names. The second array will be a 2d array of carColorType with 3 columns, one for each of the car colors. Both arrays will have a maximum size of 10. If the user chooses this option, then you will need to get the customer name and add it to the array of strings. Then you will get the colors for the customer's order in the same way you did for the previous assignment. You will add the 3 colors to the array of carColorType so that it is at the same index as the string array. You do not need to output the order to the output file at this point.*/
void writeOrders(string customerNames[], carColorType orders[][3], int orderCount);

void addOrder(string customerNames[], carColorType orders[][3], int &orderCount)
{

  if (orderCount >= 10)
  {
    cout << "You have entered the maximum number of orders, the program will now save all orders and quit." << endl;
    writeOrders(customerNames, orders, orderCount);
    return;
  }

  string customerName;
  cout << "Enter the name for the order: ";
  cin >> customerName;

  customerNames[orderCount] = customerName;

  carColorType bodyColor = getColor("body");
  // This holds the enumerator for the color chosen by the user
  carColorType topColor = getColor("top");
  carColorType trimColor = getColor("trim");

  // Display the choices back to the user
  cout << "You have chosen " << printColor(bodyColor) << " for the body, " << printColor(topColor) << " for the top, and " << printColor(trimColor) << " for the trim." << endl;

  // Store the current order to the orders array
  orders[orderCount][0] = bodyColor;
  orders[orderCount][1] = topColor;
  orders[orderCount][2] = trimColor;

  char orderYN;
  do
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Do you want to continue with your order? ";
    cin >> orderYN;
  } while (!cin || (orderYN != 'Y' && orderYN != 'y' && orderYN != 'N' && orderYN != 'n'));
}

void writeOrders(string customerNames[], carColorType orders[][3], int orderCount)
{
  cout << "Thank you for using the car customizer. The orders will be saved in files named customerLastName.txt." << endl;
  cout << "writeOrders orderCount: " << orderCount << endl;
  for (int i = 0; i < orderCount; i++)
  {
    string filename = customerNames[i] + ".txt";
    ofstream outfile(filename.c_str());

    if (outfile.is_open())
    {
      outfile << enumValue(orders[i][0]) << endl;
      outfile << enumValue(orders[i][1]) << endl;
      outfile << enumValue(orders[i][2]) << endl;
      outfile.close();
      cout << "Order for " << customerNames[i] << "written to file" << endl;
    }
    else
    {
      cout << "Error opening file: " << filename << endl;
    }
  }
}

int main()
{
  int menuNum;
  // Prompt the user for the body color, top color, and trim color

  cout << "Welcome to the car customizer!" << endl;

  string customerNames[10];
  carColorType orders[10][3];
  int orderCount = 0;

  do
  {
    menuNum = menu();

    switch (menuNum)
    { // Switch statement for the menu
    case 1:
      readOrder();
      break;
    case 2:
      cout << "order count link 319 " << orderCount << endl;
      addOrder(customerNames, orders, orderCount);
      orderCount++;
      cout << "order count line 322 " << orderCount << endl;
      break;
    case 3:
      writeOrders(customerNames, orders, orderCount);
      break;
    }

  } while (menuNum != 3); // Loop until user chooses to quit

  return 0;
}