#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int k;
    while (k < 1 || k > 6) {cout << "Choose day of the week:" << endl << "1. Monday" << endl << "2. Thuesday" << endl << "3. Wednesday" << endl << "4. Thursday" << endl << "5. Friday" << endl << "6. Saturday" << endl;
    cin >> k;
    }
    switch(k) {
        case 1:
        cout << "Shedule for Monday:" << endl << "2.Physical culture" << endl << "3.Physics" << endl << "4.Physics" << endl << "5.Physics" << endl << "6.Basics of programming";
        break;
        case 2:
        cout << "Shedule for Thuesday:" << endl << "3.Basics of programming" << endl << "4.Basics of programming" << endl << "5.Basics of programming";
        break;
        case 3:
        cout << "Shedule for Wednesday:" << endl << "3.Basics of software engineering" << endl << "4.Basics of programming" << endl << "5.Basics of programming";
        break;
        case 4:
        cout << "Shedule for Thursday:" << endl << "2.English" << endl << "3.History and culture of Ukraine";
        break;
        case 5:
        cout << "Shedule for Friday:" << endl << "2.Higher Math" << endl << "3.Physics" << endl << "4.Higher Math";
        break;
        case 6:
        cout << "No shedule for Saturday :)";
        break;
    }

    return 0;
}