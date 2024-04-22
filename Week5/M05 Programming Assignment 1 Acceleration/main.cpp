/* Program name: main.cpp
 *  Author: Younghyun Lee
 *  Date last updated: 4/22/2024
 * Purpose: Acceleration
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double speedDueToAcceleration(double acceleration, int time)
{

  double speed = 0.0;
  speed = acceleration * time;

  return speed;
}

double accelerationFromButton(double buttonForce)
{
  double acceleration = 0.0;
  acceleration = buttonForce * 0.463;

  return acceleration;
}

int main()
{

  double buttonForce = 0.0;
  string buttonForcePrompt = "Enter the button force between 0 and 10: ";
  double acceleration = 0.0;

  cout << buttonForcePrompt << endl;
  cin >> buttonForce;
  while (!cin || buttonForce < 0 || buttonForce > 10)
  {
    // Input validation. the button force is between 0 and 10
    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      // Clear the input failure
      cin.clear();
      cin.ignore(100, '\n');
    }
    else
    {
      cout << "The button force needs to be between 0 and 10." << endl;
    }

    cout << buttonForcePrompt << endl;
    cin >> buttonForce;
  }

  // Computation of accelaretion with valid input.
  acceleration = accelerationFromButton(buttonForce);

  int time = 0;
  string accelerationTimePrompt = "Enter the total acceleration time in seconds: ";
  cout << accelerationTimePrompt << endl;
  cin >> time;

  while (!cin || time <= 0)
  {
    // Input validation. the total time is greater than 0.
    if (!cin)
    {
      cout << "You entered something that is not a number. Please Try again." << endl;
      // Clear the input failure
      cin.clear();
      cin.ignore(100, '\n');
    }

    else
    {
      cout << "The total acceleration time must be greater than 0." << endl;
    }

    cout << accelerationTimePrompt << endl;
    cin >> time;
  }

  // Output
  cout << "Acceleration is " << fixed << setprecision(3) << acceleration << " m/s^2" << endl;
  cout << left << setw(15) << "Time in s" << setw(15) << "Speed in m/s" << endl;
  cout << setw(30) << setfill('*') << "*" << endl;
  cout << setfill(' ');

  // Computation of speed with valid input.
  // Compute speed for every three seconds
  for (int i = 0; i <= time; i += 3)
  {

    cout << setw(15) << i << setw(15) << speedDueToAcceleration(acceleration, i) << endl;
  }

  // The time entered by the user is the final value shown in the table
  cout << setw(15) << time << setw(15) << speedDueToAcceleration(acceleration, time) << endl;

  return 0;
}