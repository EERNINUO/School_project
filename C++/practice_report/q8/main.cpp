#include <iostream> // 包含输入输出流库

// 定义一个num类，包含数量和价格两个属性，以及构造函数、求和函数和平均数函数
class num
{
public:
    int quantity; // 数量
    float price; // 价格

    num(int q, int p){ // 构造函数
        quantity = q; // 设置数量
        price = p; // 设置价格
    }

    int sum(){ // 求和函数，如果数量大于10，则打9.8折
        float sum = quantity * price; // 计算总和
        if (quantity > 10){ // 如果数量大于10
            sum *= 0.98; // 打9.8折
        }
        return sum;// 返回总和
    }

    int avarge(){// 求平均数函数
        float average = sum() / quantity; // 计算平均数
        return average; // 返回平均数
    }

    // 析构函数
    ~num(){}
};

int main()  // 主函数
{
    num n101(5, 23.5);// 创建num n101对象
    num n102(12, 24.56);// 创建num n102对象
    num n103(100, 21.5);// 创建num n103对象

    // 计算三个num对象的总和
    float sum = n101.sum() + n102.sum() + n103.sum();
    // 计算三个num对象的平均数
    float average = sum / (n101.quantity + n102.quantity + n103.quantity);

    std::cout << "Sum: " << sum << std::endl;// 输出总和
    std::cout << "Average: " << average << std::endl;// 输出平均数
}