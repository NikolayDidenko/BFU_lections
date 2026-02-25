#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    srand(time(0));

    vector<char> items1;
    items1.push_back('a');
    items1.push_back('b');
    items1.push_back('c');
    items1.push_back('d');
    
    vector<char> items2;
    items2.push_back('a');
    items2.push_back('c');
    items2.push_back('x');
    items2.push_back('y');
    
    Player p1("Г1", 10, 10, 100, items1);
    Player p2("Г2", 0, 0, 100, items2);
    
    cout << "Игрок 1: ";
    p1.show();
    cout << "Игрок 2: ";
    p2.show();
    
    cout << endl << "Результаты операций:" << endl;
    
    Player p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.show();
    
    Player p4 = p1 - p2;
    cout << "p1 - p2 = ";
    p4.show();
    
    Player p5 = p1 / p2;
    cout << "p1 / p2 = ";
    p5.show();
    
    Player p6(p1);      
    Player p7 = p2;    
    p6.show();
    p7.show();

    return 0;
}