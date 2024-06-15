#include <iostream>
#include <string>

using namespace std;

// Enumeration for menu items
enum MenuItem
{
  VEGGIE_BURGER = 35,
  HAMBURGER = 45,
  FRIED_CHICKEN_SLIDERS = 38,
  HAMBURGER_SLIDERS = 38,
  VEGGIE_SLIDERS = 38,
  HADDOCK_SANDWICH = 38,
  BLT = 42,
  FAUX_BLT = 42,
  CHICKEN_BURRITO = 42,
  FALAFEL_WRAP = 42,
  CHEESE_PIZZA = 59,
  PEPPERONI_PIZZA = 59,
  FAUX_MEAT_AND_CHIPS = 77,
  FISH_AND_CHIPS = 77
};

// Struct to manage a reservation
struct Reservation
{
  string customerName;
  int numberOfPeople;
  string reservationTime;
};

struct TempReservation
{
  string customerName;
  int numberOfPeople;
  string reservationTime;
};

// Struct to manage a table
struct Table
{
  int tableNumber;
  int tableCapacity;
  int numSeated;
  bool isOccupied;
};

// Struct to manage an order
struct Order
{
  Reservation reservation;
  Table table;
  MenuItem menuItems[10];
  int numberOfItems;
  bool isComplete;
  bool isPaid;
};

void makeReservation(Reservation reservations[], int &reservationCount, bool &firstReservationMade);
void checkInReservation(Reservation reservations[], Table tables[], int &reservationCount, int &tableCount);
void enterOrder(Order orders[], int &orderCount, Reservation reservations[], Table tables[], int reservationCount, int tableCount);
void completeOrder(Order orders[], int &orderCount);
void calculateAndPayBill(Order orders[], int orderCount);

