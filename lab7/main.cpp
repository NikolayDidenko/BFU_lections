#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

// ВАРИАНТ 4

// ---------------- П1 (vector) ----------------

void printVector(const vector<int>& msv) {
    cout << "[";
    for (int i = 0; i < msv.size(); i++) {
        cout << msv[i];
        if (i + 1 < msv.size()) {
            cout << " ";
        }
    }
    cout << "]\n";
}

void pushFront(vector<int>& msv, int x) {
    msv.insert(msv.begin(), x);
}

void pushBack(vector<int>& msv, int x) {
    msv.push_back(x);
}

void clearVector(vector<int>& msv) {
    msv.clear();
}

vector<int> findElements(const vector<int>& msv, int x) {
    vector<int> idx;
    for (int i = 0; i < msv.size(); i++) {
        if (msv[i] == x) {
            idx.push_back(i);
        }
    }
    return idx;
}

void variant4(vector<int>& msv) {
    int mn = 999999;

    for (int i = 0; i < msv.size(); i++) {
        int x = msv[i];
        if (x != 0 && abs(x) < abs(mn)) {
            mn = x;
        }
    }

    if (mn == 999999) {
        return;
    }

    for (int i = 0; i < abs(mn); i++) {
        msv.push_back(0);
    }
}


// ---------------- П2 (array) ----------------

/* По значению: 
    -Неэффективно;
    -Cоздается абсолютно новая копия всего массива в другом месте памяти, d;
    -Все изменения (например, сортировка) будут применены к копии и исчезнут после завершения работы функции;
*/
void sortByValue(array<int,10> arr) {
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

/* По ссылке: 
    -Функция получает прямой доступ к оригинальному массиву;
    -Очень быстрый способ передачи;
    -Ссылка всегда должна указывать на существующий объект;
*/
void sortByReference(array<int,10>& arr) {
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 9; j++) { 
            if (arr[j] > arr[j+1]) { 
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

/* По указателю: 
    -Функция получает только адрес (указатель) первого элемента или всего объекта;
    -Указатель может быть "пустым" (nullptr).;
*/
void sortByPointer(array<int,10>* arr) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            if ((*arr)[j] > (*arr)[j+1])
                swap((*arr)[j], (*arr)[j+1]);
}

int main() {
    vector<int> msv = {100, 23, 23, 52, 54};

    while (true) {
        cout << "Меню:" << endl;
        cout << "0. Выход" << endl;
        cout << "1. Просмотр массива" << endl;
        cout << "2. Добавить в начало" << endl;
        cout << "3. Добавить в конец" << endl;
        cout << "4. Очистить" << endl;
        cout << "5. Поиск элемента" << endl;
        cout << "6. Задание варианта 4" << endl;
        cout << "7. Сортировки массива (array)" << endl;
        cout << "Ваш выбор: ";
        
        int pnt;
        cin >> pnt;

        if (pnt == 0) break;

        if (pnt == 1) printVector(msv);
        else if (pnt == 2) {
            int x; cout << "Введите число: "; 

            cin >> x;

            cout << "До: "; 
            printVector(msv);
            pushFront(msv, x);

            cout << "После: "; 
            printVector(msv);
        }
        else if (pnt == 3) {
            int x; cout << "Введите число: ";

            cin >> x;

            cout << "До: "; 
            printVector(msv);
            pushBack(msv, x);

            cout << "После: "; 
            printVector(msv);
        }
        else if (pnt == 4) {
            cout << "До: "; 
            printVector(msv);
            clearVector(msv);

            cout << "После: "; 
            printVector(msv);
        }
        else if (pnt == 5) {
            int x; 
            cout << "Введите элемент: "; 
            cin >> x;
            printVector(findElements(msv, x));
        }
        else if (pnt == 6) {
            cout << "До: "; 
            printVector(msv);
            variant4(msv);
            cout << "После: "; 
            printVector(msv);
        }
        else if (pnt == 7) {
            array<int,10> arr = {3,-1,5,0,-2,9,7,-3,4,1};

            array<int,10> a1 = arr, a2 = arr, a3 = arr;

            sortByValue(a1);
            sortByReference(a2);
            sortByPointer(&a3);

            cout << "sortByValue: ";
            for (int i = 0; i < a1.size(); i++) {
                cout << i << " ";
            }
            cout << endl;

            cout << "sortByReference: ";
            for (int i = 0; i < a2.size(); i++) {
                cout << i << " ";
            }
            cout << endl;

            cout << "sortByPointer: ";
            for (int i = 0; i < a3.size(); i++) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

