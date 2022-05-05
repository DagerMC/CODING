#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

void input(float*, int, int); //Заповнення матриці випадковими числами
void show(float*, int, int); //Вивід матриці
void remove(float*, int, int, int); //Видалити певний стовпець матриці
bool cMP(float*, int, int); //Визначити чи має цей рядок більше позитивних чисел ніж негативних, contain More Positive

int main() {
    int n, m, k;
    bool Contain = false;
    cout << "Enter size of matrix, n*m: ";
    cin >> n >> m;
    float matrix[n][m];
    cout << "Fill matrix with numbers: ";
    input(&matrix[0][0], n, m);
    cout << "Your matrix: \n";
    show(&matrix[0][0], n, m);
    cout << "Which collum will we remove?";
    cin >> k;
    remove(&matrix[0][0], n, m, k);
    cout << "Your matrix now: \n";
    show(&matrix[0][0], n, m);
    cout << "Those lines contains more positive numbers than negative: ";
    for(int i = 0; i < n; i++) {
        if(cMP(&matrix[0][0], i, m)) cout << i + 1 << " ", Contain = true;
    }
    if(!Contain) cout << "No such lines";

    return 0;
}

void input(float *start, int n, int m) {
    srand(time(0));
    int size = n * m;
    for(int i = 0; i < size; i++, start++) *start = rand()%19 - 9;
}

void show(float *start, int n, int m) {
    int size = n * m, j = 0;
    for(int i = 0; i < size; i++, start++) {
        if(*start >= 0) cout << " " << *start << " ";
        else cout << *start << " ";
        j++;
        if(j == m) cout << "\n", j = 0;
    }
}

void remove(float *start, int n, int m, int k) {
    start += k - 1;
    for(int i = 0; i < n; i++, start += m) {
        *start = 0;
    }
}

bool cMP(float *start, int n, int m) {
    start += n * m;
    int P = 0, N = 0; //Positive - Negative
    for(int i = 0; i < m; i++, start++) {
        if(*start > 0) P++;
        else if(*start < 0) N++;
    }
    if(P > N) return true;
    return false;
}