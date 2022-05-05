#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>

void output(int*, int);
int task(int*, int);

int main() {
    FILE *f;
    f = fopen("C:\\Users\\Su Ming\\Documents\\CODING\\Ырср 9\\task.txt", "r");
    if(f == NULL) {
        std::cout << "Opening error";
        return 1;
    }
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;
    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) matrix[i][j] = 0;
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) fscanf(f, "%d ", &matrix[i][j]);
    }
    output(&matrix[0][0], n);
    if(task(&matrix[0][0], n) == -1 ) std::cout << "\nNo such lines.";
    else std::cout << "\nLine #" << task(&matrix[0][0], n);

    return 0;
}

void output(int *matrix, int n) {
    for(int i = 0; i < n; i++) {
        std::cout << std::endl;
        for(int j = 0; j < n; j++) std::cout << std::setw(4) << *(matrix + i*10 + j);
    }
}

int task(int *matrix, int n) {
    int max = -1, maxp = 0, i;
    for(i = 0; i < n; i++) {
        int p = 0;
        for(int j = 0; j < n; j++) {
            if(!(*(matrix + i*10 + j))) continue;
            if(!(*(matrix + i*10 + j) % (i+1 + j+1))) p++;
        }
        if(p > maxp) maxp = p, max = i+1;
    }

    return max;
}