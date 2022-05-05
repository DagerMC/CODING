#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

bool isBin(char*, int);
long long unsigned int toDec(char*, int);

int main() {
    int len, dec;
    char num[50];
    bool Bin;
    do {
        cout << "Enter a number: ";
        gets(num);
        len = strlen(num);
        Bin = isBin(num, len);
    } while(!Bin);
    dec = toDec(num, len);
    cout << "Your number in dec system: " << dec;

    return 0;
}

bool isBin(char *str, int len) {
    int bin = strspn(str, "01");
    if(bin == len) return true;
    return false;
}

long long unsigned int toDec(char *str, int len) {
    long long unsigned int Dec = 0;
    for(int i = 0; str[i]; i++) {
        if(str[i] == '1') Dec += (int)pow(2, len - i - 1);
    }
    
    return Dec;
}