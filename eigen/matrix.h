#ifndef EIGEN_MATRIX_H
#define EIGEN_MATRIX_H

#include "forward_declaration.h"

template<typename T, int CompileRows, int CompileCols>
class Matrix
{
public:
    enum {
        CompileSize = trasit_storage<CompileRows, CompileRows>::Size,
        Fixed = trasit_storage<CompileRows, CompileRows>::IsArray,
    };
    typedef StorageBase<T, CompileSize, Fixed> Storage;
    Matrix()
        : rows_(CompileRows), cols_(CompileCols), size_(CompileRows * CompileCols)
    {
        static_assert((CompileRows != DYNAMIC) && (CompileCols != DYNAMIC),
                      "VALID CONSTRUCTOR ONLY FOR FIXED Matrix.");
        data_ = storage_.data();
    }
    Matrix(int rows)
        : rows_(rows), cols_(1), size_(rows_ * 1), storage_(size_)
    {
        static_assert((CompileRows == DYNAMIC) && (CompileCols == 1),
                      "VALID CONSTRUCTOR ONLY FOR DYNAMIC VECTOR.");
        data_ = storage_.data();
    }
    Matrix(int rows, int cols)
        : rows_(rows), cols_(cols), size_(rows_ * cols_), storage_(size_)
    {
        static_assert((CompileRows == DYNAMIC) && (CompileCols == DYNAMIC),
                      "VALID CONSTRUCTOR ONLY FOR DYNAMIC Matrix.");
        data_ = storage_.data();
    }
    Matrix(const Matrix& other)
        : rows_(other.rows_), cols_(other.cols_), size_(other.size_), storage_(other.storage_)
    {
        if (Fixed && ((CompileRows != other.rows_) || (CompileCols != other.cols_))) {
            // error
        }
        if ((CompileCols == 1) && (1 != other.cols_)) {
            // error
        }
        data_ = storage_.data();
    }
    Matrix& operator=(const Matrix& other) {
        if (Fixed && ((CompileRows != other.rows_) || (CompileCols != other.cols_))) {
            // error
        }
        if ((CompileCols == 1) && (1 != other.cols_)) {
            // error
        }
        rows_ = other.rows_;
        cols_ = other.cols_;
        size_ = other.size_;
        storage_ = other.storage_;
        data_ = storage_.data();
        return *this;
    }
    Matrix(Matrix&& other)
        : rows_(other.rows_), cols_(other.cols_), size_(other.size_), storage_(std::move(storage_))
    {
        if (Fixed && ((CompileRows != other.rows_) || (CompileCols != other.cols_))) {
            // error
        }
        if ((CompileCols == 1) && (1 != other.cols_)) {
            // error
        }
        data_ = storage_.data();
    }
    Matrix& operator=(Matrix&& other) {
        if (Fixed && ((CompileRows != other.rows_) || (CompileCols != other.cols_))) {
            // error
        }
        if ((CompileCols == 1) && (1 != other.cols_)) {
            // error
        }
        rows_ = other.rows_;
        cols_ = other.cols_;
        size_ = other.size_;
        storage_ = std::move(other.storage_);
        data_ = storage_.data();
        return *this;
    }

private:
    int rows_ { 0 };
    int cols_ { 0 };
    int size_ { 0 };
    Storage storage_;
    T* data_ { nullptr };
};

typedef Matrix<float, DYNAMIC, DYNAMIC> MatrixXf;
typedef Matrix<float, 2, 2> Matrix2f;
typedef Matrix<float, 3, 3> Matrix3f;
typedef Matrix<float, 4, 4> Matrix4f;
typedef Matrix<float, DYNAMIC, 1> VectorXf;
typedef Matrix<float, 2, 1> Vector2f;
typedef Matrix<float, 3, 1> Vector3f;
typedef Matrix<float, 4, 1> Vector4f;

typedef Matrix<double, DYNAMIC, DYNAMIC> MatrixXd;
typedef Matrix<double, 2, 2> Matrix2d;
typedef Matrix<double, 3, 3> Matrix3d;
typedef Matrix<double, 4, 4> Matrix4d;
typedef Matrix<double, DYNAMIC, 1> VectorXd;
typedef Matrix<double, 2, 1> Vector2d;
typedef Matrix<double, 3, 1> Vector3d;
typedef Matrix<double, 4, 1> Vector4d;

#endif