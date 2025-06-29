#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    data_ = new double[rows * cols]();
}

Matrix::Matrix(const Matrix &other) : rows_(other.rows_), cols_(other.cols_) {
    data_ = new double[rows_ * cols_];
    for (int i = 0; i < rows_ * cols_; ++i) {
        data_[i] = other.data_[i];
    }
}

Matrix::~Matrix() {
    delete[] data_;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        delete[] data_;
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = new double[rows_ * cols_];
        for (int i = 0; i < rows_ * cols_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(const double *other){
    for (int i = 0; i < rows_ * cols_; ++i) {
        data_[i] = other[i];
    }
}