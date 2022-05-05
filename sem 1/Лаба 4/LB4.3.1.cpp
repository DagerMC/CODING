#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int sumOfDigits(int);

int main() {
    unsigned int k, s, count = 0, start_time = clock();
    cout << "Enter k, s: ";
    cin >> k >> s;
    for (int i = pow(10, (k - 1)); i < pow(10, k); i++) {
        if (sumOfDigits(i) == s) count++;
    }
    switch(count) {
        case 0:
        cout << "There are no such numbers";
        break;
        case 1:
        cout << "There is 1 such number";
        break;
        default:
        cout << "There are " << count << " such numbers";
    }
    unsigned int end_time = clock();
    cout << "\n Execution time:" << (end_time - start_time)/CLK_TCK << " seconds.";

    return 0;
}

int sumOfDigits(int x) {
    int sum = 0;
    while(x >= 1) {
        sum += x%10;
        x /= 10;
    }

    return sum;
}