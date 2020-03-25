#include <iostream>
#include <stdlib.h>
#include "math_tools.h"
#include "display_tools.h"

using namespace std;

void inverseMatrix(Matrix A, Matrix &I) {

	float determinante = determinant(A);
	if (determinante == 0) {
		cout << "No se puede calcular la inversa de esta matriz porque el determinante es 0" << endl;
		exit(EXIT_FAILURE);
	}else{
		Matrix cofMatrix;
		cofactors(A, cofMatrix); //creamos la matriz de cofactores a partir de la matriz original

		Matrix transposedMatrix;
		transpose(cofMatrix, transposedMatrix); //transponemos la matriz de cofactores

		productRealMatrix((1 / determinante), transposedMatrix, I); //multiplicamos la matriz adjunta por la constante 1/|A|

	}

}

int main() {

	Matrix A, Inversa;
	zeroes(A, 3);

	A.at(0).at(0) = 2; A.at(0).at(1) = 2; A.at(0).at(2) = 3; //se inicializa la matriz a invertir
	A.at(1).at(0) = 4; A.at(1).at(1) = 5; A.at(1).at(2) = 6;
	A.at(2).at(0) = 7; A.at(2).at(1) = 8; A.at(2).at(2) = 9;

	inverseMatrix(A, Inversa);
	showMatrix(Inversa);

}