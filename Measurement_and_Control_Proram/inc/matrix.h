#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <stdexcept>
#include <cassert>

class Matrix {
private:
    int rows_; // 矩阵的行数
    int cols_; // 矩阵的列数
    double *data_;

public:
    Matrix() : rows_(0), cols_(0), data_(nullptr){}    // 默认构造函数
    Matrix(int rows, int cols);// 指定大小的构造函数
    Matrix(const Matrix &other);// 拷贝构造函数
    ~Matrix();    // 析构函数

    Matrix &operator=(const Matrix &other);// 赋值运算符重载
    Matrix &operator=(const double *other);
    // 索引运算符重载
    double &operator()(int row, int col) {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[row * cols_ + col];
    }

    const double &operator()(int row, int col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[row * cols_ + col];
    }

    // 获取矩阵的行数和列数
    int rows() const { return rows_; }
    int cols() const { return cols_; }

    // 矩阵加法
    Matrix operator+(const Matrix &other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrix dimensions must match");
        }
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_ * cols_; ++i) {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return result;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix &other) const {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Matrix dimensions must match for multiplication");
        }
        Matrix result(rows_, other.cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < other.cols_; ++j) {
                for (int k = 0; k < cols_; ++k) {
                    result(i, j) += data_[i * cols_ + k] * other.data_[k * other.cols_ + j];
                }
            }
        }
        return result;
    }

    // 打印矩阵
    void print() const {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};


#endif // __MATRIX_H__