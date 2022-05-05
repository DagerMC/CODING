#include <iostream>
#include <cmath>
using namespace std;

void decomp(int);
void decomp(int&, int);
void decomp(int*);


int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    int _num = num;
    cout << "\n 1. \n" << num << " = ";
    decomp(num);
    cout << "\n 2. \n" << num << " = ";
    decomp(num, 0);
    cout << "\n num now equal to " << num;
    cout << "\n 3. \n" << _num << " = ";
    decomp(&_num);
    cout << "\n _num now equal tu " << _num;

    return 0;
}

void decomp(int x) {
    bool FirstPair = true;
    int b;

    for(int i = 2; i <= sqrt(x); i++) {
        if(!(x%i)) {
            if((x/i)%i == 0) {
                for(b = 0; x%i == 0; b++) x /= i;
            }
            if(FirstPair) {
                cout << i;
                if(b) cout << "^" << b, b = 0;
                if(x%i == 0) x /= i;
                FirstPair = false;
                i = 1;
                continue;
            }
            cout << " * " << i;
            if(b) cout << "^" << b, b = 0;
            if(x%i == 0) x /= i;
            i = 1;
        }
    }

    if(x != 1) cout << " * " << x;
}

void decomp(int *x) {
    bool FirstPair = true;
    int b;

    for(int i = 2; i <= sqrt(*x); i++) {
        if(!(*x%i)) {
            if((*x/i)%i == 0) {
                for(b = 0; *x%i == 0; b++) *x /= i;
            }
            if(FirstPair) {
                cout << i;
                if(b) cout << "^" << b, b = 0;
                if(*x%i == 0) *x /= i;
                FirstPair = false;
                i = 1;
                continue;
            }
            cout << " * " << i;
            if(b) cout << "^" << b, b = 0;
            if(*x%i == 0) *x /= i;
            i = 1;
        }
    }

    if(*x != 1) cout << " * " << *x;
}

void decomp(int &x, int c) {
    bool FirstPair = true;
    int b;

    for(int i = 2; i <= sqrt(x); i++) {
        if(!(x%i)) {
            if((x/i)%i == 0) {
                for(b = 0; x%i == 0; b++) x /= i;
            }
            if(FirstPair) {
                cout << i;
                if(b) cout << "^" << b, b = 0;
                if(x%i == 0) x /= i;
                FirstPair = false;
                i = 1;
                continue;
            }
            cout << " * " << i;
            if(b) cout << "^" << b, b = 0;
            if(x%i == 0) x /= i;
            i = 1;
        }
    }

    if(x != 1) cout << " * " << x;
}