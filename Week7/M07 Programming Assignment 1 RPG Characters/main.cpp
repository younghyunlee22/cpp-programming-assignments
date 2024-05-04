// what do I need to keep track of?
//
// when does the loop end?

// userInputCout reaches 10 or when the user wants to stop creating characters (userInput == 'n')
// these should be updated properly

// while (userInputCount < 10 && userInput == 'y') {

// ask the name and character class that the user wants
// call the fuction that creates the instance of characterType and store the return value

// }

/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 5/1/2024
 * Purpose: RPG Characters
 */

#include <iostream>
#include <string>
#include <cctype> // For tolower function

using namespace std;

// Creating an enum
enum characterClassType
{
  FIGHT,
  ROGUE,
  MAGIC,
  CLERIC
};

// Creating a struct
struct characterType
{
  string name;
  double hp;
  double mp;
  int strength;
  int dexterity;
  int intelligence;
  int speed;
  int endurance;
  int faith;
  characterClassType characterClass;
};

characterType createCharacter(const string &name, characterClassType characterClassEnum)
{
  characterType newCharacter;

  // Set the name and class
  newCharacter.name = name;
  newCharacter.characterClass = characterClassEnum;

  // Set the stats based on the character class
  switch (characterClassEnum)
  {
  case FIGHT:
    newCharacter.hp = 30;
    newCharacter.mp = 0;
    newCharacter.strength = 16;
    newCharacter.dexterity = 10;
    newCharacter.intelligence = 5;
    newCharacter.speed = 8;
    newCharacter.endurance = 15;
    newCharacter.faith = 5;
    break;

  case ROGUE:
    newCharacter.hp = 20;
    newCharacter.mp = 0;
    newCharacter.strength = 10;
    newCharacter.dexterity = 16;
    newCharacter.intelligence = 16;
    newCharacter.speed = 15;
    newCharacter.endurance = 8;
    newCharacter.faith = 5;
    break;

  case MAGIC:
    newCharacter.hp = 25;
    newCharacter.mp = 20;
    newCharacter.strength = 5;
    newCharacter.dexterity = 10;
    newCharacter.intelligence = 16;
    newCharacter.speed = 16;
    newCharacter.endurance = 5;
    newCharacter.faith = 8;
    break;

  case CLERIC:
    newCharacter.hp = 20;
    newCharacter.mp = 20;
    newCharacter.strength = 5;
    newCharacter.dexterity = 10;
    newCharacter.intelligence = 8;
    newCharacter.speed = 16;
    newCharacter.endurance = 5;
    newCharacter.faith = 16;
    break;
  }
  return newCharacter;
}

// Function to choose the character class
characterClassType chooseCharacter()
{

  characterClassType characterClassEnum;
  int characterClassNum;

  cout << "1. Fighter Class" << endl;
  cout << "2. Rogue Class" << endl;
  cout << "3. Magician Class" << endl;
  cout << "4. Cleric Class" << endl;

  cin >> characterClassNum;

  while (!cin || characterClassNum < 1 || characterClassNum > 4)
  {
    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }

    cout << "That is not a valid choice. Please choose the class by number from the list." << endl;
    cin >> characterClassNum;
  }

  switch (characterClassNum)
  {
  case 1:
    characterClassEnum = FIGHT;
    break;
  case 2:
    characterClassEnum = ROGUE;
    break;
  case 3:
    characterClassEnum = MAGIC;
    break;
  case 4:
    characterClassEnum = CLERIC;
    break;
  }

  return characterClassEnum;
}

// Function to print the character class in string
void printCharacterClass(characterClassType characterClassEnum)
{
  switch (characterClassEnum)
  {
  case FIGHT:
    cout << "Fighter stats:" << endl;
    break;
  case ROGUE:
    cout << "Rogue stats:" << endl;
    break;
  case MAGIC:
    cout << "Magician stats:" << endl;
    break;
  case CLERIC:
    cout << "Cleric stats:" << endl;
    break;
  }
}

// Function to display the character
void displayCharacter(const characterType &character)
{
  cout << character.name << " the ";
  printCharacterClass(character.characterClass);
  cout << "HP: " << character.hp << endl
       << "MP: " << character.mp << endl
       << "Strength: " << character.strength << endl
       << "Dexterity: " << character.dexterity << endl
       << "Intelligence: " << character.intelligence << endl
       << "Speed: " << character.speed << endl
       << "Endurance: " << character.endurance << endl
       << "Faith: " << character.faith << endl;
}

int main()
{
  characterType characters[10]; // Array to store the characters
  int characterCount = 0;
  char userInput;

  cout << "Welcome to the Character Creator!" << endl;

  do
  {
    string characterName;
    characterClassType characterClass;

    cout << "What is your character's name: " << endl;
    getline(cin, characterName);

    cout << "What character class do you want " << characterName << " to be?" << endl;
    characterClass = chooseCharacter();

    characters[characterCount++] = createCharacter(characterName, characterClass);

    cout << "Do you want to create another character (y or n)? ";
    cin >> userInput;
    cin.ignore(100, '\n');
    userInput = tolower(userInput);

    if (characterCount >= 10)
    {
      cout << "You have entered the max number of characters. The program will now exit." << endl;
      break;
    }

    while (userInput != 'y' && userInput != 'n') // Validate the input
    {
      cout << "Invalid input. Please enter 'y' to continue or 'n' to stop: ";
      cin >> userInput;
      cin.ignore(100, '\n');
      userInput = tolower(userInput);
    }
  } while (userInput == 'y');

  cout << "Here are the characters you created:" << endl;
  for (int i = 0; i < characterCount; i++)
  {
    displayCharacter(characters[i]);
  }

  return 0;
}