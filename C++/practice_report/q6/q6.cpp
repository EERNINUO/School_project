/*******************************************************************************
 * GNU GENERAL PUBLIC LICENSE (GPL) v3.0
 * Copyright (c) EERNIINUO
 * which is available at
 *	 https://github.com/EERNINUO/School_project/tree/main/C++/practice_report/q6
 * All rights reserved.
 *
 ********************************************************************************/
#include <iostream>  // 包含iostream头文件，使用std命名空间
using namespace std; // 使用std命名空间

            // 学号，课程1，课程2，课程3，课程4，课程5
int student[4][6] = {{1001, 96, 94, 89, 91, 87},
                     {1002, 82, 61, 77, 67, 72},
                     {1003, 18, 42, 37, 22, 49},
                     {1004, 56, 62, 49, 59, 63}}; // 测试数组

int ave(int arr[4][6], int stu)                              // 计算平均值
{                              
    int sum = arr[1][2] + arr[2][2] + arr[3][2] + arr[4][2]; // 计算分数的和
    float a = (float)sum / 4;                                // 计算平均值
    return a;                                                // 返回平均值
}

void find_not_pass(int stu)             // 查找有两门课不及格的学生
{ 
    int num = 0;                        // 不及格科目的数量
    for (int i = 1; i < 6; i++)         // 遍历每一门课
    {
        if (student[stu][i] < 60)       // 如果第i门课不及格
            num++;                      // 则不及格科目+1
    }
    if (num > 2)                        // 如果不及格科目数量大于2
    {
        cout << student[stu][0] << ','; // 输出该学生的姓名
        for (int i = 1; i < 6; i++)
        {
            cout << student[stu][i] << ',';// 输出该学生的成绩
        }
        cout << ave(student, stu) << endl;// 输出该学生的平均成绩
    }
}

void find()                                         // 查找平均成绩90分以上或全部课程成绩在85分以上的学生
{
    for (int i = 0; i < 4; i++)                     // 遍历4个学生
    {
        if (ave(student, i) > 90)                   // 如果该学生的平均成绩大于90
            cout << student[i][0] << endl;          // 输出该学生的姓名
        else
        {
            int tip = 1;                            // 存储成绩在85分以上的科目数量
            for (int j = 1; j < 6; j++)             // 遍历该学生的6科成绩
            {
                if (student[i][j] <= 85)            // 如果有科成绩小于85
                    tip = 0;                        // 将tip置为0
            }
            if (tip)                                // 如果不存在不及格的科目，
                cout << student[i][0] << endl;      // 输出该学生的姓名
        }
    }
}

int main()
{
    cout << "第一门课平均分为: " << ave(student, 1) << endl;              //求第一门课的平均分
    cout << "不及格的学生为：" << endl;                                   //输出提示信息
    for (int i = 0; i < 4; i++)                                          //遍历每一个学生
        find_not_pass(i);                                               
    cout << "平均成绩90分以上或全部课程成绩在85分以上的学生有:" << endl;     //输出提示信息
    find();                                                              //查找平均成绩90分以上或全部课程成绩在85分以上的学生
    return 0;
}