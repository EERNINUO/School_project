// 包含iostream头文件，使用std命名空间
#include <iostream>
using namespace std;

// 声明结构体数组，用于存储学生数据
struct student{             //声明结构体数组储存学生数据
    char name[32];
    int number;
    int grade;
}stu[10];

// 主函数
int main(){
    cout<< "Please input \"name\" \"number\" \"grade\"" <<endl;
    // 输入学生数据
    for(uint8_t i=0;i<10;i++){
        scanf("%s %d %d",stu[i].name,&stu[i].number,&stu[i].grade);
    }
    cout<< "Student is: " <<endl;
    // 输出学生数据
    for(uint8_t i=0;i<10;i++){
        if((stu[i].grade) <= 60) // 如果成绩小于等于60
            printf("%s,%d,%d\n",stu[i].name,stu[i].number,stu[i].grade);
    }
    return 0;
}
