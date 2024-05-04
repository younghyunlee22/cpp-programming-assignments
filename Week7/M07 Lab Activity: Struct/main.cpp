/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 5/1/2024
 * Purpose: Contact struct
 */

/*
For today's activity, I'd like you to create a C++ program that stores contact information for colleagues in a struct. Your struct should store the first name, last name, phone number, email address, street address, City, State, and postal code for each contact. Write a function which displays each of these items on the screen.

For this assignment, it's fine to create a struct within your program rather than inputting values from the user. In a larger program, you'd probably end up creating something such as an array of structs to store many users, and would need functions for adding and modifying the data members, but for now, I just want to make sure that everyone can create a struct and work with it's members.
*/
#include <iostream>
#include <string>

using namespace std;

// Create a struct to store contact information
struct contactInfo
{
  string firstName;
  string lastName;
  string phoneNumber;
  string emailAddress;
  string streetAddress;
  string city;
  string state;
  string postalCode;
};

// Function to print the contact information
void printContactInfo(contactInfo contact)
{
  cout << "First Name: " << contact.firstName << endl;
  cout << "Last Name: " << contact.lastName << endl;
  cout << "Phone Number: " << contact.phoneNumber << endl;
  cout << "Email Address: " << contact.emailAddress << endl;
  cout << "Street Address: " << contact.streetAddress << endl;
  cout << "City: " << contact.city << endl;
  cout << "State: " << contact.state << endl;
  cout << "Postal Code: " << contact.postalCode << endl;
}

int main()
{
  // Create a contact
  contactInfo contact1 = {
      "John",
      "Doe",
      "(123)456-7890",
      "john.doe@example.com",
      "123 Main St",
      "Michigan City",
      "IN",
      "46360"};

  // Print the contact information
  printContactInfo(contact1);

  return 0;
}