#include<iostream>
#include<vector>
#include"Matrix.h"

int main() {
	Matrix<double,2,2> a;
	a(0, 0) = 1;
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 4;
	std::cout << a;

	return 0;
}