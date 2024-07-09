#include <iostream>
#include <string>
using namespace std;

/*字符数组形式*/
/*
char str[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void arr_useing(){
    int index = 0;
    char str_in;
    while((str_in = getchar()) != '\n'){
        str[index] = str_in;
        index++;
    }
    for(int i=15;i>=0;i--){
        if(str[i] != 0) cout<< str[i];
    }
}*/

/*string方法形式*/
void str_useing(){
    string str;
    cin>> str;
    for(int i=str.size()-1;i>=0;i--){
        cout<< str[i];
    }
}

int main(){
    cout<< "请输入一个字符串：" <<endl;
    //arr_useing();
    str_useing();
    return 0;
}