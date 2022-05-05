#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
    float C, R, S;
    printf("Enter lenght of a circle: ");
    scanf("%f", &C);
    R = C / (2*PI);
    S = ((3 * sqrt(3))/ 2) * pow(R, 2);
    printf("Area is: %f", S);

    return 0;
}