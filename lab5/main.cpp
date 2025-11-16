#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ------------------------- 4 ВАРИАНТ -------------------------

int variants(int a) {
    cout << "Использование функции для 1 числа" << endl;
    int digitCount[10] = {0};
    
    a = abs(a);
    
    int temp = a;
    while (temp > 0) {
        int digit = temp % 10;
        digitCount[digit]++;
        temp /= 10;
    }
    
    int maxDigit = -1;
    int maxCount = 0;
    
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > 0 && i > maxDigit) {
            maxDigit = i;
            maxCount = digitCount[i];
        }
    }
    return maxCount;
}

int variants(int a, int b, int c) {
    cout << "Использование функции для 3 чисел" << endl;
    if ((a != b) && (b != c) && (a != c)) {
        return ((abs(a) + abs(b) + abs(c)) / 3);
    } else {
        int minn = min({a, b, c});
        return minn;
    }
}


void Point1() {
    int items[3];
    for (int i = 0; i < 3; i++) {
        cin >> items[i];
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++){
        if (items[i] != 0) {
            cnt++;
        }
    }
    switch (cnt) {
        case 1: {
            int oneNum = 0;
            for (int i = 0; i < 3; i++) {
                if (items[i] != 0) {
                    oneNum = items[i];
                }
            }
            cout << variants(oneNum);
            break;
        }
        case 3:
            cout << variants(items[0], items[1], items[2]);
            break;
    }
}

void Point2(short r) {
    const float P = 13.1415f;

    float volume = 4/3 * P * pow(r, 3);
    short square = 4 * P * pow(r, 2);

    cout << "Обьем сферы: " << volume << endl;
    cout << "Площадь сферы: " << square << endl;
}

int main() {
    short point;
    cin >> point;


    switch (point) {
        case 1:
            Point1();
            break;
        case 2: 
            unsigned short radius;
            cin >> radius;
            Point2(radius);
            break;
    }

    return 0;
}