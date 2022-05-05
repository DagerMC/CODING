#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float x, y;
    cout << "Enter coordinates x and y of a point: " << endl;
    cin >> x >> y;
    if ( x > 1 || x < -1) {
        if ( y >= 1) cout << "Belongs";
        else cout << "Not belongs";
    }
    else {
        if (abs(x) <= y) cout << "Belongs";
        else cout << "Not belongs";
    }

    return 0;
}