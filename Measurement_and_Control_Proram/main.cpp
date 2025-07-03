#include <iostream>
#include <cmath>
#include "inc/matrix.h"
#include "inc/draw.h"
#include "inc/read_data.h"

#define SHOW_DATA

#define a0_10 3.78
#define a0_05 5.99
#define a0_01 13.74

extern double X_read[];
extern double Yread[];

int main() {
    Matrix Y(8, 1);
    Matrix X(8, 2);
    Matrix b(2, 1);
    Matrix V(8, 1);

    Matrix C(2, 2);
    Matrix B(2, 1);

    Matrix X_T_X(2, 2);

    double Y_read[8];

    averge(Yread, Y_read, X.rows());
    for (int i = 0; i < X.rows(); i++) {
        X(i, 0) = 1;
        X(i, 1) = X_read[i];
    }
    Y = Y_read;
    X.print();
    Y.print();

    X_T_X = X.T()* X;
    double det = X_T_X(0, 0) * X_T_X(1, 1) - X_T_X(0, 1) * X_T_X(1, 0); // 行列式
    double c_num[4] = {X_T_X(1, 1) / det, - X_T_X(0, 1) / det, - X_T_X(1, 0) / det, X_T_X(0, 0) / det}; // 逆矩阵

    C = c_num;
    B = X.T() * Y;

    b = C * B;
    b.print();

#if defined(SHOW_DATA) || defined(SHOW_ALL) // 绘制散点图和回归直线
    // 绘制散点图
    Figure f1;
    f1.drawScatter(X_read, Y_read, X.rows());

    // 绘制回归直线
    Figure f2;
    double line_x[] = {5, 50};
    double line_y[] = {b(0, 0) + b(1, 0) * line_x[0], b(0, 0) + b(1, 0) * line_x[1]};
    f2.drawLine(line_x, line_y);

#endif // SHOW_DATA

#if  defined(LINE_CHECK) || defined(SHOW_ALL) // 检验回归方程的显著性
    // 计算Y的均值
    double Y_avage = 0;
    for (int i = 0; i < Y.rows(); i++) {
        Y_avage += Y_read[i];
    }
    Y_avage /= Y.rows();

    // 计算S、Q和U
    double S, Q, U, sigma2 = 0;
    for (int i = 0; i < Y.rows(); i++) {
        Q += pow(Y_read[i] - (b(0, 0) + b(1, 0) * X_read[i]), 2);
        U += pow((b(0, 0) + b(1, 0) * X_read[i]) - Y_avage, 2);
    }
    S = Q + U;
    
    std::cout << "Q = " << Q << std::endl;
    std::cout << "U = " << U << std::endl;
    std::cout << "S = " << S << std::endl;
    
    uint16_t N = Y.rows();

    // 计算F值
    double F = (U / 1) / (Q / (N - 2));

    sigma2 = Q / (N - 2);

    std::cout << "回归自由度= " << 1 << std::endl;
    std::cout << "残差自由度= " << N - 2 << std::endl;
    std::cout << "F= " << F << std::endl;
    std::cout << "残余方差= " << sigma2 << std::endl;

    if (F > a0_01) std::cout << "回归方程在0.01上显著" << std::endl;
    else if (F > a0_05) std::cout << "回归方程在0.05上显著" << std::endl;
    else if (F > a0_10) std::cout << "回归方程在0.10上显著" << std::endl;
    else std::cout << "回归方程不显著" << std::endl;

#endif // LINE_CHECK

    return 0;
}



