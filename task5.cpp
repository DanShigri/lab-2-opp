#include <iostream>
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}
void fillMatrix(int** matrix, int rows, int cols) {
    std::cout << "Enter elements for the matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int** addMatrices(int** mat1, int** mat2, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}
int** subtractMatrices(int** mat1, int** mat2, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}
int** multiplyMatrices(int** mat1, int** mat2, int rows, int cols, int mat2Cols) {
    int** result = createMatrix(rows, mat2Cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < mat2Cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns for the matrix: ";
    std::cin >> cols;
    int** matrix1 = createMatrix(rows, cols);
    int** matrix2 = createMatrix(rows, cols);
    std::cout << "Matrix 1:" << std::endl;
    fillMatrix(matrix1, rows, cols);
    std::cout << "Matrix 2:" << std::endl;
    fillMatrix(matrix2, rows, cols);
    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, rows, cols);
    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, rows, cols);
    int** sum = addMatrices(matrix1, matrix2, rows, cols);
    int** diff = subtractMatrices(matrix1, matrix2, rows, cols);
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    printMatrix(sum, rows, cols);
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    printMatrix(diff, rows, cols);
    int mat2Cols;
    std::cout << "Enter the number of columns for Matrix 2 for multiplication: ";
    std::cin >> mat2Cols;
    int** matrix2ForMult = createMatrix(cols, mat2Cols);
    std::cout << "Enter elements for Matrix 2 (for multiplication):" << std::endl;
    fillMatrix(matrix2ForMult, cols, mat2Cols);
    int** product = multiplyMatrices(matrix1, matrix2ForMult, rows, cols, mat2Cols);
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    printMatrix(product, rows, mat2Cols);
    deleteMatrix(matrix1, rows);
    deleteMatrix(matrix2, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(diff, rows);
    deleteMatrix(matrix2ForMult, cols);
    deleteMatrix(product, rows);

    return 0;
}
