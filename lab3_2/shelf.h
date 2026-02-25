#ifndef SHELF_H
#define SHELF_H

#include "book.h"
#include <vector>
#include <iostream>
using namespace std;

class Shelf {
public:
    vector<Book*> books;
    int maxCapacity;

    Shelf();

    Shelf(int capacity);

    Shelf(Shelf &other);

    ~Shelf();

    void addBook(Book* book);

    void sortByTitle();

    void show();
};

#endif