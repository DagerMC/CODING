#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
using namespace std;

void input(float*, int); //Заповнення масиву випадковими числами
void show(float*, int); //Вивід масиву

int main() {
    int n;
    cout << "Enter amount of numbers: ";
    cin >> n;
    float sequence[n];
    input(sequence, n);
    cout << "Your sequence is: ";
    show(sequence, n);

    return 0;
}

void input(float *start, int len) {
    srand(time(0));
    for(int i = 0; i < len; i++) start[i] = rand()%10;
}

void show(float *start, int len) {
    for(int i = 0; i < len; i++) cout << start[i] << " ";
}