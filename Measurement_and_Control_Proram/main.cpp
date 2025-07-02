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

    
    Matrix B(2, 1);

    double Y_read[8];

    averge(Yread, Y_read, X.rows());
    for (int i = 0; i < X.rows(); i++) {
        X(i, 0) = 1;
        X(i, 1) = X_read[i];
    }
    Y = Y_read;

    Matrix  X_T(X.T() * X);
    X_T.print();

    Matrix C(X_T.inv()); 
    B = X_T * Y;

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
    double line_y[] = {-5046 + 25.2335 * 5, -5.046 + 25.2335 * 50};
    f2.drawLine(line_x, line_y);

    return 0;
}



