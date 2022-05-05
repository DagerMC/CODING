#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    float v1, v2, t1 = 1.2, t2 = 0.5;
    v1 = (3 - (30 * t2)) / (t2 - (t1 + t2));
    v2 = v1 + 30;
    printf("Speed = %f", v2);

    return 0;
}