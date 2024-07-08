#include <iostream>
using namespace std;

double list(int i){                 //求解斐波那契数列
    double value;
    if(i==0 || i==1) value = 1;
    else value = list(i-1)+list(i-2);
    return value;
}

int main(){
    double sum = 0.0;
    int i;
    for(i=1;i<21;i++){
        sum = sum + (list(i+1)/list(i));
    }
    cout<<"sum = "<< sum <<endl;
    return 0;
}
