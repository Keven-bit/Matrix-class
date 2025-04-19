#pragma once

#include<iostream>
#include <vector>
template <typename T,int row,int col>
class Matrix {
public:
	std::vector<std::vector<T>> ele;

	Matrix() :ele(row, std::vector<T>(col)){};
	//Matrix(int r, int c) :row(r), col(c) {};
	T& operator()(int r, int c) {
		return ele[r][c];
	}

	friend std::ostream& operator<< (std::ostream& out, const Matrix& src) {
		for (const auto& r : src.ele) {
			for (const auto& element : r) {
				out << element << " ";
			}
			out << std::endl;
		}
		return out;
	};

};


