/*********************************************
*
* The  GNU GENERAL PUBLIC LICENSE (GPL) v3.0
* Copyright EERNIINUO
* which is available at https://github.com/EERNINUO/School_project/C++/
* All rights reserved.
*
*********************************************/

#include <iostream>             //包含标准输入输出头文件
#include <string>               //包含字符串操作头文件
using namespace std;            //使用命名空间std

/*字符数组形式*/
/*
char str[16] = {0,0,0,0,       //创建字符串数组，初始化全部为空
                0,0,0,0,
                0,0,0,0,
                0,0,0,0};
void arr_useing(){              //使用字符数组方法操作
    int index = 0;              //字符数组索引
    char str_in;                //暂存输入字符
    while((str_in = getchar()) != '\n'){    //检测输入是否结束
        str[index] = str_in;                //赋值对应数组元素
        index++;                            //索引+1
    }
    for(int i=15;i>=0;i--){                 //遍历字符数组str的每个字符
        if(str[i] != 0) cout<< str[i];      //输出字符数组str的每个字符
    }
}*/

/*string方法形式*/
void str_useing(){          //使用string方法操作
    string str;             //定义目标字符串str
    cin>> str;              //输入一个字符串到str
    for(int i=str.size()-1;i>=0;i--){    //遍历字符串str的每个字符
        cout<< str[i];                   //输出字符串str的每个字符
    }
}

int main(){                               //程序入口
    cout<< "请输入一个字符串：" <<endl;     //提示文字
    //arr_useing();                       //使用字符数组方法操作
    str_useing();                         //使用string方法操作
    return 0;                             //返回正常运行
}