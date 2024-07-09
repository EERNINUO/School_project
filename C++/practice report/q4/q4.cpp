#include <iostream>
using namespace std;

struct nums{
    int number;
    nums * next;
};

static nums * head = NULL;			//存储链表头指针

bool in(int num,nums * head){			//
    nums *current_p_in = head;			//
	if(head != NULL){
		while(current_p_in->next != NULL){
			if(num == current_p_in->number) return true;		//如果当前数为目标数则返回真
			else current_p_in = current_p_in->next;		//如果当前数不为目标数则移至下一个节点
		}
	}
    return false;						//如果链表中无目标数则返回假
}

bool prime(int num){               //计算输入数据是不是素数
	nums *current_p_prime = head;
	nums *prev,*malloc_return;
    if(in(num,head)) return true;
    else{
		for(int i=2;i<(num/2);i++){				//遍历比目标数小的数
			if(num%i == 0) 	return false;	//判断目标数是否有其他因数，如果有，返回false
        }
		malloc_return = (nums *)malloc(sizeof(nums));//创建一个新的节点
		if(head == NULL){
			head = malloc_return;
			}
		else{
			while(current_p_prime != NULL){
				prev = current_p_prime;
				current_p_prime	= current_p_prime->next;
			}
			prev->next = malloc_return;
		}
		malloc_return->next = NULL;
		malloc_return->number = num;
		return true;
	}
}

void clean_list(void){
	nums * current_clean = head;
	while(current_clean != NULL){
		head = current_clean->next;
		free(current_clean);
		current_clean = head;
	}
}

void gotbah(int number){
	for(int i=2;i<(number/2);i++){				//遍历比目标数小的所有值
		if(prime(i)&&prime(number-i)){
			printf("%d=%d+%d\n",number,i,number-i);
		}
	}
}

int main(){
    int input_num = 1;
	cout<< "Input 0 to exit." <<endl;
	while(input_num != 0){
    cout<< "Please input a even number not less than 6: ";
    cin>>input_num;
		if(input_num >= 6 && input_num%2 ==0)gotbah(input_num);
		else if(input_num < 6) cout<< "Please input a number not less than 6!";
		else if(input_num%2 != 0) cout<< "Please input a even number!";
		else{
			cout<< "Unknown error!";
			clean_list();
			exit(EXIT_FAILURE);
		}
	clean_list();
	}
    return EXIT_SUCCESS;
}
