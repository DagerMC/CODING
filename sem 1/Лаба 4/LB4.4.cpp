#include <iostream>
#include <cmath>
using namespace std;

float Area(float);
float Area(float, float);
float Area(float, float, float);

int main() {
    float a, b, c, pi = 3.14159;
    cout << "Enter lenth of a square: ";
    cin >> a;
    cout << "Area of a square = " << Area(a) << "\nEnter radius of a circle: ";
    cin >> b;
    cout << "Area of a circle = " << Area(pi, b) << "\nEnter sides of a triangle: ";
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a) cout << "There is no such triangle.";
    else cout << "Area if a triangle =" << Area(a, b, c);

    return 0;
}

float Area(float x) {
    return x * x;
}

float Area(float pi, float x) {
    return pi * x * x;
}

float Area(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}