#include <iostream>
using namespace std;

int num;

void num_off(int index[]){
    for(int i=0;i<num-1;i++){
        int current = 1;
        for(int j=0;j<num;j++){
            
            if(current==3){
                index[j] = 0;
                break;
            }
        }
    }
    for(int i=0;i<num;i++){
        if(index[i] != 0) cout<<"最后留下的人原来排在第"<<i+1<<"排"<<endl;
    }
}

int main(){
    cout<<"请输入人数：";
    cin>>num;
    int index[num];
    for(int i=0;i<num;i++){
        index[i]=i+1;
    }
    num_off(index);
    return 0;
}
