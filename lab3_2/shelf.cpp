#include "shelf.h"
#include <iostream>
using namespace std;

Shelf::Shelf() {
    maxCapacity = 10;
}

Shelf::Shelf(int capacity) {
    maxCapacity = capacity;
}

Shelf::Shelf(Shelf &other) {
    maxCapacity = other.maxCapacity;
    books = other.books;
}

Shelf::~Shelf() {
    cout << "Полка удалена" << endl;
    books.clear();
}

void Shelf::addBook(Book* book) {
    if (books.size() < maxCapacity) {
        books.push_back(book);
        cout << "Книга \"" << book->getTitle() << "\" поставлена на полку." << endl;
    } else {
        cout << "Полка заполнена! Нельзя поставить книгу." << endl;
    }
}

void Shelf::sortByTitle() {
    for (int i = 0; i < books.size(); i++) {
        for (int j = 0; j < books.size() - 1; j++) {
            if (books[j]->getTitle() > books[j + 1]->getTitle()) {
                Book* temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    cout << "Книги отсортированы по названию." << endl;
}

void Shelf::show() {
    cout << "=== Полка (вместимость: " << maxCapacity << ") ===" << endl;
    cout << "Книг на полке: " << books.size() << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ") ";
        books[i]->show();
    }
    cout << "=============================" << endl;
}