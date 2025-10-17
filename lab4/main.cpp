#include <iostream>
#include <algorithm>
using namespace std;

// ---------------------------- 4 ВАРИАНТ ----------------------------

int main() {

    // --------------- 1 задание --------------

    // int size = 7;
    // int nums[size];
    // for (int i = 0; i < size; ++i) {
    //     int el;
    //     cin >> el;
    //     nums[i] = el;
    // }
    // short cnt = 0;
    // for (int j = 0; j < size; ++j) {
    //     if (nums[j] % 5 == 0) {
    //         cnt += 1;
    //     } else if (nums[j] % 5 != 0) {
    //         cnt = 0;
    //     }
    // }
    // if (cnt == size) {
    //     for(int i = 0; i < size - 1; i++) {
    //         for(int j = 0; j < size - i - 1; j++) {
    //             if(nums[j] > nums[j + 1]) {
    //                 int temp = nums[j];
    //                 nums[j] = nums[j + 1];
    //                 nums[j + 1] = temp;
    //             }
    //         }
    //     }
    // } else {
    //     cout << "Числа не кратны 5, вот обычный массив:" << endl;
    // }
    // for (int i = 0; i < size; i++) {
    //     cout << nums[i] << " ";
    // }

    // --------------- 2 задание --------------

    int rows = 3;
    int cols = 4;
    int matrix[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int colIndex = -123;
    int maxMnCnt = 0;
    for (int i = 0; i < cols; i++) {
        int mnCnt = 0;
        for (int j = 0; j < rows; ++j) {
            if (matrix[j][i] < 0) {
                mnCnt += 1;
            }
        }
        if (mnCnt > maxMnCnt) {
            maxMnCnt = mnCnt;
            colIndex = i;
        }
    }
    if (colIndex != -123) {
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                matrix[i][colIndex] = -1;
            }
        }
    } else {
        cout << "В матрице нет ни одного отрицательного числа!" << endl;
    }
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}