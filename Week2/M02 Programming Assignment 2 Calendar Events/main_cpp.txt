#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    Table Heading
    /*output file*/ << left;
    /*output file*/ << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ << setfill(' ');
    /*output file*/<< "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    /*output file*/ << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ << setfill(' ');

    
    return 0;
}