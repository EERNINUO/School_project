#include <iostream>
using namespace std;

int fuc(int n){
    if(n == 1) return 1;
    else return fuc(n-1) + n*n;
}

int main(){
    int n;
    cout<< "Please input a number: ";
    cin>> n;
    cout<< fuc(n);
    return 0;
}
