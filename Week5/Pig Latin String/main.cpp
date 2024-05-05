#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch)
{
  // This function would check if a character is a vowel.

  switch (ch)
  {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'y':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'Y':
    return true;
  default:
    return false;
  }
}

string rotate(string pStr)
{
  string::size_type len = pStr.length();
  string rStr;
  rStr = pStr.substr(1, len - 1) + pStr[0];

  return rStr;
}

std::string pigLatinString(std::string pStr)
{
  std::string::size_type len;
  bool foundVowel;
  std::string::size_type counter;

  if (isVowel(pStr[0]))
  {
    pStr = pStr + "-way"; // Step 2
  }
  else
  {
    pStr = pStr + '-';   // Step 3
    pStr = rotate(pStr); // Step 3

    len = pStr.length(); // Step 3.a
    foundVowel = false;  // Step 3.b

    for (counter = 1; counter < len - 1; counter++)
    { // Step 3.d
      if (isVowel(pStr[0]))
      {
        foundVowel = true;
        break;
      }
      else
      {
        cout << "before rotation: " << pStr << endl;
        pStr = rotate(pStr); // Step 3.c
        cout << "after rotation: " << pStr << endl;
      }
    }

    if (!foundVowel)
    {
      cout << "No vowel found. Current pStr: " << pStr << endl;
      pStr = pStr.substr(1, len) + "-way"; // Step 4
    }
    else
    {
      pStr = pStr + "ay"; // Step 5
    }
  }

  return pStr;
}

int main()
{
  string str;

  cout << "Enter a string: ";
  cin >> str;
  cout << endl;

  cout << "The pig Latin form of " << str << " is: " << pigLatinString(str) << endl;
  return 0;
}