/*******************************************************************************
 * GNU GENERAL PUBLIC LICENSE (GPL) v3.0
 * Copyright (c) EERNIINUO
 * which is available at
 *	 https://github.com/EERNINUO/School_project/tree/main/C++/practice_report/q2
 * All rights reserved.
 *
 ********************************************************************************/
#include <iostream>
using namespace std;

int n;

void num_off(int index[])
{
    int sign = 1;    // 计算每个人报的数
    int stu_num = 0; // 存储还存活的人数
    while (stu_num != 1)
    {                // 当存活的人不等于1时
        stu_num = 0; // 重置计数器
        for (int i = 0; i < n; i++)// 遍历每一个人
        { 
            if (index[i] != 0)
            { // 如果当前人还存活
                if (sign == 3)    // 如果这个人报了3
                {                 
                    index[i] = 0; // 将这个人移除
                    sign = 0;     // 重新从1开始
                }
                else
                    stu_num++; // 存活的人加1
                sign++;        // 报数加1
            }
        }
    }
    for (int i = 0; i < n; i++)
    { // 遍历每一个人以寻找仍然存活的人
        if (index[i] != 0)
            cout << "最后留下的人原来排在第" << i + 1 << "个" << endl;//输出
    }
}

int main()
{
    cout << "请输入人数：";            //输入提示
    cin >> n;                         //获取人数信息
    int index[n];                     //建立数组以存储原来的序号
    for (int i = 0; i < n; i++)       //对数组赋初值
    {
        index[i] = i + 1;
    }
    num_off(index);                    //进行计算
    return 0;                          //程序返回
}
