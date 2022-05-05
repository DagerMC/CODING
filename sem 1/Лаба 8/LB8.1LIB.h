#include <cstring>
#include <iostream>

struct flight {
    int id;
    char name[50];
    char type[10];
    int price;
    int distance;
};

void input(flight* flight, int num) {
    for(int i = 0; i < num; i++) {
        std::cout << "\nFlight number #" << i+1 << "\nEnter id of flight:";
        std::cin >> flight[i].id;
        std::cout << "Enter name of flight: ";
        std::cin >> flight[i].name;
        std::cout << "Enter type of plane: ";
        std::cin >> flight[i].type;
        std::cout << "Enter price of ticket in UAH: ";
        std::cin >> flight[i].price;
        std::cout << "Enter distance of flight in kilometers: ";
        std::cin >> flight[i].distance;
    }
}

void sortById(flight *fligh, int num) {
    for(int i = 1; i < num; ++i) {
        for(int r = 0; r < num-i; r++) {
            if(fligh[r].id < fligh[r+1].id) {
                flight temp = fligh[r];
                fligh[r] = fligh[r+1];
                fligh[r+1] = temp;
            }
        }
    }
}