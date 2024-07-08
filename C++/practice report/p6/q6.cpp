#include <iostream>
using namespace std;

                    //学号，课程1，课程2，课程3，课程4，课程5
int student[4][6] ={{1001,  96,    94,   89,    91,   87},
                    {1002,  82,    61,   77,    67,   72},
                    {1003,  18,    42,   37,    22,   49},
                    {1004,  56,    62,   49,    59,   63}};//测试数组

int ave(int arr[4][6],int stu){
    int sum=arr[1][2]+arr[2][2]+arr[3][2]+arr[4][2];
    float a = (float)sum/4;
    return a;
}

void find_not_pass(int stu){
    int num=0;
    for(int i=1;i<6;i++){
        if(student[stu][i] < 60) num++;
    }
    if(num > 2){
        cout<< student[stu][0] << ',';
        for(int i=1;i<6;i++){
            cout<< student[stu][i] << ',';
        }
        cout<< ave(student,stu) <<endl;
    }
}

void find(){
    for(int i=0;i<4;i++){
        if(ave(student,i)>90) cout<<student[i][0]<<endl;
        else{
            int tip=1;
            for(int j=1;j<6;j++){
                if(student[i][j] <= 85) tip = 0;
            }
            if(tip) cout<< student[i][0]<<endl;
        }
    }
}

int main(){
    cout<< "第一门课平均分为: " << ave(student,1) <<endl;
    cout<< "不及格的学生为："<<endl;
    for(int i=0;i<4;i++)find_not_pass(i);
    cout<<"平均成绩90分以上或全部课程成绩在85分以上的学生有:"<<endl;
    find();
    return 0;
}