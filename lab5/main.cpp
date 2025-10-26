#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ------------------------- 4 ВАРИАНТ -------------------------

void variants(int a) {
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
    cout << maxCount;
}

void variants(int a, int b, int c) {
    if ((a != b) && (b != c) && (a != c)) {
        cout << ((abs(a) + abs(b) + abs(c)) / 3);
    } else {
        int minn = min({a, b, c});
        cout << minn;
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
            variants(oneNum);
            break;
        }
        case 3:
            variants(items[0], items[1], items[2]);
            break;
    }
}

void Point2() {
    const float P = 13.1415f;
    unsigned short radius;

    cin >> radius;

    float volume = 4/3 * P * pow(radius, 3);
    short square = 4 * P * pow(radius, 2);

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
            Point2();
            break;
    }

    return 0;
}