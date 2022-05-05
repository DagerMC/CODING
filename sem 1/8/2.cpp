#include<iomanip>
#include<iostream>
#include<conio.h>
using namespace std;

struct flight {
    int n;
    char T[10];
    char R[10];
    float Z;
    int K;
    float S;
};

void inputSort(flight*, int);

int main() {
    cout<<"enter number of flights ";
    int num;
    cin>>num;
    flight flights[num];
    inputSort(flights, num);
    cout<<" # |  Type  |  Race  |  Z  |  K  |  S  |";
    for(int i=0; i<num;i++) {
        cout<<"\n"<<setw(4)<<flights[i].n<<setw(9)<<flights[i].T<<setw(9)<<flights[i].R<<setw(6)<<flights[i].Z<<setw(6)<<setw(6)<<flights[i].Z<<setw(6)<<flights[i].S;
    }
    cout<<"\nthose races is calculated incorrect: ";
    for(int i=0; i<num; i++) {
        if(flights[i].Z/flights[i].K != flights[i].S) cout<<" #"<<flights[i].n;
    }
    getch();

    return 0;
}

void inputSort(flight *fl, int num) {
    for(int i=0; i<num; i++) {
        cout<<"enter num, T, R, Z, K, S ";
        cin>>fl[i].n>>fl[i].T>>fl[i].R>>fl[i].Z>>fl[i].K>>fl[i].S;
    }
    for(int i = 1; i < num; ++i) {
        for(int r = 0; r < num-i; r++) {
            if(fl[r].S < fl[r+1].S) {
                flight temp = fl[r];
                fl[r] = fl[r+1];
                fl[r+1] = temp;
            }
        }
    }
}