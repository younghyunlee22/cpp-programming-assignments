/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 5/8/2024
 * Purpose: Final Project Restaurant Management System
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// Enumeration for menu items
enum MenuItem
{
  VEGGIE_BURGER,
  HAMBURGER,
  FRIED_CHICKEN_SLIDERS,
  HAMBURGER_SLIDERS,
  VEGGIE_SLIDERS,
  HADDOCK_SANDWICH,
  BLT,
  FAUX_BLT,
  CHICKEN_BURRITO,
  FALAFEL_WRAP,
  CHEESE_PIZZA,
  PEPPERONI_PIZZA,
  FAUX_MEAT_AND_CHIPS,
  FISH_AND_CHIPS
};

// Struct to manage a reservation
struct Reservation
{
  string customerName;
  int numberOfPeople;
  string reservationTime;
  bool isCheckedIn;
  bool reservationPending = true;
};

// Struct to save a reservation temporarily
struct TempReservation
{
  string customerName;
  int numberOfPeople;
  string reservationTime;
};

// Struct to manage an order
struct Order
{
  MenuItem menuItems[10];
  int numberOfItems;
  int tableNumber;
  bool isComplete = false;
  bool isPaid = false;
};

// Struct to manage a table
struct Table
{
  int tableNumber;
  int tableCapacity;
  int numSeated;
  bool isOccupied;
  Order order;
  bool hasOrdered;
};

// Function prototypes
// Function prototypes for making a reservation
void setCustomerName(TempReservation &tempReservation);
void setNumberOfPeople(TempReservation &tempReservation);
void setReservationTime(TempReservation &tempReservation);
void getConfirmation(TempReservation &tempReservation, char &choice);
void makeReservation(Reservation reservations[], int &reservationCount, bool &firstReservationMade);

// Function prototypes for checking in a reservation
void checkInReservation(Reservation reservations[], Table tables[], int &reservationCount, int &tableCount);

// Function prototypes for entering an order
void showMenuItems();
void enterOrder(Table tables[], Order orders[], int &tableCount, int &orderCount);

// Function prototypes for completing an order
void completeOrder(Order orders[], Table tables[], int &tableCount, int &orderCount);

// Function prototypes for calculating and paying a bill
int getMenuItemPrice(MenuItem menuOrdered);
string getMenuItemName(MenuItem menuOrdered);
void calculateAndPayBill(Table tables[], Order orders[], int &orderCount);

// Function prototypes for other functions
void clearBuffer(string datatypeExpected);
bool showCloseRestaurant(Reservation reservations[], int reservationCount, Table tables[], int tableCount);

// Function definitions
void clearBuffer(string datatypeExpected)
{
  // Show warning message
  cout << "You entered something that is not a " << datatypeExpected << ". Please Try again." << endl;
  // Clear the buffer
  cin.clear();
  cin.ignore(100, '\n');
}

void setCustomerName(TempReservation &tempReservation)
{
  cout << "Enter a name for the reservation: ";
  cin.clear();
  cin.ignore(100, '\n');
  getline(cin, tempReservation.customerName);
}

void setNumberOfPeople(TempReservation &tempReservation)
{
  cout << "Enter the number of people in the party: ";
  cin >> tempReservation.numberOfPeople;

  while (!cin || tempReservation.numberOfPeople < 1 || tempReservation.numberOfPeople > 10)
  {
    if (!cin)
    {
      clearBuffer("number");
    }

    cout << "The number of people must be between 1 and 10." << endl;

    cout << "Enter the number of people in the party: ";
    cin >> tempReservation.numberOfPeople;
  }
}

void setReservationTime(TempReservation &tempReservation)
{
  cout << "Enter the time for the reservation in HH::MM AM/PM: ";
  cin.clear();
  cin.ignore(100, '\n');
  getline(cin, tempReservation.reservationTime);
}

