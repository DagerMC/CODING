#include <cstring>
#include <iostream>
#include <C:\Users\Su Ming\Documents\CODING\Ырср 8\LB8.1LIB.h>

void input(flight*, int);
void sortById(flight*, int);

int main() {
    std::cout << "Enter number of flights: ";
    int num, distance;
    std::cin >> num;
    flight flights[num];
    input(flights, num);
    std::cout << "\nEnter a distance to filter: ";
    std::cin >> distance;
    sortById(flights, num);
    std::cout << "Those flights have distance longer that you entered: ";
    for(int i = 0; i < num; i++) {
        if(flights[i].distance >= distance) {
            std::cout << "\n    .Flight id:" << flights[i].id;
        }
    }

    return 0;
}