#include <iostream>
#include <math.h>
using namespace std;

int main() {
    for(int i = 1; i <= 12; i++) {
        int Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30, Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31;
        int cMD; //currentMonthDays
        switch(i) {
            case 1:
            cout << "\n          January: " << 2021 << endl;
            cMD = Jan;
            break;
            case 2:
            cout << "\n          February: " << 2021 << endl;
            cMD = Feb;
            break;
            case 3:
            cout << "\n          March: " << 2021 << endl;
            cMD = Mar;
            break;
            case 4:
            cout << "\n          April: " << 2021 << endl;
            cMD = Apr;
            break;
            case 5:
            cout << "\n          May: " << 2021 << endl;
            cMD = May;
            break;
            case 6:
            cout << "\n          June: " << 2021 << endl;
            cMD = Jun;
            break;
            case 7:
            cout << "\n          July: " << 2021 << endl;
            cMD = Jul;
            break;
            case 8:
            cout << "\n          August: " << 2021 << endl;
            cMD = Aug;
            break;
            case 9:
            cout << "\n          September: " << 2021 << endl;
            cMD = Sep;
            break;
            case 10:
            cout << "\n          October: " << 2021 << endl;
            cMD = Oct;
            break;
            case 11:
            cout << "\n          November: " << 2021 << endl;
            cMD = Nov;
            break;
            case 12:
            cout << "\n          December: " << 2021 << endl;
            cMD = Dec;
            break;
        }
        int start, end;
        if (i == 1) start = 5;
        else if (end > 7) start = 1;
        else start = end;
        cout << "Mon |Tue |Wed |Thu |Fri |Sat |Sun |\n";
        end = start;
        switch(start) {
            case 2: cout << "    |"; 
            break;
            case 3: cout << "    |    |";
            break;
            case 4: cout << "    |    |    |";
            break;
            case 5: cout << "    |    |    |    |";
            break;
            case 6: cout << "    |    |    |    |    |";
            break;
            case 7: cout << "    |    |    |    |    |    |";
            break;
        }
        for (int d = 1; d <= cMD; d++, end++) {
            if (end > 7) cout << endl, end = 1;
            if (d < 10) cout << " " << d << "  |";
            else cout << " " << d << " |";
        }
    }
    return 0;
}