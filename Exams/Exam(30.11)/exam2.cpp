#include <iostream>

using namespace std;

class Vector{
	int n;
	int* array;
public:
	Vector();
	Vector(int n, int* arr){
		this->n = n;
		this->array = new int(n);
		for (int i = 0; i < n; ++i){
			this->array[i] = arr[i];
		}
	}

	int getN(){
		return this->n;
	}

	int* getArray(){
		return this->array;
	}
	int operator[] (int index) {
		return this->array[index];
	}
	~Vector(){
		delete[] array;
	}
	
};

class Matrix{
	int n;
	int m;
	Vector* vectors;
public:
		Matrix(int n, int m){
		this->n = n;
		this->m = m;
	}
	int getM() {
		return m;
	}
	int getN() {
		return n;
	}
	static Matrix from_array(int n, int m, int* arr){
		Matrix matrix = Matrix(n, m);
		for (int i = 0; i < n; ++i){
			matrix.vectors[i] = Vector(m, &arr[i]);
		}
		return matrix;
	}


	/*Matrix operator+ (Matrix matrix, int num) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] = matrix[i][j] + number;
			}
		}
		return matrix;
	}
	Matrix operator+ (int num) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vectors[i][j] += num;
			}
		}
		return *this;
	}
	Matrix operator+ (Matrix matrix) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vectors[i][j] += matrix.vectors[i][j];
			}
		}
		return *this;
	}
	Matrix operator- (int num) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vectors[i][j] -= num;
			}
		}
		return *this;
	}
	Matrix operator- (Matrix matrix) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vectors[i][j] -= matrix.vectors[i][j];
			}
		}
		return *this;
	}*/
	~Matrix(){
		delete[] vectors;
	}
	
};

int main(int argc, char const *argv[]){
	int arr[3] = {1, 2, 3};
	int arr2[4] = {1, 2, 3, 4};
	Vector v1 = Vector(3, arr);
	Vector v2 = Vector(3, arr);
	Vector v3 = Vector(4, arr2);
	Matrix matrix = Matrix(2, 3);
	int array[2][3];
	array[0][0] = 1;
	array[0][1] = 2;
	array[0][2] = 3;
	array[1][0] = 4;
	array[1][1] = 5;
	array[1][2] = 6;
	matrix = matrix.from_array(2, 3, *array);
	return 0;
}