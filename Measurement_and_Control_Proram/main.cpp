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
    double det = X_T_X(0, 0) * X_T_X(1, 1) - X_T_X(0, 1) * X_T_X(1, 0); // ����ʽ
    double c_num[4] = {X_T_X(1, 1) / det, - X_T_X(0, 1) / det, - X_T_X(1, 0) / det, X_T_X(0, 0) / det}; // �����

    C = c_num;
    B = X.T() * Y;

    b = C * B;
    b.print();

#if defined(SHOW_DATA) || defined(SHOW_ALL) // ����ɢ��ͼ�ͻع�ֱ��
    // ����ɢ��ͼ
    Figure f1;
    f1.drawScatter(X_read, Y_read, X.rows());

    // ���ƻع�ֱ��
    Figure f2;
    double line_x[] = {5, 50};
    double line_y[] = {b(0, 0) + b(1, 0) * line_x[0], b(0, 0) + b(1, 0) * line_x[1]};
    f2.drawLine(line_x, line_y);

#endif // SHOW_DATA

#if  defined(LINE_CHECK) || defined(SHOW_ALL) // ����ع鷽�̵�������
    // ����Y�ľ�ֵ
    double Y_avage = 0;
    for (int i = 0; i < Y.rows(); i++) {
        Y_avage += Y_read[i];
    }
    Y_avage /= Y.rows();

    // ����S��Q��U
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

    // ����Fֵ
    double F = (U / 1) / (Q / (N - 2));

    sigma2 = Q / (N - 2);

    std::cout << "�ع����ɶ�= " << 1 << std::endl;
    std::cout << "�в����ɶ�= " << N - 2 << std::endl;
    std::cout << "F= " << F << std::endl;
    std::cout << "���෽��= " << sigma2 << std::endl;

    if (F > a0_01) std::cout << "�ع鷽����0.01������" << std::endl;
    else if (F > a0_05) std::cout << "�ع鷽����0.05������" << std::endl;
    else if (F > a0_10) std::cout << "�ع鷽����0.10������" << std::endl;
    else std::cout << "�ع鷽�̲�����" << std::endl;

#endif // LINE_CHECK

    return 0;
}



