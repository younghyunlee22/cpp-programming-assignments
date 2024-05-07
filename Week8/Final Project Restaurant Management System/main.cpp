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
  bool isCheckIn = false;
};

// Struct to save a reservation temporarily
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

// Function prototypes
void clearBuffer(string datatypeExpected);
void setCustomerName(TempReservation &tempReservation);
void setNumberOfPeople(TempReservation &tempReservation);
void setReservationTime(TempReservation &tempReservation);
void makeReservation(Reservation reservations[], int &reservationCount, bool &firstReservationMade);

void clearBuffer(string datatypeExpected)
{
  cout << "You entered something that is not a" << datatypeExpected << ". Please Try again." << endl;
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
    else
    {
      cout << "The number of people in the party must be between 1 and 10." << endl;
    }

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
  cout << "Please confirm the reservation:";
  cout << "Reservation Name: " << tempReservation.customerName << endl;
  cout << "Reservation Time: " << tempReservation.reservationTime << endl;
  cout << "Number in Party: " << tempReservation.numberOfPeople << endl;

  cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
  cin >> choice;
  choice = tolower(choice);
}

// Function to make a reservation
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

  if (choice == 'c')
  {
    return;
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

void checkInReservation(Reservation reservations[], Table tables[], int &reservationCount, int &tableCount)
{

  int reservationChoice;

  cout << "Choose the reservation to check in" << endl;

  for (int i = 0; i < reservationCount; i++)
  {
    if (reservations[i].isCheckIn == false)
    {
      cout << i + 1 << ": " << reservations[i].customerName << " - " << reservations[i].reservationTime << ", " << reservations[i].numberOfPeople << " people" << endl;
    }
  }

  cin >> reservationChoice;

  while (!cin || (reservationChoice < 1 || reservationChoice > reservationCount))
  {
    if (!cin)
    {
      clearBuffer("number");
    }

    cout << "That is not a valid choice. Please choose between 1 and " << reservationCount << endl;
    cin >> reservationChoice;
  }

  int tableChoice;
  cout << "Please assign a table:" << endl;

  bool tableAvailable = false;
  for (int i = 0; i < tableCount; i++)
  {

    if (!tables[i].isOccupied && tables[i].tableCapacity >= reservations[reservationChoice - 1].numberOfPeople)
    {
      tableAvailable = true;
      cout << tables[i].tableNumber << ": " << tables[i].tableCapacity << " people" << endl;
    }
  }

  if (!tableAvailable)
  {
    cout << "There are no open tables that will fit the party. Please complete some orders and have the customers pay their bills to free up tables." << endl;
    return;
  }

  cin >> tableChoice;

  while (!cin || (tableChoice < 1 || tableChoice > tableCount) || tables[tableChoice - 1].isOccupied || tables[tableChoice - 1].tableCapacity < reservations[reservationChoice - 1].numberOfPeople)
  {
    if (!cin)
    {
      clearBuffer("number");
    }

    cout << "That is not a valid choice. Try again." << endl;
    cin >> tableChoice;
  }

  tables[tableChoice - 1].isOccupied = true;
  tables[tableChoice - 1].numSeated = reservations[reservationChoice - 1].numberOfPeople;

  reservations[reservationChoice - 1].isCheckIn = true;
}

int main()
{
  Reservation reservations[50];
  Table tables[20];
  Order orders[50];
  int reservationCount = 0;
  int tableCount = 20;
  int orderCount = 0;

  // The restaurant has 20 tables
  // 1-8: 2 people
  // 9-10: 10 people
  // 11-14: 6 people
  // 15-20: 4 people

  for (int i = 0; i < 20; i++)
  {
    tables[i].tableNumber = i + 1;
    tables[i].numSeated = 0;
    tables[i].isOccupied = false;

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
      checkInReservation(reservations, tables, reservationCount, tableCount);
      break;
    case 3:
      cout << "3 selected" << endl;
      break;
    case 4:
      cout << "4 selected" << endl;
      break;
    case 5:
      cout << "5 selected" << endl;
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid input. Please choose between 1 and 6." << endl;
    }
  } while (choice != 6);

  return 0;
}