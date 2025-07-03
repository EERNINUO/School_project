#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    data_ = new double[rows * cols]();
}

Matrix::Matrix(const Matrix &other) : rows_(other.rows_), cols_(other.cols_) {
    data_ = new double[rows_ * cols_]; //  分配内存空间，大小为行数乘以列数
    for (int i = 0; i < rows_ * cols_; ++i) { //  将另一个矩阵的数据复制到当前矩阵中
        data_[i] = other.data_[i];
    }
}

Matrix::~Matrix() {
    delete[] data_;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) { //  检查是否为自我赋值
        delete[] data_; //  释放原有数据
        rows_ = other.rows_; //  复制行数和列数
        cols_ = other.cols_;
        data_ = new double[rows_ * cols_]; //  分配新数据
        for (int i = 0; i < rows_ * cols_; ++i) { //  复制数据
            data_[i] = other.data_[i];
        }
    }
    return *this; //  返回当前对象
}

Matrix &Matrix::operator=(const double *other){
    for (int i = 0; i < rows_ * cols_; i++) {
        data_[i] = other[i];
    }
    return *this;
}

double &Matrix::operator()(int row, int col) {
    if (row >= rows_ || col >= cols_) { // 检查索引是否越界
        std::cout << "Index out of range" << std::endl;
    }
    return data_[row * cols_ + col];
}

const double &Matrix::operator()(int row, int col) const {
    if (row >= rows_ || col >= cols_) { // 检查索引是否越界
        std::cout << "Index out of range" << std::endl;
    }
    return data_[row * cols_ + col];
}

Matrix &Matrix::operator+(const Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix* add_result = new Matrix(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        (*add_result).data_[i] = data_[i] + other.data_[i];
    }
    return *add_result;
}

Matrix &Matrix::operator*(const Matrix &other) const {
    // 检查矩阵维度是否匹配
    if (cols_ != other.rows_) {
        std::cout << "Matrix dimensions must match" << std::endl;
    }
    // 创建一个矩阵用于存储结果
    Matrix* times_result = new Matrix(rows_, other.cols_);
    // 遍历矩阵元素
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                // 计算矩阵乘法结果
                (*times_result)(i, j) += data_[i * cols_ + k] * other.data_[k * other.cols_ + j];
            }
        }
    }
    // 返回结果矩阵
    return *times_result;
}

Matrix &Matrix::operator*(double scalar) const {
    Matrix* times_result = new Matrix(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        (*times_result).data_[i] = data_[i] * scalar;
    }
    return *times_result;
}

void Matrix::print() const {
    for (int i = 0; i < rows_; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < cols_; ++j) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "]"<< std::endl;
    }
    std::cout << std::endl;
}

Matrix Matrix::T() const{
    Matrix* T_result = new Matrix(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            (*T_result)(j, i) = (*this)(i, j);
        }
    }
    return *T_result;
}


Matrix Matrix::inv() const {
    // 获取矩阵的大小
    static Matrix inv_mat(cols_, rows_);
    // 初始化逆矩阵为单位矩阵
    for (int i = 0; i < cols_ * rows_; i++) {
        inv_mat.data_[i] = 1;
    }
    // 高斯-约当消元法求逆
    for (int i = 0; i < cols_; i++) {
        // 寻找主元
        double pivot = (*this)(i, i);
        for (int j = 0; j < cols_; j++) {
            data_[i* cols_ + j] /= pivot;
            inv_mat(i, j) /= pivot;
        }
        for (int j = 0; j < cols_ ; j++) {
            if (j != i) {
                double factor = (*this)(i, i);
                for (int k = 0; k <  rows_; k++) {
                    data_[j* cols_ + k] -= factor * data_[i* cols_ + k];
                    inv_mat(j, k) -= factor * inv_mat(j, k);
                }
            }
        }
    }
    return inv_mat;
}