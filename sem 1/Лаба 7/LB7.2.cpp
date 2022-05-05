#include <iostream>
#include <cstring>

bool Alone(char, char*, int);

int main() {
    std::cout << "Enter a string shorter than 100 symbols: ";
    char str[100], repeat[50];
    int j = 0;
    bool Void = true;
    gets(str);
    std::cout << "\nThose symbols occur only once: ";
    for(int i = 0; str[i]; i++) {
        if(!Alone(str[i], repeat, strlen(repeat))) continue;
        if(Alone(str[i], str, strlen(str))) std::cout << str[i], Void = false;
        else repeat[j++] = str[i], repeat[j++] = str[i];
    }
    if(Void) std::cout << "No such symbols.";

    return 0;
}

bool Alone(char symb, char *str, int size) {
    int count = 0;
    for(int i = 0; str[i]; i++) {
        if(str[i] == symb) {
            count++;
            if(count == 2) return false;
        }
    }

    return true;
}