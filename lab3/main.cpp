#include <iostream>
#include <cmath>
using namespace std;

bool found = false;

int main() {

    // --------------------- 1 задание ---------------------
    
    short minusSum = 0;
    short maxMinus = numeric_limits<short>::lowest();
    short repeats = 0;
    short N;
    cin >> N;
    short num;
    for (short i = 0; i < N; i++) {
        cin >> num;
        if (num < 0) {
            found = true;
            if (num > maxMinus) {
                maxMinus = num;
                repeats = 1;
            } else if (maxMinus == num) {
                ++repeats;
            }
            
            minusSum += num;
        }
    }
    if (found) {
        cout << maxMinus << endl;
        cout << minusSum << endl;
        cout << repeats << endl;
    } else {
        cout << "В последовательности отсутсвуют отрицательные числа";
    }    

    // --------------------- 2 задание ---------------------

    short x;
    short maxNum = 0;
    cin >> x;
    x = abs(x);
    if (x >= 1000){
        cout << "Число X больше либо равно 1000" << endl;
    } else if (x < 1000) {
        while (x != 0) {
            if ((x % 10) > maxNum) {
                maxNum = x % 10;
            }
            x /= 10;
        }
        cout << "Максимальная цифра: " << maxNum << endl;
    }
    return 0;
}