void getConfirmation(TempReservation &tempReservation, char &choice)
{
  // Display the reservation information
  cout << "Please confirm the reservation:" << endl;
  cout << "Reservation Name: " << tempReservation.customerName << endl;
  cout << "Reservation Time: " << tempReservation.reservationTime << endl;
  cout << "Number in Party: " << tempReservation.numberOfPeople << endl;

  // Ask the user to confirm the reservation
  cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
  cin >> choice;
  choice = tolower(choice);

  while (!cin || (choice != 'y' && choice != 'n' && choice != 'c'))
  {
    if (!cin)
    {
      clearBuffer("letter");
    }

    cout << "That is not a valid choice. Please choose [Y]es, [N]o, or [C]ancel." << endl;
    cin >> choice;
    choice = tolower(choice);
  }
}

void showMenuItems()
{
  // Display the menu items
  cout << "1: Veggie Burger\n"
       << "2: Hamburger\n"
       << "3: Fried Chicken Sliders\n"
       << "4: Hamburger Sliders\n"
       << "5: Veggie Sliders\n"
       << "6: Haddock Sandwich\n"
       << "7: BLT\n"
       << "8: Faux BLT\n"
       << "9: Chicken Burrito\n"
       << "10: Falafel Wrap\n"
       << "11: Cheese Pizza\n"
       << "12: Pepperoni Pizza\n"
       << "13: Faux Meat and Chips\n"
       << "14: Fish and Chips"
       << endl;
}

int getMenuItemPrice(MenuItem menuOrdered)
{
  // Return the price of the menu item
  switch (menuOrdered)
  {
  case VEGGIE_BURGER:
    return 35;
  case HAMBURGER:
    return 45;
  case FRIED_CHICKEN_SLIDERS:
    return 38;
  case HAMBURGER_SLIDERS:
    return 38;
  case VEGGIE_SLIDERS:
    return 38;
  case HADDOCK_SANDWICH:
    return 38;
  case BLT:
    return 42;
  case FAUX_BLT:
    return 42;
  case CHICKEN_BURRITO:
    return 42;
  case FALAFEL_WRAP:
    return 42;
  case CHEESE_PIZZA:
    return 59;
  case PEPPERONI_PIZZA:
    return 59;
  case FAUX_MEAT_AND_CHIPS:
    return 77;
  case FISH_AND_CHIPS:
    return 77;
  }
}

string getMenuItemName(MenuItem menuOrdered)
{
  // Return the name of the menu item
  switch (menuOrdered)
  {
  case VEGGIE_BURGER:
    return "Veggie Burger";
  case HAMBURGER:
    return "Hamburger";
  case FRIED_CHICKEN_SLIDERS:
    return "Fried Chicken Sliders";
  case HAMBURGER_SLIDERS:
    return "Hamburger Sliders";
  case VEGGIE_SLIDERS:
    return "Veggie Sliders";
  case HADDOCK_SANDWICH:
    return "Haddock Sandwich";
  case BLT:
    return "BLT";
  case FAUX_BLT:
    return "Faux BLT";
  case CHICKEN_BURRITO:
    return "Chicken Burrito";
  case FALAFEL_WRAP:
    return "Falafel Wrap";
  case CHEESE_PIZZA:
    return "Cheese Pizza";
  case PEPPERONI_PIZZA:
    return "Pepperoni Pizza";
  case FAUX_MEAT_AND_CHIPS:
    return "Faux Meat and Chips";
  case FISH_AND_CHIPS:
    return "Fish and Chips";
  }
}

