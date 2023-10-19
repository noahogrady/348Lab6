#include <iostream>
#include <fstream>
void getMatrices(const std::string& fileName, int**& matrix1, int**& matrix2, int& n);
void printMatrix(int** matrix, int numRows, int numCols);
void matrixSum(int** matrix1, int** matrix2, int numRows, int numCols);
void matrixProduct(int** matrix1, int** matrix2, int numRows, int numCols);
void matrixDiff(int** matrix1, int** matrix2, int numRows, int numCols);

int main(){
    int n;
    int** matrix1 = nullptr;
    int** matrix2 = nullptr;
    getMatrices("matrix_input.txt", matrix1, matrix2, n);
    std::cout << "Noah O'Grady\nLab #6: Matrix Manipulation\n";
    std::cout << "Matrix A:\n";
    printMatrix(matrix1, n, n);
    std::cout << "Matrix B:\n";
    printMatrix(matrix2, n, n);
    std::cout << "Matrix Sum (A + B):\n";
    matrixSum(matrix1, matrix2, n, n);
    std::cout << "Matrix Product (A * B):\n";
    matrixProduct(matrix1, matrix2, n, n);
    std::cout << "Matrix Difference (A - B):\n";
    matrixDiff(matrix1, matrix2, n, n);
    return 0;
}

void getMatrices(const std::string& fileName, int**& matrix1, int**& matrix2, int& n){
    std::ifstream inputFile(fileName);
    inputFile >> n;

    matrix1 = new int*[n];
    matrix2 = new int*[n];

    for (int i=0; i<n;i++){
        matrix1[i] = new int[n];
        matrix2[i] = new int[n];
    } 

    for (int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            inputFile >> matrix1[i][j];
        }
    }

    for (int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            inputFile >> matrix2[i][j];
        }
    }
}

void printMatrix(int** matrix, int numRows, int numCols){
    for (int i=0; i<numRows; i++){
        for (int j=0; j<numCols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void matrixSum(int** matrix1, int** matrix2, int numRows, int numCols){
    int** matrix3 = new int* [numRows];
    for(int i=0; i<numCols; i++){
	matrix3[i] = new int[numCols];
    }
    for(int i=0; i<numRows; i++){
	for(int j=0; j<numCols; j++){
		matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
	}
    }
    printMatrix(matrix3, numRows, numCols);
}

void matrixProduct(int** matrix1, int** matrix2, int numRows, int numCols){
    int** matrix3 = new int* [numRows];
    for(int i=0; i<numRows; i++){
        matrix3[i] = new int[numCols];
    }
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            matrix3[i][j] = 0;
        }
    }
    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            for(int s=0; s<numRows; s++){
                matrix3[i][j] += matrix1[i][s] * matrix2[s][j];
            }
        }
    }
    printMatrix(matrix3, numRows, numCols);
}

void matrixDiff(int** matrix1, int** matrix2, int numRows, int numCols){
    int** matrix3 = new int* [numRows];
    for(int i=0; i<numCols; i++){
	matrix3[i] = new int[numCols];
    }
    for(int i=0; i<numRows; i++){
	for(int j=0; j<numCols; j++){
		matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
	}
    }
    printMatrix(matrix3, numRows, numCols);
}