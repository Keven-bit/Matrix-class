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
	//�������ݱ�����һά���飬�ڹ��캯���ж���
	std::vector<T> ele;
	//���캯��������ele����
	Matrix() :ele(row* col) {};
	//��һ��һά���鹹��������
	Matrix(std::vector<T>vec) :ele(vec) {};
	//���ʾ���Ԫ��
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

	//cout�����������
	friend std::ostream& operator<< (std::ostream& out, const Matrix& src) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				out << std::setw(2) << src.ele[r * row + c] << " ";
			}
			out << std::endl;
		}
		return out;
	};
	//�ֶ��������
	friend std::istream& operator>> (std::istream& in, Matrix& dir) {
		for (int i = 0; i < row * col; i++) {
			in >> dir.ele[i];
		}
		return in;
	}

	//����˷�
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
	//		//����Ƶ������ص�Matrix�����ͣ���
	//	}
	//	else
	//		std::cout << "Matrix size does not match";
	//		return;
	
};



