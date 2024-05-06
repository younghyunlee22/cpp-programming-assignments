
/*
The outer loop does in each iteration:
  1. It takes the first element of the currently unsorted list as the starting point.
  2. The inner loop is used to find the smallest element among those that follow the current first element.
  3. Once the smallest element is identified, it is swapped with the current first element.
This process is repeated until the entire list is sorted.

Inner loop: in the unsorted portion of the list:
  a. Find the location of the smallest element.
  b. Move the smallest element to the beginning of the unsorted list.

  for (index = 0; index < length - 1; index++)
  {
    a. Find the location (smallestIndex) of the smallest element in the unsorted section of the list, starting from index to the end of the list.
    b. Swap the element at list[smallestIndex] with list[index]. The element list[index] is currently the first element in the unsorted section and will be the position where the smallest element found is placed.
  }

  The general form of Step a is:

  smallestIndex = index; // assume the first element is the smallest

  for (location = index + 1; location < length; location++)
  {
    if (list[location] < list[smallestIndex]) // current element vs the smallest so far
    {
      smallestIndex = location; // update the location of the smallest element
    }
  }

  Step b:
    temp = list[smallestIndex]; // store the smallest element in the unsorted section in temp
    list[smallestIndex] = list[index]; // move it to the top of the unsorted section
    list[index] = temp; // current element is now the next smallest element

Selection sort algorithm:
  1. Start at the beginning of the unsorted section of the list.
  2. Find the smallest item in the unsorted part of the list.
  3. Swap the smallest item found with the first item in the unsorted part of the list.
  4. Move the boundary of the sorted section of the list one item forward (i.e., shrink the unsorted part).
  Repeat steps 1-4 until the entire list is sorted.
*/

#include <iostream>

using namespace std;

void selectionSort(int list[], int length)
{
  int index;
  int smallestIndex;
  int location;
  int temp;

  for (index = 0; index < length - 1; index++)
  {
    // Initialize smallestIndex at the start of the unsorted section
    smallestIndex = index;

    // Step a: Find the index of the smallest element in the unsorted section
    for (location = index + 1; location < length; location++)
    {
      if (list[location] < list[smallestIndex])
      {
        smallestIndex = location;
      }
    }

    // Step b: Swap the found smallest element with the first element in the unsorted section
    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
  }
}

int main()
{

  int list[8] = {16, 30, 24, 7, 62, 45, 5, 55};
  selectionSort(list, 8);

  for (int i = 0; i < 8; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;

  return 0;
}