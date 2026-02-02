#include "Book.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Book::Book() {
    author = "Неизвестно";
    works = {};
    pages = 0;
    price = 0;
}

Book::Book(string a, vector<string> w, int p, float pr) {
    author = a;
    works = w;
    pages = p;
    price = pr;
}

Book Book::operator+(Book other) {
    Book result;
    
    if (author == other.author) {
        result.author = author;
    } else {
        result.author = author + " и " + other.author;
    }
    
    result.pages = pages + other.pages;
    
    result.price = (price + other.price) * 0.85f;
    
    result.works = works;
    
    for (int i = 0; i < other.works.size(); i++) {
        bool findd = false;
        for (int j = 0; j < works.size(); j++) {
            if (other.works[i] == works[j]) {
                findd = true;
                break;
            }
        }
        if (!findd) {
            result.works.push_back(other.works[i]);
        }
    }
    
    return result;
}

Book Book::operator/(Book other) {
    Book result;
    
    if (author == other.author) {
        result.author = author;
    } else {
        result.author = author + " и " + other.author;
    }
    
    result.pages = (pages + other.pages) * 0.7f;
    
    result.price = (price + other.price) * 1.1f;
    
    srand(time(0));
    
    for (int i = 0; i < works.size(); i++) {
        int random_index = rand() % 2;
        
        if (random_index == 1) {
            result.works.push_back(works[i]);
        }
    }
    
    for (int i = 0; i < other.works.size(); i++) {
        int random_index = rand() % 2;
        
        if (random_index == 1) {
            bool findd = false;
            for (int j = 0; j < result.works.size(); j++) {
                if (other.works[i] == result.works[j]) {
                    findd = true;
                    break;
                }
            }
            if (!findd) {
                result.works.push_back(other.works[i]);
            }
        }
    }
    
    if (result.works.size() == 0) {
        if (works.size() > 0) {
            result.works.push_back(works[0]);
        }
    }
    
    return result;
}

void Book::show() {
    cout << "Автор: " << author << endl;
    cout << "Страниц: " << pages << endl;
    cout << "Цена: " << price << " руб." << endl;
    cout << "Произведения: ";
    for (int i = 0; i < works.size(); i++) {
        cout << works[i];
        if (i != works.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl << "---------------------" << endl;
}