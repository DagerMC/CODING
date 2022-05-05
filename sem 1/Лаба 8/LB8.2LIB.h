#include <iostream>
#include <cmath>

struct table {
    float L;
    float V0;
    float t;
    float V;
    float difference;
};

void input(table *table, int num) {
    for(int i = 0; i < num; i++) {
        std::cout << "  .L" << i+1 << ",t" << i+1 << " = ";
        std::cin >> table[i].L >> table[i].t;
    }
}

void calc(table *table, int num) {
    const float a = 1.2 * pow(10, -5);
    for(int i = 0; i < num; i++) {
        table[i].V0 = pow(table[i].L, 3);
        table[i].V = table[i].V0*(1 + 3*a*table[i].t + 3*pow(a*table[i].t, 2) + pow(a*table[i].t, 3));
        table[i].difference = table[i].V - table[i].V0;
    }
}

void sort(table *tables, int num) {
    for(int i = 1; i < num; ++i) {
        for(int r = 0; r < num-i; r++) {
            if(tables[r].V < tables[r+1].V) {
                table temp = tables[r];
                tables[r] = tables[r+1];
                tables[r+1] = temp;
            }
        }
    }
}