#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, x6 = 1, x7 = 1, x8 = 1, x9 = 1, choice;
    while (choice < 1 || choice > 9) {
    cout << "Choose a coin beetwen 1 and 9, and i'll show you how to detect that it is imposter" << endl;
    cin >> choice;
    }
    switch(choice) {
        case 1: x1 = 0; break;
        case 2: x2 = 0; break;
        case 3: x3 = 0; break;
        case 4: x4 = 0; break;
        case 5: x5 = 0; break;
        case 6: x6 = 0; break;
        case 7: x7 = 0; break;
        case 8: x8 = 0; break;
        case 9: x9 = 0; break;
    }
    cout << "Compare 1,2,3 with 4,5,6:" << endl;
    if ((x1 + x2 + x3) == (x4 + x5 + x6)) {
        cout << "They're equal! So the imposter is between 7, 8, 9. Let's compare 7 and 8:" << endl;
        if (x7 < x8) cout << "8 is heavier, so imposter is 7!";
        else if (x7 > x8) cout << "7 is heavier, so imposter is 8!";
        else cout << "They're equal, so imposter is 9!";
    }
    else if ((x1 + x2 + x3) < (x4 + x5 + x6)) {
        cout << "4,5,6 is heavier, so imposter is between 1, 2, 3. Let's compare 1 and 2: " << endl;
        if (x1 > x2) cout << "1 is hevier, so imposter is 2";
        else if (x1 < x2) cout << "2 is heavier, so imposter is 1";
        else cout << "They're equal so imposter is 3!";
    }
    else {
        cout << "1,2,3 is heavier, so imposter is between 4, 5, 6. Let's compare 4 and 5" << endl;
        if (x4 < x5) cout << "5 is heavier, so imposter is 4!";
        else if (x4 > x5) cout << "4 is heavier, so imposter is 5!";
        else cout << "They're equal, so imposter is 6!";
    }

    return 0;
}