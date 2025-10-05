#include <iostream>
#include <cfloat>
using namespace std;
// 4 ВАРИАНТ

const float P = 13.1415f;
unsigned short radius; // Выбрал тип данных с припиской unsigned, так как радиус не может быть отрицательным

/*
Многострочный комментарий
В нем много строк
*/


short sizeOfShort = sizeof(short) * 8;
short minUnsShortValue = -pow(2, sizeOfShort - 1);
short maxUnsShortValue = pow(2, sizeOfShort - 1) - 1;

short sizeOfFloat = sizeof(float) * 8;
float minFloatValue = -FLT_MAX;
float maxFloatValue = FLT_MAX;

int main() {

    cout << "short занимает: " << sizeOfShort << " бит, мин значение = " << minUnsShortValue << ", макс значение = " << maxUnsShortValue << endl;
    cout << "float занимает: " << sizeOfFloat << " бит, мин значение = " << minFloatValue << ", макс значение = " << maxFloatValue << endl;
    cin >> radius;

    float volume = 4/3 * P * pow(radius, 3);
    short square = 4 * P * pow(radius, 2);

    cout << "Обьем сферы: " << volume << endl;
    cout << "Площадь сферы: " << square << endl;
}