#include "LinkedList.h"
#include <iostream>
using namespace std;


int main() {
    cout << "Enter amount of numbers ";
    int num;
    cin >> num;
    int numbers[num];
    cout << "Enter numbers ";
    for(int i = 0; i < num; i++) {
        cin >> numbers[i];
    }
    List list(numbers, num);
    list.push_back(5);
    list.push_back(5);
    list.insert(10, 2);
    list.print();
    cout << list.locate(10) << "\n";
    list.delete_(10);
    list.print();

    return 0;
}