void makeReservation(Reservation reservations[], int &reservationCount, bool &firstReservationMade)
{

  Reservation newReservation;
  TempReservation tempReservation;
  char choice;

  if (reservationCount >= 50)
  {
    cout << "Restaurant is fully booked. We can't accept more reservations." << endl;
    return;
  }

  // Get the reservation information and confirmation
  setCustomerName(tempReservation);
  setNumberOfPeople(tempReservation);
  setReservationTime(tempReservation);
  getConfirmation(tempReservation, choice);

  while (!cin || (choice != 'y' && choice != 'n' && choice != 'c'))
  {
    if (!cin)
    {
      clearBuffer("letter");
    }

    cout << "That is not a valid choice. Please choose [Y]es, [N]o, or [C]ancel." << endl;
    cin >> choice;
    choice = tolower(choice);
  }

  // If the user wants to make changes to the reservation
  while (choice == 'n')
  {

    int changeChoice;

    cout << "What do you want to change?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Number of People" << endl;
    cout << "3. Time" << endl;
    cout << "4. Cancel" << endl;
    cin >> changeChoice;

    while (!cin || (changeChoice < 1 || changeChoice > 4))
    {
      if (!cin)
      {
        clearBuffer("number");
      }

      cout << "That is not a valid choice. Please choose between 1 and 4." << endl;
      cin >> changeChoice;
    }

    // Switch statement to handle the user's choice for changing the reservation
    switch (changeChoice)
    {
    case 1:
      setCustomerName(tempReservation);
      getConfirmation(tempReservation, choice);
      break;
    case 2:
      setNumberOfPeople(tempReservation);
      getConfirmation(tempReservation, choice);
      break;
    case 3:
      setReservationTime(tempReservation);
      getConfirmation(tempReservation, choice);
      break;
    case 4:
      return;
    }
  }

  // If the user wants to cancel the reservation
  if (choice == 'c')
  {
    return;
  }
  // If the user confirms the reservation
  else
  {
    // Set the reservation information using the temp reservation information
    newReservation.customerName = tempReservation.customerName;
    newReservation.numberOfPeople = tempReservation.numberOfPeople;
    newReservation.reservationTime = tempReservation.reservationTime;

    // Add the reservation to the list of reservations
    reservations[reservationCount++] = newReservation;

    // Set the first reservation made to true
    // This is used to show the close restaurant option
    // We can't close the restaurant if there are no reservations that have been made
    firstReservationMade = true;
  }
}

void checkInReservation(Reservation reservations[], Table tables[], int &reservationCount, int &tableCount)
{

  int reservationChoice;

  cout << "Choose the reservation to check in" << endl;
  bool showErrorMessage = true;

  for (int i = 0; i < reservationCount; i++)
  {
    // if the reservation is not checked in
    if (!reservations[i].isCheckedIn)
    {
      // show the reservation
      cout << i + 1 << ": " << reservations[i].customerName << " - " << reservations[i].reservationTime << ", " << reservations[i].numberOfPeople << " people" << endl;
      showErrorMessage = false;
    }
  }

  if (showErrorMessage)
  {
    cout << "There are no reservations to check in. Please make a reservation first." << endl;
    return;
  }
  cin >> reservationChoice;

  int tableChoice;
  cout << "Please assign a table:";

  bool tableAvailable = false;
  for (int i = 0; i < tableCount; i++)
  {
    // if the table is not occupied
    // and the table capacity is greater than or equal to the number of people in the reservation
    if (!tables[i].isOccupied && tables[i].tableCapacity >= reservations[reservationChoice - 1].numberOfPeople)
    {
      // show the table
      tableAvailable = true;
      cout << tables[i].tableNumber << ": " << tables[i].tableCapacity << " people" << endl;
    }
  }

  // if there are no tables available
  if (!tableAvailable)
  {
    cout << "There are no open tables that will fit the party. Please complete some orders and have the customers pay their bills to free up tables." << endl;
    return;
  }

  cin >> tableChoice;

  // assign the table to the reservation
  tables[tableChoice - 1].isOccupied = true;

  // assign the number of people in the reservation to the table
  // this is used to keep track of the number of entrees to get orders for
  tables[tableChoice - 1].numSeated = reservations[reservationChoice - 1].numberOfPeople;

  // mark the reservation as checked in
  reservations[reservationChoice - 1].isCheckedIn = true;

  // mark the reservation as not pending
  reservations[reservationChoice - 1].reservationPending = false;
}

