#include "book.h"
#include "shelf.h"
#include <iostream>
#include <vector>
using namespace std;

void myLabRating() {
    cout << "========================================" << endl;
    cout << "Моя оценка лабораторной работы 4:" << endl;
    cout << "Интерес:      8/10" << endl;
    cout << "Наполненность: 8/10" << endl;
    cout << "Сложность:    7/10" << endl;
    cout << "========================================" << endl;
}

int main() {
    vector<string> works1 = {"Рассказ А", "Рассказ Б", "Рассказ В"};
    vector<string> works2 = {"Рассказ А", "Рассказ М", "Рассказ Н"};
    vector<string> works3 = {"Поэма 1", "Поэма 2"};

    Book book1("Автор А", "Сборник первый", works1, 250, 300.0f);
    Book book2("Автор А", "Сборник второй", works2, 180, 250.0f);
    Book book3("Автор Б", "Сборник поэм", works3, 120, 150.0f);

    cout << "--- Книга 1 ---" << endl;
    book1.show();

    cout << "--- Книга 2 ---" << endl;
    book2.show();

    cout << "--- Книга 3 ---" << endl;
    book3.show();

    cout << "Автор книги 1: " << book1.getAuthor() << endl;
    cout << "Цена книги 2: " << book2.getPrice() << endl;

    book1.setPrice(350.0f);
    cout << "Новая цена книги 1: " << book1.getPrice() << endl;

    book2.changePrice(50.0f);
    cout << "Цена книги 2 после изменения на +50: " << book2.getPrice() << endl;

    book1.ratePositive();
    book1.ratePositive();
    book1.rateNegative();
    cout << "Рейтинг книги 1: " << book1.getRating() << endl;

    book1.setBookmark("Синий", "Картон", 42);
    cout << "--- Книга 1 с флажком ---" << endl;
    book1.show();

    ++book1.bookmark;
    cout << "Флажок после ++: стр. " << book1.bookmark.pageNumber << endl;
    --book1.bookmark;
    cout << "Флажок после --: стр. " << book1.bookmark.pageNumber << endl;

    cout << "--- book1 + book2 ---" << endl;
    Book book4 = book1 + book2;
    book4.show();

    cout << "--- book1 += book2 ---" << endl;
    book1 += book2;
    book1.show();

    cout << "--- book2 / book3 ---" << endl;
    Book book5 = book2 / book3;
    book5.show();

    cout << "--- Копия книги 3 ---" << endl;
    Book book6 = book3;
    book6.show();

    cout << "--- Полка ---" << endl;
    Shelf shelf(5);

    shelf.addBook(&book2);
    shelf.addBook(&book3);
    shelf.addBook(&book4);
    shelf.addBook(&book1);

    shelf.show();

    cout << "--- После сортировки ---" << endl;
    shelf.sortByTitle();
    shelf.show();

    myLabRating();

    return 0;
}