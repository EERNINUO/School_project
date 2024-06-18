#include <iostream>
using namespace std;

struct student{             //声明结构体数组储存学生数据
    char name[32];
    int number;
    int grade;
}stu[10];

int main(){
    cout<< "Please input \"name\" \"number\" \"grade\"" <<endl;
    for(uint8_t i=0;i<10;i++){
        scanf("%s %d %d",stu[i].name,&stu[i].number,&stu[i].grade);
    }
    cout<< "Student is: " <<endl;
    for(uint8_t i=0;i<10;i++){
        if((stu[i].grade) <= 60) 
            printf("%s,%d,%d\n",stu[i].name,stu[i].number,stu[i].grade);
    }
    return 0;
}
