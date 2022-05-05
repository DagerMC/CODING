#include<cmath>
#include<iostream>
#include<conio.h>
using namespace std;

struct man
{
    char surname[10];
    int year;
    int millitary;
};

void input(man*, int);

int main()
{
    const int n=16;
    man mans[n];
    input(mans, n);
    int i, years=10000, index=0;
    for(i=0; i<n; i++) {
        if(mans[i].millitary==1&&mans[i].year < years) index=i, years=mans[i].year;
    }
    cout<<"\nyoungest millitary: "<<mans[index].surname;
    years=0;
    for(i=0; i<n; i++) {
        if(mans[i].millitary==1&&mans[i].year > years) index=i, years=mans[i].year;
    }
    cout<<"\noldest millitary: "<<mans[index].surname;
    years=0;
    for(i=0; i<n; i++) {
        if(!mans[i].millitary==1&&mans[i].year > years) index=i, years=mans[i].year;
    }
    cout<<"\noldest non-millitary: "<<mans[index].surname;
    for(int j = 1; j < n; ++j) {
        for(int r = 0; r < n-j; r++) {
            if((int)mans[r].surname[0] > (int)mans[r+1].surname[0]) {
                man temp = mans[r];
                mans[r] = mans[r+1];
                mans[r+1] = temp;
            }
        }
    }
    cout<<"\nsorted ";
    for(int j=0; j<n; j++){
        cout<<"\n"<<mans[j].surname;
    }
    getch();

    return 0;
}

void input(man *mans, int n) 
{
    cout<<"Enter 16 surnames ";
    for(int i=0; i<n; i++) {
        cin>>mans[i].surname;
    }
    cout<<"Enter 16 years ";
    for(int i=0; i<n; i++) {
        cin>>mans[i].year;
    }
    cout<<"Enter 16 millitarys(1-Yes, 0-No) ";
    for(int i=0; i<n; i++) {
        cin>>mans[i].millitary;
    }
}