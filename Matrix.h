#pragma once

#include<iostream>
#include<iomanip>
#include <vector>
template <typename T, int Row, int Col>
class Matrix {
public:
	using value_type = T;
	static constexpr int row = Row;
	static constexpr int col = Col;
public:
	//矩阵内容保存在一维数组，在构造函数中定义
	std::vector<T> ele;
	//构造函数，定义ele数组
	Matrix() :ele(row* col) {};
	//由一个一维数组构造矩阵对象
	Matrix(std::vector<T>vec) :ele(vec) {};
	//访问矩阵元素
	T& operator()(int r, int c) {
		if (r < row && r>=0 && c < col && c>=0)
			return ele[r * col + c];
		else
			throw std::out_of_range("Matrix indices out of bounds");
	}

	const T& operator()(int r, int c) const{
		if (r < row && r >= 0 && c < col && c >= 0)
			return ele[r * col + c];
		else
			throw std::out_of_range("Matrix indices out of bounds");
	}

	//cout输出矩阵内容
	friend std::ostream& operator<< (std::ostream& out, const Matrix& src) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				out << std::setw(2) << src.ele[r * row + c] << " ";
			}
			out << std::endl;
		}
		return out;
	};
	//手动输入矩阵
	friend std::istream& operator>> (std::istream& in, Matrix& dir) {
		for (int i = 0; i < row * col; i++) {
			in >> dir.ele[i];
		}
		return in;
	}

	//矩阵乘法
	template <typename U, int right_col>
	auto operator* (Matrix<U, col, right_col> right)const
		->Matrix<decltype(T{} + U{}), row, right_col >
	{
		using resulttype = Matrix<decltype(T{} + U{}), row, right_col > ;
		resulttype result;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < right_col; c++) {
				for (int k = 0; k < col; k++)
					result(r, c) += (*this)(r, k) * right(k, c);
			}
		}
		return result;
	}
	
	
	//Matrix& operator* (const Matrix<T,Row,Col>& M1) const{
	//	if (col == M2.row) {
	//		Matrix<decltype(*this::T{} + M1::T{}), col, M1.row > result;
	//		return &result;
	//		//如何推导出返回的Matrix的类型？？
	//	}
	//	else
	//		std::cout << "Matrix size does not match";
	//		return;
	
};



