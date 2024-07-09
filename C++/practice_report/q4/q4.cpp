/*******************************************************************************
* GNU GENERAL PUBLIC LICENSE (GPL) v3.0
* Copyright (c) EERNIINUO
* which is available at 
*	 https://github.com/EERNINUO/School_project/tree/main/C++/practice_report/q4
* All rights reserved.
*
********************************************************************************/
#include <iostream>				//引入iostream头文件
using namespace std;			//使用std命名空间

struct nums{					//链表结构体nums
    int number;					//整数number
    nums * next;				//指向下一个节点的指针next
};

static nums * head = NULL;			//存储链表头指针

bool in(int num,nums * head){			//判断num是否在head对应的链表中
    nums *current_p_in = head;			//将当前所在的节点设置为head对应的节点
	if(head != NULL){									//判断是否存在第一个节点
		while(current_p_in->next != NULL){				//遍历链表
			if(num == current_p_in->number) return true;//如果当前数为目标数则返回真
			else current_p_in = current_p_in->next;		//如果当前数不为目标数则移至下一个节点
		}
	}
    return false;						//如果链表中无目标数则返回假
}

bool prime(int num){               //计算输入数据是不是素数
	nums *current_p_prime = head;		    //将当前所在的节点设置为head对应的节点
	nums *prev,*malloc_return;				//声明必要的指针变量
    if(in(num,head)) return true;			//判断数是否在链表内
    else{
		for(int i=2;i<(num/2);i++){			//遍历比目标数小的数
			if(num%i == 0) 	return false;	//判断目标数是否有其他因数，如果有，返回false
        }
		malloc_return = (nums *)malloc(sizeof(nums));//创建一个新的节点
		if(head == NULL){					//如果链表第一项不存在
			head = malloc_return;			//创建链表入口
			}
		else{
			while(current_p_prime != NULL){//将prev指针指向链表的最后一个节点
				prev = current_p_prime;
				current_p_prime	= current_p_prime->next;
			}
			prev->next = malloc_return;	   //最后一个节点赋给上一个节点的next指针
		}
		malloc_return->next = NULL;		   //next指针赋空
		malloc_return->number = num;	   //将计算出来的素数存储
		return true;					   //返回true
	}
}

void clean_list(void){				// 清理链表
	nums * current_clean = head;	// 定义当前节点指针
	while(current_clean != NULL){	// 遍历链表
		head = current_clean->next;	// 将当前节点的下一个节点指向当前节点的下一个节点的下一个节点
		free(current_clean);		// 释放当前节点的内存空间
		current_clean = head;
	}
}

void gotbah(int number){							// 定义哥德巴赫函数
	for(int i=2;i<(number/2);i++){					//从2开始遍历小于number/2的所有数
		if(prime(i)&&prime(number-i)){				// 如果i是质数，且number-i也是质数
			printf("%d=%d+%d\n",number,i,number-i);	// 输出number=i+number-i的值
		}
	}
}

int main(){
    int input_num = 1;    //输入的数值
	cout<< "Input 0 to exit." <<endl;//输出提示信息，让用户输入0来退出程序
	while(input_num != 0){			 //判断是否退出代码
	cout<< "Please input a even number not less than 6: ";		//输出提示信息，让用户输入一个偶数，且这个偶数大于等于6
		if(input_num >= 6 && input_num%2 ==0)gotbah(input_num);	//判断输入的数字是否合法
		else if(input_num < 6) cout<< "Please input a number not less than 6!";
		else if(input_num%2 != 0) cout<< "Please input a even number!";
		else{							//输出未知错误信息
			cout<< "Unknown error!";	//输出提示语
			clean_list();				//清空链表
			exit(EXIT_FAILURE);			//程序异常退出
		}
	clean_list();						//清理链表
	}
    return EXIT_SUCCESS;			    //程序正常退出
}