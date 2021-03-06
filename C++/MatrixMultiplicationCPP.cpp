#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	//Declaring variables for rows/columns and initializing the matrices
	int rowA, columnA, rowB, columnB;
	int a[100][100];
	int b[100][100];
	int c[100][100];
    
	//Ensures the randomly generated values won't be repeated
	srand(time(NULL));
    
	//Takes input from user to set matrix sizes
	cout << "# of rows for matrix A: ";
	cin >> rowA;
	cout << "# of columns for matrix A: ";
	cin >> columnA;
	cout << "# of rows for matrix B: ";
	cin >> rowB;
	cout << "# of columns for matrix B: ";
	cin >> columnB;
	cout << endl;

	// Checks if matrix A and B cannot be multiplied
	while (columnA != rowB) {
		cout << "Incompatible matrix sizes!";
	}
    
	//Starts a timer to measure execution time
	clock_t begin = clock();

	//Fills Matrix A with random numbers between 1-100
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < columnA; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}
    
	//Fills Matrix B with random numbers between 1-100
	for (int i = 0; i < rowB; i++) {
		for (int j = 0; j < columnB; j++) {
			b[i][j] = rand() % 100 + 1;
		}
	}

	//Prints out Matrix A
	cout << "Matrix A: " << endl;
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < columnA; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	
	//Prints out Matrix B
	cout << "Matrix B: " << endl;
	for (int i = 0; i < rowB; i++) {
		for (int j = 0; j < columnB; j++) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	
	//Performs matrix multiplication for matrix A and B
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < columnB; j++) {
			c[i][j] = 0;
			for (int k = 0; k < rowB; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
    
	//Prints out Matrix C
	cout << "Resulting Matrix: " << endl;
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < columnB; j++) {
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}
	
	//Stops the timer and returns the execution time in milliseconds
	cout << endl;
	clock_t end = clock();
	double clockTicks = double(end - begin);
	double timeTaken_ms = clockTicks / (CLOCKS_PER_SEC / 1000);
	cout << "Execution Time: " << timeTaken_ms << " ms";
}
