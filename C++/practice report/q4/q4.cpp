#include <iostream>
using namespace std;

struct nums{
    int number;
    nums * next;
};

static nums * head = NULL;			//存储链表头指针

bool in(int num,nums * array){
    nums *current_p_in = head;			//
	if(head != NULL){
		while(current_p_in->next != NULL){
			if(num == array->number) return true;		//如果当前数为目标数则返回真
			else current_p_in = array->next;		//如果当前数不为目标数则移至下一个节点
		}
	}
    return false;						//如果链表中无目标数则返回假
}

bool prime(int num){               //计算输入数据是不是素数
	nums *current_p_prime = head;
	nums *prev,*malloc_return;
    if(in(num,head)) return true;
    else{
		for(int i=2;i<num;i++){				//遍历比目标数小的数
			if(num%i == 0) 	return false;	//判断目标数是否有其他因数，如果有，返回false
        }
		malloc_return = (nums *)malloc(sizeof(nums));//创建一个新的节点
		if(head == NULL) head = malloc_return;
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
	for(int i=0;i<number;i++){
		if(number%i == 0){
			if(prime(i) && prime(number/i));
		}
	}
}

int main(){
    int input_num;
	
    cout<< "Please input a even number not less than 6: ";
    cin>>input_num;
	while (input_num != 0){
		if(prime(input_num)) cout<<"yes"<<endl;
		cout<< "Please input a even number not less than 6: ";
		cin>>input_num;
	}
	clean_list();
	
	/*
    if(num >= 6 && num%2 ==0) cout<<1;
    else if(num < 6) cout<< "Please input a number not less than 6!";
    else if(num%2 != 0) cout<< "Please input a even number!";
    else{
        cout<< "Unknown error!";
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;*/
}
