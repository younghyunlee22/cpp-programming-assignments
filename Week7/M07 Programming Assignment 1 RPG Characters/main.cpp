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

using namespace std;

enum characterClassType
{
  FIGHT,
  ROGUE,
  MAGIC,
  CLERIC
};

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

characterClassType chooseCharacter(int characterClass)
{

  characterClassType characterClassEnum;
  int characterClassNum;

  cout << "1. Fighter" << endl;
  cout << "2. Rogue" << endl;
  cout << "3. Magic" << endl;
  cout << "4. Cleric" << endl;

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

void printCharacterClass(characterClassType characterClassEnum)
{
  switch (characterClassEnum)
  {
  case FIGHT:
    cout << "Fighter" << endl;
    break;
  case ROGUE:
    cout << "Rogue" << endl;
    break;
  case MAGIC:
    cout << "Magician" << endl;
    break;
  case CLERIC:
    cout << "Cleric" << endl;
    break;
  }
}

int main()
{

  string characterName;
  int characterClassNum;
  characterClassType characterClass;

  cout << "Welcome to the Character Creator!" << endl;

  cout << "What is your character's name: " << endl;
  cin >> characterName;
  cout << "What character class do you want " << characterName << " to be?" << endl;
  characterClass = chooseCharacter(characterClassNum);
  printCharacterClass(characterClass);

  return 0;
}