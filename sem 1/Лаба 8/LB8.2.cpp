#include <iostream>
#include <iomanip>
#include <C:\Users\Su Ming\Documents\CODING\Ырср 8\LB8.2LIB.h>

void input(table*, int);
void calc(table*, int);
void sort(table*, int);

int main() {
    int num;
    std::cout << "Enter number of elemets: "; 
    std::cin >> num;
    table table[num];
    std::cout << "Fill the table: \n";
    input(table, num);
    calc(table, num);
    sort(table, num);
    std::cout << "Table sorted by Value: \n L | V(0) | t |   V   | V-V(0) |" << std::endl;
    for(int i = 0; i < num; i++) {
        std::cout << std::setw(3) << table[i].L << "|"
                  << std::setw(6) << table[i].V0 << "|"
                  << std::setw(3) << table[i].t << "|"
                  << std::setw(7) << table[i].V << "|"
                  << std::setw(8) << table[i].difference << "|\n";
    }   

    return 0;
}