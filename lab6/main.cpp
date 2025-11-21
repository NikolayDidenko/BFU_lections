#include <iostream>
#include <cstdlib>
using namespace std;

int* processMatrix(int**& matrix, int& rows, int& cols, int A, int B, int C, int D) {
    int newRows = 2 + A;
    int newCols = 2 + B;

    int savedA = matrix[0][0];
    int savedB = matrix[0][1]; 
    int savedC = matrix[1][0];
    int savedD = matrix[1][1];

    matrix = (int**)realloc(matrix, newRows * sizeof(int*));
    for(int i = 0; i < newRows; i++) {
        if(i < rows) {
            matrix[i] = (int*)realloc(matrix[i], newCols * sizeof(int));
            for(int j = cols; j < newCols; j++) {
                matrix[i][j] = 0;
            }
        } else {
            matrix[i] = (int*)calloc(newCols, sizeof(int));
        }
    }

    rows = newRows;
    cols = newCols;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i >= A && j >= B) {
                matrix[i][j] = matrix[i - A][j - B];
            }
            else {
                matrix[i][j] = i * C + j * D;
            }
        }
    }
    
    matrix[A][B] = savedA; 
    matrix[A][B+1] = savedB;
    matrix[A+1][B] = savedC;
    matrix[A+1][B+1] = savedD;
    
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
                break;
            }
        }
    }
    
    int* result = (int*)malloc((zeroCount + 1) * sizeof(int));
    result[0] = zeroCount;
    
    int resultIndex = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                result[resultIndex++] = i;
                break;
            }
        }
    }
    
    return result;
}

void removeRows(int**& matrix, int& rows, int& cols, int* rowsToRemove) {
    int removeCount = rowsToRemove[0];
    if (removeCount == 0) {
        cout << "Нет строк для удаления." << endl;
        return;
    }
    
    for (int k = 1; k <= removeCount; k++) {
        int rowToRemove = rowsToRemove[k];
        if (rowToRemove < rows && matrix[rowToRemove] != NULL) {
            free(matrix[rowToRemove]);
            matrix[rowToRemove] = NULL;
        }
    }
    
    int newIndex = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i] != NULL) {
            if (newIndex != i) {
                matrix[newIndex] = matrix[i];
                matrix[i] = NULL;
            }
            newIndex++;
        }
    }
    
    if (newIndex > 0) {
        int** temp = (int**)realloc(matrix, newIndex * sizeof(int*));
        if (temp != NULL) {
            matrix = temp;
        }
        rows = newIndex;
    } else {
        free(matrix);
        matrix = NULL;
        rows = 0;
    }
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
    
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, rows, cols);
    
    int* zeroRows = processMatrix(matrix, rows, cols, A, B, C, D);
    
    cout << "Матрица после processMatrix:" << endl;
    printMatrix(matrix, rows, cols);
    
    removeRows(matrix, rows, cols, zeroRows);
    
    cout << "Матрица после удаления строк с нулями:" << endl;
    printMatrix(matrix, rows, cols);
    
    free(zeroRows);

    if (matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i] != NULL) {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
    
    workWithPointers();

    return 0;
}
