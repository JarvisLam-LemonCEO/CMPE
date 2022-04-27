#include <iostream>

using namespace std;

// function prototype
void showResult(int a[3][3]);
void showMatrix(int a[3][3], int row, int col);

int main(){
	
	// array variables of Martix
	int a[3][3] = {{1, 0, 0}, {2, 3, 0}, {4, 5, 6}};
	int b[3][3] = {{1, 2, 3}, {0, 1, 7}, {0, 0, 9}};
	int c[3][3] = {{9, 1, 1}, {7, 2, 1}, {8, 3, 1}};
	
	//call showMatrix and showResult of Upper, lower and normal matrix
	showMatrix(a, 3, 3);
	showResult(a);
	showMatrix(b, 3, 3);
	showResult(b);
	showMatrix(c, 3, 3);
	showResult(c);
	
	return 0;
	
}

// The fuction of determing whether a martix is a normal, upper triangle or lower triangle
void showResult(int a[3][3]){
	//Upper triangular			Lower triagular
	/*		0 1 2					0 1 2
		0	x x x				0	x 0 0
		1	0 x x				1	x x 0        
		2	0 0	x				2	x x	x
	*/
	
	if ((a[1][0] == 0) && (a[2][0] == 0) && (a[2][1] == 0)){ //if index of array a[1][0], a[2][0] and a[2][1] contain 0 which is upper triangular
		cout << "upper triangular" << endl;
	} else if ((a[0][1] == 0) && (a[0][2] == 0) && (a[1][2] == 0)) { //if index of array a[0][1], a[0][2] and a[1][2] contain 0 which is lower triangular
		cout << "lower triangular" << endl;
	} else {
		cout << "normal" << endl;
	}
}

//The fuction of display matrix
void showMatrix(int a[3][3], int row, int col) { 
	for (int i = 0; i < row; i++){ 
		for (int j = 0; j < col; j++) { 
			cout << a[i][j] << " "; 
		}
		cout << endl; 
	} 
}

/*
	The output of program:
	----------------------
	1 0 0 
	2 3 0 
	4 5 6 
	lower triangular
	1 2 3 
	0 1 7 
	0 0 9 
	upper triangular
	9 1 1 
	7 2 1 
	8 3 1 
	normal


*/