void enterOrder(Table tables[], Order orders[], int &tableCount, int &orderCount)
{
  int tableChoice;

  cout << "Please choose the table for the order: " << endl;

  bool showErrorMessage = true;

  for (int i = 0; i < tableCount; i++)
  {
    // if the table is occupied and hasn't ordered yet
    if (tables[i].isOccupied && !tables[i].hasOrdered)
    {
      // show the table
      cout << tables[i].tableNumber << ": Table " << tables[i].tableNumber << endl;
      showErrorMessage = false;
    }
  }

  if (showErrorMessage)
  {
    cout << "There are no tables without orders." << endl;
    return;
  }

  cin >> tableChoice;

  // set up a new order struct
  Order newOrder;
  newOrder.tableNumber = tableChoice - 1;
  newOrder.isComplete = false;
  newOrder.isPaid = false;
  newOrder.numberOfItems = tables[tableChoice - 1].numSeated;

  // get the menu items for the order
  int menuChoice;
  for (int i = 0; i < newOrder.numberOfItems; i++)
  {
    string prompt = "Please choose entree number ";
    cout << prompt << i + 1 << endl;
    showMenuItems();
    cin >> menuChoice;

    // save the enum chosen to the menuItems array in the order struct
    newOrder.menuItems[i] = static_cast<MenuItem>(menuChoice - 1);
  }

  // save the order to the orders array
  orders[orderCount++] = newOrder;

  // mark the table as having ordered
  tables[tableChoice - 1].hasOrdered = true;
}

void completeOrder(Order orders[], Table tables[], int &tableCount, int &orderCount)
{
  int orderIndex;
  cout << "Choose the order to complete:" << endl;

  bool showErrorMessage = true;

  for (int i = 0; i < orderCount; i++)
  {
    // if the table's order is not complete
    if (!orders[i].isComplete)
    {
      // show the table number
      cout << i + 1 << ": Table " << orders[i].tableNumber + 1 << endl;
      showErrorMessage = false;
    }
  }

  if (showErrorMessage)
  {
    cout << "There are no orders to complete." << endl;
    return;
  }

  cin >> orderIndex;
  // mark the order as complete
  orders[orderIndex - 1].isComplete = true;
}

void calculateAndPayBill(Table tables[], Order orders[], int &orderCount)
{
  int orderIndex;

  cout << "Choose the order to calculate the bill:" << endl;

  bool showErrorMessage = true;

  for (int i = 0; i < orderCount; i++)
  {
    // if the table's order is complete and not paid
    if (orders[i].isComplete && !orders[i].isPaid)
    {
      // show the table number
      cout << i + 1 << ": Table " << orders[i].tableNumber + 1 << endl;
      showErrorMessage = false;
    }
  }

  if (showErrorMessage)
  {
    cout << "There are no orders ready for payment" << endl;
    return;
  }

  cin >> orderIndex;

  // show the bill for the table and calculate the bill
  cout << "Here is the bill for table " << orders[orderIndex - 1].tableNumber + 1 << endl;

  double subtotal = 0.0;
  double itemPrice = 0.0;

  // set the decimal precision to 2
  cout << fixed << showpoint << setprecision(2);

  for (int i = 0; i < orders[orderIndex - 1].numberOfItems; i++)
  {
    // get the price of the menu item and the menu name and display it
    itemPrice = getMenuItemPrice(orders[orderIndex - 1].menuItems[i]);
    cout << getMenuItemName(orders[orderIndex - 1].menuItems[i]) << " - $" << itemPrice << endl;

    // add the price to the subtotal
    subtotal += itemPrice;
  }

  // calculate the tip, tax, and total
  double tip = subtotal * 0.20;
  double tax = subtotal * 0.10;
  double total = subtotal + tip + tax;

  cout << "Subtotal: $" << subtotal << endl;
  cout << "Tip: $" << tip << endl;
  cout << "Tax: $" << tax << endl;
  cout << "Total: $" << total << endl;

  // ask the user if they want to pay the bill
  char payBillChoice;

  cout << "Pay Bill?";
  cin >> payBillChoice;
  payBillChoice = tolower(payBillChoice);

  // if the user wants to pay the bill
  if (payBillChoice == 'y')
  {
    // mark the order as paid
    orders[orderIndex - 1].isPaid = true;

    // clear the table
    tables[orders[orderIndex - 1].tableNumber].isOccupied = false;
    tables[orders[orderIndex - 1].tableNumber].hasOrdered = false;
    tables[orders[orderIndex - 1].tableNumber].numSeated = 0;
    tables[orders[orderIndex - 1].tableNumber].order = Order();
  }
  else
  {
    return;
  }
}

