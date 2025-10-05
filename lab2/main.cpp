#include <iostream>
#include <bitset>
using namespace std;

// short A_st;
// short i;


short A;
short i;

int main() {
    // --------- 1 задание ----------
    // cin >> A;
    // cin >> i;
    // if (i < 16) {
    //     short iBit = ((A >> i) & 1);
    //     if (iBit != 0) {
    //         short B;
    //         short C;
    //         cin >> B;
    //         cin >> C;
    //         if ((A < B) & (B < C)) {
    //             cout << C - B - A << " = " << bitset<8>(C - B - A);
    //         } else if (A % C == 0) {
    //             cout << A / C + B << " = " << bitset<8>(A / C + B);
    //         } else {
    //             cout << A + B + C << " = " << bitset<8>(A + B + C);
    //         }
    //     } else {
    //         cout << (A | A) << " = " << bitset<8>(A | A);
    //     }
    // } else {
    //     cout << "i больше 16";
    // }

    // --------- 2 задание ----------
    short N;
    cin >> N;

    if ((N < 0) | (N > 12)) {
        cout << "Введен некоректный номер месяца";
    } else {
        switch (N) {
            case 1: 
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                cout << "31 день";
                break;
            case 2:
                cout << "28 дней";
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                cout << "30 дней";
                break;
        }
    }
    return 0;
}