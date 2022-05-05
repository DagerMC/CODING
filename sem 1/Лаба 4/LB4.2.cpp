#include <iostream>
#include <cmath>
using namespace std;

int sumOfD(int);

int main() {
    int range;
    cout << "Enter range: ";
    cin >> range;
    for(int i = 2, j = 0; i <= range; i++) {
        int sumOfI = sumOfD(i);
        if(i == sumOfD(sumOfI) && i > sumOfI) cout << sumOfI << " & " << i << " | ", j++;
        if(j == 3) cout << endl, j = 0;
    }

    return 0;
}

int sumOfD(int x) {
    int sumD = 0;
    for (int i = 1; i <= x/2; i++) {
        if ((x%i) == 0) sumD += i;
    }

    return sumD;
}