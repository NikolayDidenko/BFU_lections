#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string author;
    vector<string> works;
    int pages;
    float price;
    
    Book();
    Book(string a, vector<string> w, int p, float pr);
    
    Book operator+(Book other);
    Book operator/(Book other);
    
    void show();
};

#endif