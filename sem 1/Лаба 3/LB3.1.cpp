#include <iostream>
#include <math.h>
using namespace std;

int main() {
    for(int i = 100; i <= 987; i++) {
        int a, b, c;
        a = i % 10;
        b = (i/10) % 10;
        c = i/100;
        if (a == b || b == c || a == c) continue;
        cout << i << ", ";
    }
    
    return 0;
}