#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

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
    Matrix &operator=(const double *other);// 赋值运算符重载
    double &operator()(int row, int col); // 索引运算符重载
    const double &operator()(int row, int col) const; // 常量索引运算符重载(用于安全的读取元素)
    Matrix &operator+(const Matrix &other) const;// 矩阵加法
    Matrix &operator*(const Matrix &other) const;// 矩阵乘法
    Matrix &operator*(double scalar) const;// 矩阵与标量乘法
    Matrix T() const;// 矩阵转置
    Matrix inv() const;// 矩阵求逆
    Matrix det() const;// 矩阵求行列式 
    
    int rows() const { return rows_; }  // 获取矩阵的行数
    int cols() const { return cols_; }  // 获取矩阵的列数
    double *data() const { return data_; } // 获取矩阵的数据指针
    void print() const;// 打印矩阵
};

#endif // __MATRIX_H__