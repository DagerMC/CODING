#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float end, iSum;
    end = 103;
    iSum = end;
    while(end > 1.) {
        iSum = (end - 2) + 1 / iSum;
        end = end - 2;
    }
    cout << "Culculated! Result is: " << 1 / iSum;

    return 0;
}