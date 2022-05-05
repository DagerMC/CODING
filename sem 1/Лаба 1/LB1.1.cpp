#include <stdio.h>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main() {
    float x, y, a;
    printf ("Enter x and y: ");
    scanf("%f%f",&x,&y);
    a = x - pow(x,2) / (1 + pow(sin(abs(x + y)*(PI/180)),2)) + (pow(x,2) + pow(y,2)) / (1-(pow(x,2) - pow(y,2)) / (2*x)); 
    printf ("a = %f", a);
    return 0;
}