#include <iostream>
#include <string>
using namespace std;
// 4 вариант
class Book {
    private:
        string author;
        string title;
        int pageCount;
        float rating;
        float cost;
        void validateRating() {
            if (rating < 0.0) {
                rating = 0.0;
            }
            if (rating > 5.0) {
                rating = 5.0;
            }
        }
        void validateCost() {
            if (cost < 0) {
                cost = 0;
            }
        }
        void validateRating() {
            if (rating < 0) {
                rating = 0;
            }
        }
    public:
        Book() {
            author = "Unknown";
            title = "Untitled";
            pageCount = 0;
            rating = 0.0;
            cost = 0.0;
        }

        Book(string a, string t, int pages, float r, float c) {
            author = a;
            title = t;
            pageCount = pages;
            rating = r;
            cost = c;
            validateRating();
        }

        Book(const Book &other) {
            author = other.author;
            title = other.title;
            pageCount = other.pageCount;
            rating = other.rating;
            cost = other.cost;
        }

        ~Book() {
            cout << "Run_Destructor" << endl;
        }

        string getAuthor() { 
            return author; 
        }
        string getTitle() { 
            return title; 
        }
        int getPageCount() { 
            return pageCount; 
        }
        float getRating() { 
            return rating; 
        }
        float getCost() { 
            return cost; 
        }

        void setRating(float r) {
            rating = r;
            validateRating();
            cout << "Оценка книги '" << title << "' изменена на " << rating << endl;
        }

        void changeCost(float newCost) {
            if (newCost >= 0) {
                cost = newCost;
                cout << "Стоимость книги '" << title << "' изменена на " << cost << endl;
            } else {
                cout << "Цена не может быть отрицательной!" << endl;
            }
        }

        void printInfo() {
            cout << "=== Карточка книги ===" << endl;
            cout << "Автор: " << author << endl;
            cout << "Название: " << title << endl;
            cout << "Страниц: " << pageCount << endl;
            cout << "Рейтинг: " << rating << "/5.0" << endl;
            cout << "Цена: " << cost << " руб." << endl;
        }
};

int main() {
    Book book1("Дж. Оруэлл", "1984", 320, 4.9, 500.0);
    book1.printInfo();
    cout << "   " << endl;
    Book book2 = book1;
    book2.changeCost(650.0);
    book2.setRating(10.0);
    book2.printInfo();
    cout << "   " << endl;
    Book book3;
    book3.printInfo();

    return 0;
}