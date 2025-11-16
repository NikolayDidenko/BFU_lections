#include <iostream>
#include <cstdlib>
using namespace std;

int* processMatrix(int**& matrix, int& rows, int& cols, int A, int B, int C, int D) {
    int newRows = 2 + A;
    int newCols = 2 + B;

    int** newMatrix = (int**)malloc(newRows * sizeof(int*));
    for (int i = 0; i < newRows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
    }
    
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            newMatrix[i][j] = i * C + j * D;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    matrix = newMatrix;
    rows = newRows;
    cols = newCols;
    
    int* zeroRows = (int*)calloc(rows, sizeof(int));
    int zeroCount = 0;
    
    for (int i = 0; i < rows; i++) {
        bool hasZero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            zeroRows[zeroCount++] = i;
        }
    }
    
    int* result = (int*)malloc((zeroCount + 1) * sizeof(int));
    result[0] = zeroCount;
    for (int i = 1; i <= zeroCount; i++) {
        result[i] = zeroRows[i - 1];
    }
    
    free(zeroRows);
    return result;
}

void removeRows(int**& matrix, int& rows, int& cols, int* rowsToRemove) {
    int removeCount = rowsToRemove[0];
    if (removeCount == 0) {
        cout << "Нет строк для удаления." << endl;
        return;
    }
    
    int newRows = rows - removeCount;
    
    int** newMatrix = (int**)malloc(newRows * sizeof(int*));    
    int newI = 0;
    for (int i = 0; i < rows; i++) {
        bool shouldRemove = false;
        
        // Проверяем, нужно ли удалять текущую строку
        for (int k = 1; k <= removeCount; k++) {
            if (i == rowsToRemove[k]) {
                shouldRemove = true;
                break;
            }
        }
        
        if (!shouldRemove) {
            newMatrix[newI] = (int*)malloc(cols * sizeof(int));
            for (int j = 0; j < cols; j++) {
                newMatrix[newI][j] = matrix[i][j];
            }
            newI++;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        bool shouldRemove = false;
        for (int k = 1; k <= removeCount; k++) {
            if (i == rowsToRemove[k]) {
                shouldRemove = true;
                break;
            }
        }
        if (shouldRemove) {
            free(matrix[i]);
        }
    }
    free(matrix);

    matrix = newMatrix;
    rows = newRows;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void workWithPointers() {
    int a, b;

    cin >> a;
    cin >> b;
    
    int* ptrA = new int(a);
    int* ptrB = new int(b);
        
    *ptrA *= 2;
    
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    a = *ptrA;
    b = *ptrB;

    cout << "A = " << a << ", B = " << b << endl;

    delete ptrA;
    delete ptrB;
}

int main() {        
    int A, B, C, D;
    
    do {
        cout << "Введите A: ";
        cin >> A;
        if (A < 0) {
            cout << "Ошибка! A должно быть неотрицательным." << endl;
        }
    } while (A < 0);
    
    do {
        cout << "Введите B: ";
        cin >> B;
        if (B < 0) {
            cout << "Ошибка! B должно быть неотрицательным." << endl;
        }
    } while (B < 0);
    
    cin >> C;
    cin >> D;
    
    int rows = 2;
    int cols = 2;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;
    
    
    int* zeroRows = processMatrix(matrix, rows, cols, A, B, C, D);
    
    printMatrix(matrix, rows, cols);
    
    removeRows(matrix, rows, cols, zeroRows);
    
    cout << "Матрица после удаления строк с нулями:" << endl;
    printMatrix(matrix, rows, cols);
    
    free(zeroRows);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
    
    workWithPointers();
    return 0;
}