// Function to make a reservation
void makeReservation(Reservation reservations[], int &reservationCount, bool &firstReservationMade)
{

  Reservation newReservation;
  TempReservation tempReservation;

  if (reservationCount >= 50)
  {
    cout << "Restaurant is fully booked. We can't accept more reservations." << endl;
    return;
  }

  cout << "Enter a name for the reservation: ";
  cin >> tempReservation.customerName;

  cout << "Enter the number of people in the party: ";
  cin >> tempReservation.numberOfPeople;
  cin.clear();
  cin.ignore(100, '\n');

  cout << "Enter the time for the reservation in HH::MM AM/PM: ";
  getline(cin, tempReservation.reservationTime);

  /*Reservation Name: Louie Singleton
Reservation Time: 07:30 PM
Number in Party: 4
Is this information correct [Y]es, [N]o (make changes), [C]ancel? */

  // Get confirmation from the user
  cout << "Please confirm the reservation:";
  cout << "Reservation Name: " << tempReservation.customerName << endl;
  cout << "Reservation Time: " << tempReservation.reservationTime << endl;
  cout << "Number in Party: " << tempReservation.numberOfPeople << endl;

  char choice;
  cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
  cin >> choice;
  choice = tolower(choice);

  while (!cin || (choice != 'y' && choice != 'n' && choice != 'c'))
  {
    if (!cin)
    {
      cout << "You entered something that is not a letter. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }

    cout << "That is not a valid choice. Please choose [Y]es, [N]o, or [C]ancel." << endl;
    cin >> choice;
    choice = tolower(choice);
  }

  if (choice == 'c')
  {
    return;
  }
  else if (choice == 'n')
  {
    /*
    What do you want to change?
    1. Name
    2. Number of People
    3. Time
    4. Cancel
    */
    cout << "modifying..." << endl;
  }
  else
  {
    newReservation.customerName = tempReservation.customerName;
    newReservation.numberOfPeople = tempReservation.numberOfPeople;
    newReservation.reservationTime = tempReservation.reservationTime;
    reservations[reservationCount++] = newReservation;
  }

  if (reservationCount == 1)
  {
    firstReservationMade = true;
  }
}

// Function to check-in for a reservation and assign a table
void checkInReservation(Reservation reservations[], Table tables[], int &reservationCount, int &tableCount)
{
  if (reservationCount == 0)
  {
    cout << "No pending reservations to check in." << endl;
    return;
  }

  cout << "Pending Reservations:" << endl;
  for (int i = 0; i < reservationCount; i++)
  {
    cout << i + 1 << ". " << reservations[i].customerName << " (Party of " << reservations[i].numberOfPeople << ") at " << reservations[i].reservationTime << endl;
  }

  int choice;
  cout << "Enter the number of the reservation to check in: ";
  cin >> choice;

  if (choice < 1 || choice > reservationCount)
  {
    cout << "Invalid choice." << endl;
    return;
  }

  Reservation &selectedReservation = reservations[choice - 1];

  // Find a suitable table for the reservation
  for (int i = 0; i < tableCount; i++)
  {
    Table &currentTable = tables[i];
    if (!currentTable.isOccupied && currentTable.tableCapacity >= selectedReservation.numberOfPeople)
    {
      currentTable.numSeated = selectedReservation.numberOfPeople;
      currentTable.isOccupied = true;
      selectedReservation.numberOfPeople = 0; // Mark reservation as checked-in
      cout << "Reservation checked in and assigned to Table " << currentTable.tableNumber << endl;
      return;
    }
  }

  cout << "No available tables that can accommodate this reservation." << endl;
}

// Function to enter an order
void enterOrder(Order orders[], int &orderCount, Reservation reservations[], Table tables[], int reservationCount, int tableCount)
{
  if (reservationCount == 0 || tableCount == 0)
  {
    cout << "No pending reservations or available tables to enter an order." << endl;
    return;
  }

  cout << "Available Tables:" << endl;
  for (int i = 0; i < tableCount; i++)
  {
    Table &currentTable = tables[i];
    if (!currentTable.isOccupied)
    {
      cout << i + 1 << ". Table " << currentTable.tableNumber << " (Max Size: " << currentTable.tableCapacity << ", Current Size: " << currentTable.numSeated << ")" << endl;
    }
  }

  int tableChoice;
  cout << "Enter the number of the table to place an order: ";
  cin >> tableChoice;

  if (tableChoice < 1 || tableChoice > tableCount)
  {
    cout << "Invalid table choice." << endl;
    return;
  }

  Table &selectedTable = tables[tableChoice - 1];

  if (selectedTable.isOccupied)
  {
    cout << "Table is already occupied." << endl;
    return;
  }

  if (selectedTable.numSeated == 0)
  {
    cout << "No reservation assigned to this table." << endl;
    return;
  }

  // Create a new order
  Order newOrder;
  newOrder.reservation = reservations[selectedTable.tableNumber - 1];
  newOrder.table = selectedTable;
  newOrder.isComplete = false;
  newOrder.isPaid = false;

  cout << "Enter the number of menu items to order (max 10): ";
  cin >> newOrder.numberOfItems;

  if (newOrder.numberOfItems < 1 || newOrder.numberOfItems > 10)
  {
    cout << "Invalid number of items." << endl;
    return;
  }

  cout << "Enter the menu item numbers (1-14) for the order:" << endl;
  for (int i = 0; i < newOrder.numberOfItems; i++)
  {
    int menuItemChoice;
    cin >> menuItemChoice;
    if (menuItemChoice < 1 || menuItemChoice > 14)
    {
      cout << "Invalid menu item choice. Order canceled." << endl;
      return;
    }
    newOrder.menuItems[i] = static_cast<MenuItem>(menuItemChoice - 1);
  }

  orders[orderCount++] = newOrder;
  selectedTable.isOccupied = true;

  cout << "Order successfully placed!" << endl;
}

// Function to mark an order as completed
void completeOrder(Order orders[], int &orderCount)
{
  if (orderCount == 0)
  {
    cout << "No pending orders to complete." << endl;
    return;
  }

  cout << "Pending Orders:" << endl;
  for (int i = 0; i < orderCount; i++)
  {
    if (!orders[i].isComplete)
    {
      cout << i + 1 << ". Table " << orders[i].table.tableNumber << " (Customer: " << orders[i].reservation.customerName << ")" << endl;
    }
  }

  int choice;
  cout << "Enter the number of the order to mark as completed: ";
  cin >> choice;

  if (choice < 1 || choice > orderCount)
  {
    cout << "Invalid choice." << endl;
    return;
  }

  Order &selectedOrder = orders[choice - 1];
  selectedOrder.isComplete = true;
  cout << "Order for Table " << selectedOrder.table.tableNumber << " (Customer: " << selectedOrder.reservation.customerName << ") marked as completed." << endl;
}

// Function to calculate and pay the bill
void calculateAndPayBill(Order orders[], int orderCount)
{

  if (orderCount == 0)
  {
    cout << "There are no orders ready for payment" << endl;
    return;
  }

  double subtotal = 0.0;
  for (int i = 0; i < orderCount; i++)
  {
    if (orders[i].isComplete && !orders[i].isPaid)
    {
      for (int j = 0; j < orders[i].numberOfItems; j++)
      {
        subtotal += static_cast<int>(orders[i].menuItems[j]);
      }
      orders[i].isPaid = true;
    }
  }

  double tax = subtotal * 0.10;
  double tip = subtotal * 0.20;
  double total = subtotal + tax + tip;

  cout << "Bill Calculation:" << endl;
  cout << "Subtotal: $" << subtotal << endl;
  cout << "Tax (10%): $" << tax << endl;
  cout << "Tip (20%): $" << tip << endl;
  cout << "Total: $" << total << endl;
}

int main()
{
  Reservation reservations[50];
  Table tables[20];
  Order orders[50];
  int reservationCount = 0;
  int tableCount = 20;
  int orderCount = 0;

  // Initialize table information
  int tableNumber = 1;
  for (int i = 0; i < tableCount; i++)
  {
    Table &currentTable = tables[i];
    currentTable.tableNumber = tableNumber++;
    if (i < 8)
    {
      currentTable.tableCapacity = 2;
    }
    else if (i < 10)
    {
      currentTable.tableCapacity = 10;
    }
    else if (i < 14)
    {
      currentTable.tableCapacity = 6;
    }
    else
    {
      currentTable.tableCapacity = 4;
    }
    currentTable.numSeated = 0;
    currentTable.isOccupied = false;
  }

  int choice;
  bool firstReservationMade = false;

  do
  {
    cout << "Welcome to Messijoes" << endl;
    cout << "1. Make Reservation" << endl;
    cout << "2. Check-in for Reservation" << endl;
    cout << "3. Enter Order" << endl;
    cout << "4. Complete Order" << endl;
    cout << "5. Calculate and Pay Bill" << endl;

    if (firstReservationMade && reservationCount == 0 && orderCount == 0)
    {
      cout << "6. Close Restaurant\n";
    }

    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "1 selected" << endl;
      makeReservation(reservations, reservationCount, firstReservationMade);
      break;
    case 2:
      cout << "2 selected" << endl;
      // checkInReservation(reservations, tables, reservationCount, tableCount);
      break;
    case 3:
      cout << "3 selected" << endl;
      // enterOrder(orders, orderCount, reservations, tables, reservationCount, tableCount);
      break;
    case 4:
      cout << "4 selected" << endl;
      // completeOrder(orders, orderCount);
      break;
    case 5:
      cout << "5 selected" << endl;
      // calculateAndPayBill(orders, orderCount);
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid choice. Please enter a valid option (1-6)." << endl;
    }
  } while (choice != 6);

  return 0;
}