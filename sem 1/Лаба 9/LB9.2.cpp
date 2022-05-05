#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

struct materia{
    char name[20];
    int specificWeight;
    char type;
};

void task1(FILE*, int);
void task2(FILE*, int);

int main() {
    std::cout << "Enter number of elements: ";
    int num;
    std::cin >> num;
    FILE *f;
    f = fopen("task2.txt", "wb");
    materia material;
    for(int i = 0; i < num; i++) {
        std::cout << "Enter name: ";
        std::cin >> material.name;
        std::cout << "Enter specific weight: ";
        std::cin >> material.specificWeight;
        std::cout << "Enter type. C - conductor, S - semiconductor, I - insulator: ";
        std::cin >> material.type;
        fwrite(&material, sizeof(material), 1, f);
    }
    fclose(f);
    task1(f, num);
    task2(f, num);

    return 0;
}

void task1(FILE *f, int n) {
    f = fopen("task2.txt", "rb");
    if(f == NULL) {
        std::cout << "Opening error #2";
        exit(1);
    }
    materia materials[n], material;
    int i = 0;
    for(int j = 0; j < n; j++) {
      fread(&material, sizeof(material), 1, f);
      if(material.type == 'S') materials[i++] = material; 
    }
    for(int j = 1; j < i; j++) {
        for(int r = 0; r < i-j; r++) {
            if((int)materials[r].name[0] > (int)materials[r+1].name[0]) {
                materia temp = materials[r];
                materials[r] = materials[r+1];
                materials[r+1] = temp;
            }
        }
    }
    std::cout << "\nSemiconductors: ";
    for(int j = 0; j < i; j++) {
        std::cout << "\nName: " << materials[j].name;
        std::cout << "\nSpecific Weight: " << materials[j].specificWeight;
    }
    fclose(f);
}

void task2(FILE *f, int n) {
    f = fopen("task2.txt", "rb");
    if(f == NULL) {
        std::cout << "Opening error #2";
        exit(1);
    }
    materia materials[n], material;
    int i = 0;
    for(int j = 0; j < n; j++) {
      fread(&material, sizeof(material), 1, f);
      if(material.type == 'C') materials[i++] = material; 
    }
    for(int j = 1; j < i; j++) {
        for(int r = 0; r < i-j; r++) {
            if(materials[r].specificWeight > materials[r+1].specificWeight) {
                materia temp = materials[r];
                materials[r] = materials[r+1];
                materials[r+1] = temp;
            }
        }
    }
    std::cout << "\nConductors: ";
    for(int j = 0; j < i; j++) {
        std::cout << "\nName: " << materials[j].name;
        std::cout << "\nSpecific Weight: " << materials[j].specificWeight;
    }
    fclose(f);
}