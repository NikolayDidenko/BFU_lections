#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Book {
public:
    string author;
    string title;
    vector<string> works;
    int pages;
    float price;
    int rating;

    struct Bookmark {
        string color;
        string material;
        int pageNumber;

        Bookmark() {
            color = "Красный";
            material = "Бумага";
            pageNumber = 1;
        }

        Bookmark(string c, string m, int p) {
            color = c;
            material = m;
            pageNumber = p;
        }

        Bookmark operator++() {
            pageNumber = pageNumber + 1;
            return *this;
        }

        Bookmark operator--() {
            pageNumber = pageNumber - 1;
            return *this;
        }

        void show() {
            cout << "Флажок: цвет=" << color << ", материал=" << material << ", стр." << pageNumber << endl;
        }
    };

    bool hasBookmark;
    Bookmark bookmark;

    Book();
    Book(string a, string t, vector<string> w, int p, float pr);
    Book(Book &other);

    ~Book();

    string getAuthor();
    string getTitle();
    int getPages();
    float getPrice();
    int getRating();
    vector<string> getWorks();

    void setAuthor(string a);
    void setTitle(string t);
    void setPages(int p);
    void setPrice(float pr);
    void setRating(int r);
    void setWorks(vector<string> w);

    void changePrice(float x);
    void ratePositive();
    void rateNegative();
    void setBookmark(string color, string material, int page);
    void show();

    Book operator+(Book other);
    Book operator+=(Book other);
    Book operator/(Book other);
};

#endif