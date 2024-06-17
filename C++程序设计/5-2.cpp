#include <iostream>
using namespace std;

uint8_t s = 1;                      //交换标志位

void sort(int num[]){
    int n;                          //辅助变量
    for(uint8_t i=0;i<10;i++){
        if (num[i] > num[i+1]){
            n = num[i];             
            num[i] = num[i+1];
            num[i+1] = n;
            s = 1;
        }
    }
}

int main(){
    int nums[10];
    cout<< "Please input 10 numbers (Separtate by space):" <<endl;
    for(uint8_t i=0;i<10;i++) scanf("%d",&nums[i]);
    while (s){
        s = 0;
        sort(nums);
    }
    for(uint8_t i=0;i<10;i++){
        cout<<nums[i]<<',';
    }
    return 0;
}
