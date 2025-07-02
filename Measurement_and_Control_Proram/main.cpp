#include <iostream>
#include "inc/matrix.h"
#include "inc/draw.h"
#include "inc/read_data.h"

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

    X_T_X = X.T()* X;
    X_T_X.print();

    double det = X_T_X(0, 0) * X_T_X(1, 1) - X_T_X(0, 1) * X_T_X(1, 0);
    double c_num[4] = {X_T_X(1, 1) / det, - X_T_X(0, 1) / det, - X_T_X(1, 0) / det, X_T_X(0, 0) / det};
    C = c_num;
    B = X.T() * Y;

    X.print();
    Y.print();
    C.print();
    B.print();
    b = C * B;
    b.print();

    Figure f1;
    f1.drawScatter(X_read, Y_read, X.rows());

    Figure f2;
    double line_x[] = {5, 50};
    double line_y[] = {b(0, 0) + b(1, 0) * line_x[0], b(0, 0) + b(1, 0) * line_x[1]};
    f2.drawLine(line_x, line_y);

    return 0;
}



