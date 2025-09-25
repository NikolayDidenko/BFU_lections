#include <iostream>
using namespace std;
// 4 ВАРИАНТ

float P = 3.1415f;
unsigned short radius; // Выбрал тип данных с припиской unsigned, так как радиус не может быть отрицательным

short sizeOfShort = sizeof(short) * 8;
short minUnsShortValue = -pow(2, 15);
short maxUnsShortValue = pow(2, 15) - 1;

int main() {
    cout << "short занимает " << sizeOfShort << " бит, мин значение = " << minUnsShortValue << ", макс значение = " << maxUnsShortValue << endl;
    cin >> radius;
    unsigned short volume = 4/3 * P * pow(radius, 3);
    unsigned short square = 4 * P * pow(radius, 2);
    cout << "Обьем сферы: " << volume << endl;
    cout << "Площадь сферы: " << square << endl;
}