#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> works1 = {"a", "b", "v"};
    vector<string> works2 = {"a", "m", "n"};
    
    Book book1("A", works1, 25, 100.0f);
    Book book2("A", works2, 50, 100.0f);
    
    cout << "Книга 1:" << endl;
    book1.show();
    
    cout << "Книга 2:" << endl;
    book2.show();
    
    cout << "Результат book1 + book2:" << endl;
    Book book3 = book1 + book2;
    book3.show();
    
    cout << "Результат book1 / book2:" << endl;
    Book book4 = book1 / book2;
    book4.show();
    
    Book book5("B", works2, 50, 100.0f);
    cout << "\nКнига 5 (автор B):" << endl;
    book5.show();
    
    cout << "Результат book1 + book5 (разные авторы):" << endl;
    Book book6 = book1 + book5;
    book6.show();
    
    cout << "Простое копирование:" << endl;
    Book book7 = book1;
    book7.show();
    
    return 0;
}