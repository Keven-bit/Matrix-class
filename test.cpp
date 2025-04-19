#include<iostream>
#include<vector>
#include"Matrix.h"

int main() {
	//std::vector<double>b = {1,2,3,4};
	Matrix<double,3,2> a({ 1,2,3,4,5,6 });
	Matrix<double, 3, 2> b({ 1,2,3,4,5,6 });
	
	//a(0, 0) = 1;
	//a(0, 1) = 2;
	//a(1, 0) = 3;
	//a(1, 1) = 4;

	std::cout << a+b;

	return 0;
}