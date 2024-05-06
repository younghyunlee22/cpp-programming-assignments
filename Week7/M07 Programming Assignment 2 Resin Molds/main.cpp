#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Enum for mold sizes
enum sizeType
{
  S,
  M,
  L
};

// Struct for molds
struct moldType
{
  string shape;
  sizeType size;
  double price;
  double weight;
};

// Struct for customers
struct customerType
{
  string fname;
  string lname;
  string address;
};

// Struct for orders
struct orderType
{
  customerType customer;
  moldType products[10];
  int numProdOrdered;
  double subTotal;
  double totalWeight;
  double shippingCost;
};

// Read catalog data from the file
/*
This function reads catalog.txt. Each line of the file contains information about a mold that is currently for sale. Because she is frequently rotating stock around, this file will change and have different information in it (you cannot hardcode the data into the program).
*/

sizeType charToSizeType(char sizeChar)
{
  if (sizeChar == 'S')
  {
    return S;
  }
  else if (sizeChar == 'M')
  {
    return M;
  }
  else if (sizeChar == 'L')
  {
    return L;
  }
  else
  {
    cerr << "Invalid size character: " << sizeChar << endl;
    exit(1); // Exit the program
  }
}

string sizeTypeToString(sizeType size)
{
  switch (size)
  {
  case 0:
    return "Small";
  case 1:
    return "Medium";
  case 2:
    return "Large";
  default:
    cerr << "Invalid size" << endl;
    exit(1);
  }
}

void readCatalog(moldType productCatalog[], int &numProducts)
{
  ifstream infile("catalog.txt");
  if (!infile)
  {
    cerr << "Error opening catalog.txt" << endl;
    return;
  }

  int i = 0;
  char sizeChar;

  while (infile >> productCatalog[i].shape >> sizeChar >> productCatalog[i].price >> productCatalog[i].weight)
  {
    productCatalog[i].size = charToSizeType(sizeChar);
    i++;
  }

  numProducts = i;

  infile.close();
}

// Function to enter order information
void enterOrder(orderType &order, moldType catalog[], int numItemsInCatalog)
{

  // cout << "numItemsInCatalog" << numItemsInCatalog << endl;

  cout << "Enter the customer first name: ";
  cin >> order.customer.fname;

  cout << "Enter the customer last name: ";
  cin >> order.customer.lname;
  cin.clear();
  cin.ignore(100, '\n');

  cout << "Enter the customer street address: ";
  getline(cin, order.customer.address);

  string cityStateZip;
  cout << "Enter the customer city, state, and zip code: ";
  getline(cin, cityStateZip);

  // Concatenate city, state, zip to the address
  order.customer.address += '\n' + cityStateZip;

  // Input product details
  order.numProdOrdered = 0;
  order.subTotal = 0;
  order.totalWeight = 0;
  char choice = 'y';

  while (choice == 'y' && order.numProdOrdered < 10)
  {
    cout << "Please choose a product from list:\n";
    cout << fixed << showpoint << setprecision(2);
    for (int i = 0; i < numItemsInCatalog; i++)
    {
      cout << i + 1 << ". " << catalog[i].shape << " - " << sizeTypeToString(catalog[i].size) << " $" << catalog[i].price << " " << catalog[i].weight << "g\n";
    }
    int selection;
    cin >> selection;

    while (!cin || selection < 1 || selection > numItemsInCatalog)
    {
      if (!cin)
      {
        cout << "You entered something that is not a number. Please Try again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
      }

      cout << "That is not a valid choice. Please choose the class by number from the list." << endl;
      cin >> selection;
    }

    cout << "item: " << catalog[selection - 1].shape << " - " << sizeTypeToString(catalog[selection - 1].size) << " $" << catalog[selection - 1].price << ' ' << catalog[selection - 1].weight << "g added." << endl;

    order.products[order.numProdOrdered] = catalog[selection - 1];
    order.subTotal += order.products[order.numProdOrdered].price;
    order.totalWeight += order.products[order.numProdOrdered].weight;
    order.numProdOrdered++;

    if (order.numProdOrdered < 10)
    {
      cout << "Do you want to add another product to the order?";
      cin >> choice;
      choice = tolower(choice);
      cin.clear();
      cin.ignore(100, '\n');
    }
    else
    {
      cout << "maximum number of products ordered.";
      break;
    }
  }

  order.shippingCost = 0.58 * (order.totalWeight / 28.35);
}

// Function to print mold details
void printProduct(ostream &out, moldType mold)
{
  out << mold.shape << " - " << sizeTypeToString(mold.size) << " $" << mold.price << " " << mold.weight << "g\n";
}

// Function to print order details
void printOrder(ostream &out, orderType &order)
{
  out << fixed << showpoint << setprecision(2);
  out << "Customer: " << order.customer.fname << ' ' << order.customer.lname << endl;
  out << order.customer.address << "\n\n";

  out << "Products Ordered: " << endl;
  // debugging
  // out << "order.numProdOrdered" << order.numProdOrdered << endl;

  for (int i = 0; i < order.numProdOrdered; i++)
  {
    printProduct(out, order.products[i]);
  }

  out << '\n';

  double totalCost = 0.0;

  out << "Subtotal: $" << order.subTotal << endl;
  out << "Total Weight: " << order.totalWeight << "g" << endl;
  out << "Shipping Cost: $" << order.shippingCost << endl;
  out << "Total Cost: $" << order.subTotal + order.shippingCost << endl;
}

int main()
{
  const int MAX_PRODUCTS = 20;
  moldType productCatalog[MAX_PRODUCTS];
  int numProducts = MAX_PRODUCTS; // a variable to store the actual number of items in the catalog

  char selection;

  cout << "Welcome to Judy's Resin Molds!" << endl;

  do
  {
    // Read catalog data from file
    readCatalog(productCatalog, numProducts);

    // Get order input
    orderType order = {};
    int numItemsInCatalog = numProducts;
    enterOrder(order, productCatalog, numItemsInCatalog);

    // Print order details to the console
    printOrder(cout, order);

    // Create output file using customer's last name
    string filename = order.customer.lname + ".txt";
    ofstream outputFile(filename);

    // Print order details to the output file
    printOrder(outputFile, order);
    outputFile.close();

    // Check if there's more order to enter
    cout << "Do you want to enter another order? ";
    cin >> selection;
    cin.ignore(100, '\n');
    selection = tolower(selection);

    while (selection != 'y' && selection != 'n') // Validate the input
    {
      cout << "Invalid input. Please enter 'y' to continue or 'n' to stop: ";
      cin >> selection;
      cin.ignore(100, '\n');
      selection = tolower(selection);
    }
  } while (selection == 'y');

  cout << "Have a nice day!";

  return 0;
}