bool showCloseRestaurant(Reservation reservations[], int reservationCount, Table tables[], int tableCount)
{
  // condition 1: there are no pending reservations
  for (int i = 0; i < reservationCount; i++)
  {
    if (reservations[i].reservationPending)
    {
      return false;
    }
  }
  // condition 2: there are no outstanding orders
  // table is checked in, but an order hasn't been made/hasn't been paid yet
  //    return false

  for (int i = 0; i < tableCount; i++)
  {
    if (tables[i].isOccupied)
    {
      if (!tables[i].hasOrdered || !tables[i].order.isPaid)
      {
        return false;
      }
    }
  }

  // it should return true when you show the "close restaurant" option
  // returns false when you don't
  return true;
}

// Main function
int main()
{
  Reservation reservations[50];
  Table tables[20];
  Order orders[50];
  int reservationCount = 0;
  int tableCount = 20;
  int orderCount = 0;

  // Initialize the tables
  for (int i = 0; i < 20; i++)
  {
    tables[i].tableNumber = i + 1;
    tables[i].numSeated = 0;
    tables[i].isOccupied = false;
    tables[i].hasOrdered = false;

    if (i < 8)
    {
      tables[i].tableCapacity = 2;
    }
    else if (i < 10)
    {
      tables[i].tableCapacity = 10;
    }
    else if (i < 14)
    {
      tables[i].tableCapacity = 6;
    }
    else
    {
      tables[i].tableCapacity = 4;
    }
  }

  int choice;
  bool firstReservationMade = false;

  do
  {
    cout << "Welcome to Messijoes" << endl;
    cout << "1. Make Reservation" << endl;
    cout << "2. Check-in Reservation" << endl;
    cout << "3. Enter Order" << endl;
    cout << "4. Complete Order" << endl;
    cout << "5. Calculate and Pay Bill" << endl;

    // show the close restaurant option if there are no pending reservations and
    // no outstanding orders
    // and also if a reservation has been made
    if (showCloseRestaurant(reservations, reservationCount, tables, tableCount) && firstReservationMade)
    {
      cout << "6. Close Restaurant" << endl;
    }

    cin >> choice;

    while (!cin || (choice < 1 || choice > 6))
    {
      if (!cin)
      {
        clearBuffer("number");
      }

      cout << "That is an invalid choice. Please try again." << endl;
      cout << "Welcome to Messijoes" << endl;
      cout << "1. Make Reservation" << endl;
      cout << "2. Check-in Reservation" << endl;
      cout << "3. Enter Order" << endl;
      cout << "4. Complete Order" << endl;
      cout << "5. Calculate and Pay Bill" << endl;
      if (showCloseRestaurant(reservations, reservationCount, tables, tableCount) && firstReservationMade)
      {
        cout << "6. Close Restaurant" << endl;
      }

      cin >> choice;
    }

    // handle the user's choice
    switch (choice)
    {
    case 1:
      makeReservation(reservations, reservationCount, firstReservationMade);
      break;
    case 2:
      checkInReservation(reservations, tables, reservationCount, tableCount);
      break;
    case 3:
      enterOrder(tables, orders, tableCount, orderCount);
      break;
    case 4:
      completeOrder(orders, tables, tableCount, orderCount);
      break;
    case 5:
      calculateAndPayBill(tables, orders, orderCount);
      break;
    case 6:
      return 0;
    default:
      cout << "That is an invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != 6);

  return 0;
}