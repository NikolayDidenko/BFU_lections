#include "lootbox.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Конструктор по умолчанию
Lootbox::Lootbox() {
    name = "Обычный лутбокс";
}

// Конструктор с параметрами
Lootbox::Lootbox(string n, vector<Player::Item> items) {
    name = n;
    possibleItems = items;
}

// Конструктор копирования
Lootbox::Lootbox(Lootbox& other) {
    name = other.name;
    possibleItems = other.possibleItems;
}

// Деструктор
Lootbox::~Lootbox() {
    possibleItems.clear();
    cout << "Лутбокс \"" << name << "\" удалён из памяти" << endl;
}

// Открыть лутбокс — случайный предмет
Player::Item Lootbox::open() {
    int randomIndex = rand() % possibleItems.size();
    Player::Item droppedItem = possibleItems[randomIndex];
    cout << "Из лутбокса \"" << name << "\" выпал предмет: " << droppedItem.itemName << endl;
    return droppedItem;
}

// Показать содержимое лутбокса
void Lootbox::show() {
    cout << "=== Лутбокс: " << name << " ===" << endl;
    cout << "Возможные предметы:" << endl;
    for (int i = 0; i < possibleItems.size(); i++) {
        cout << "  " << i + 1 << ") ";
        possibleItems[i].show();
    }
    cout << "=============================" << endl;
}