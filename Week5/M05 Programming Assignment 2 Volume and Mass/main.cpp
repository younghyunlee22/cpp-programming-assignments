/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/22/2024
 * Purpose: Volume and Mass
 */

/*
You are working on a program that helps bakers convert from weight measurements to volume measurements and back again.  Your program will need to have the following functions:

Function 1
Function Name
getIngredient
Parameters
none
Return Type
string
Description
This function prompts the user for the ingredient they want to convert. It performs the validation that the chosen ingredient is one in the table below.
Function 2
Function Name
getDensity
Parameters
string for the ingredient name
Return Type
double
Description
This function takes the name of the ingredient and returns the density.
Function 3
Function Name
getWeight
Parameters
none
Return Type
double
Description
This function gets the weight of the ingredient from the user to convert to volume.  It does the input validation to ensure that the weight is greater than 0 and that the user input doesn't cause input failure. It returns the validated double.
Function 4
Function Name
getVolume
Parameters
none
Return Type
double
Description
This function does stuff
Function 5
Function Name
convertWeight
Parameters
weight : double
density : double
Return Type
double
Description
This function takes the weight for the ingredient and the density and uses the formula
to calculate and return the volume needed for the ingredient.
Function 6
Function Name
convertVolume
Parameters
volume : double
density : double
Return Type
double
Description
This function takes the volume for the ingredient and the density and uses the formula
 to calculate and return the weight needed for the ingredient.
For the main, you will use the functions you created to get the ingredient from the user. Then you will need to find out if they want to convert from a weight measurement or a volume measurement.  Next, you will use the correct conversion function to convert either the volume or weight provided. Finally, you will print the results to the user to 4 decimal places.

Ingredient Densities
Ingredient	Density g/cm3
Sugar	1.59
Flour	0.762
Cocoa Powder	1.35
Honey	1.38
Egg	1.031
Milk	1.025
Water	0.997
Oil	0.91
Input Validation:
You should ensure that the user input does not cause input failure. You should also ensure that the ingredient entered is one that is in the table of ingredient densities. The case of the ingredient shouldn't matter, and make sure you account for ingredients that have two words in their name (Coco Powder). You also need to make sure that the volume or weight entered by the user is greater than 0. When getting the character that determines if the user wants to convert from weight or volume, the case shouldn't matter.

Sample Output:
Welcome to the baking converter.
This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit.
Enter the name of the ingredient: Sugar
Do you want to convert from weight or volume? (Enter W or V): V
Enter the volume of your ingredient in ml: 236.588
236.5880 ml of Sugar is 376.1749 g
Welcome to the baking converter.
This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit.
Enter the name of the ingredient: butter
I don't know that ingredient. Here is a list of ingredients I know:
Sugar, Flour, Coco Powder, Honey, Egg, Milk, Water, and Oil
Enter the name of the ingredient: flour
Do you want to convert from weight or volume? (Enter W or V): W
Enter the weight of your ingredient in g: 325
325.0000 g of flour is 426.5092 ml
Welcome to the baking converter.
This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit.
Enter the name of the ingredient: coco powder
Do you want to convert from weight or volume? (Enter W or V): w
Enter the weight of your ingredient in g: g
You entered something that is not a number. Please Try again.
Enter the weight of your ingredient in g: 200
200.0000 g of coco powder is 148.1481 ml
*/
#include <iostream>
#include <string>

using namespace std;

string getIngredient()
{
  string ingredient = "";
  string ingredientPrompt = "Enter the name of the ingredient: ";
  bool validIngredient = false;

  // Loop until a valid ingredient is entered
  while (!validIngredient)
  {
    cout << ingredientPrompt << endl;
    // Handle input failure
    getline(cin, ingredient);

    // Input Validation. Input must be a string.
    // Convert all characters to lowercase for non-case sensitive comparison.
    bool validCharacters = true;

    for (int i = 0; i < ingredient.length(); i++)
    {
      char c = ingredient[i];
      if (c >= 'A' && c <= 'Z')
      { // Convert uppercase to lowercase
        ingredient[i] += 32;
      }
      else if (!(c >= 'a' && c <= 'z') && c != ' ')
      { // Check if the character is not a letter or space
        cout << "You entered something that is not a letter. Please try again." << endl;
        validCharacters = false;
        break;
      }
    }

    // If invalid characters were found, restart the loop
    if (!validCharacters)
    {
      continue;
    }

    // Compare the valid input with the ingredients in the list.
    if (ingredient == "sugar" || ingredient == "flour" || ingredient == "cocoa powder" ||
        ingredient == "honey" || ingredient == "egg" || ingredient == "milk" ||
        ingredient == "water" || ingredient == "oil")
    {
      validIngredient = true; // Set to true to break the loop when valid
    }
    else
    {
      cout << "I don't know that ingredient. Here is a list of ingredients I know:" << endl;
      cout << "Sugar, Flour, Cocoa Powder, Honey, Egg, Milk, Water, and Oil" << endl;
      continue; // Restart the loop if it's not in the list
    }
  }

  return ingredient;
}

double getDensity(string ingredient)
{

  if (ingredient == "sugar")
  {
    return 1.59;
  }
  if (ingredient == "flour")
  {
    return 0.762;
  }
  if (ingredient == "cocoa powder")
  {
    return 1.35;
  }
  if (ingredient == "honey")
  {
    return 1.38;
  }
  if (ingredient == "egg")
  {
    return 1.031;
  }
  if (ingredient == "milk")
  {
    return 1.025;
  }
  if (ingredient == "water")
  {
    return 0.997;
  }
  if (ingredient == "oil")
  {
    return 0.91;
  }

  return -1;
}

double getWeight()
{
  // This function gets the weight of the ingredient from the user to convert to volume.  It does the input validation to ensure that the weight is greater than 0 and that the user input doesn't cause input failure. It returns the validated double.

  double ingredientWeight;

  string weightPrompt = "Enter the weight of your ingredient in g: ";
  cout << weightPrompt << endl;
  cin >> ingredientWeight;

  while (!cin || ingredientWeight <= 0)
  {

    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
    else if (ingredientWeight <= 0)
    {
      cout << "Weight must be greater than 0" << endl;
    }
    cout << weightPrompt << endl;
    cin >> ingredientWeight;
  }

  return ingredientWeight;
}

double getVolume()
{
  // This function gets the weight of the ingredient from the user to convert to volume.  It does the input validation to ensure that the weight is greater than 0 and that the user input doesn't cause input failure. It returns the validated double.

  double ingredientVolume;

  string volumePrompt = "Enter the volume of your ingredient in ml: ";
  cout << volumePrompt << endl;
  cin >> ingredientVolume;

  while (!cin || ingredientVolume <= 0)
  {

    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
    else if (ingredientVolume <= 0)
    {
      cout << "Weight must be greater than 0" << endl;
    }
    cout << volumePrompt << endl;
    cin >> ingredientVolume;
  }

  return ingredientVolume;
}

double convertWeight(double weight, double density)
{
  // Calculate and return the volume needed for the ingredient. formula: volume = weight / density.

  return weight / density;
}

double convertVolume(double volume, double density)
{
  // Calculate and return the weight needed for the ingredient. formula: weight = volume * density.

  return volume * density;
}

int main()
{
  string ingredient = getIngredient();
  cout << "Ingredient: " << ingredient << endl;
  return 0;
}
