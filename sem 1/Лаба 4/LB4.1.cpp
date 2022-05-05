#include <iostream>
#include <cmath>
using namespace std;

float min(float, float);
float max(float, float);

int main() {
    float a, b, c, t;
    cout << "Enter a, b, c:";
    cin >> a >> b >> c;

    t = (1 + min(a * c, c * b)) / (max(a, c) + max(a, b));
    cout << "Result is:" << t;

    return 0;
}

float max(float x, float y) {
    if (x > y) return x;
    else return y;
}

float min(float x, float y) {
    if (x < y) return x;
    else return y;
}