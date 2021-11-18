#include <iostream>
#include "utmatrix.h"

void main() {
	TMatrix<int> matrix1(3);
	TMatrix<int> matrix2(3);

	cin	>> matrix1; 	

	cin >> matrix2;
	
	TMatrix<int> matrixr3 = matrix1 - matrix2;
    cout << matrixr3;
	system("pause");
}