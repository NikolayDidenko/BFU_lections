#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Конструктор по умолчанию
Player::Player() {
    name = "Unknown";
    posX = 0;
    posY = 0;
    hp = 100;
    actionStatus = "Стоит";
}

// Конструктор с параметрами
Player::Player(string n, int x, int y, int h, string status) {
    name = n;
    posX = x;
    posY = y;
    hp = h;
    actionStatus = status;
}

// Конструктор копирования
Player::Player(Player& other) {
    name = other.name;
    posX = other.posX;
    posY = other.posY;
    hp = other.hp;
    actionStatus = other.actionStatus;
    backpack = other.backpack;
}

// Деструктор
Player::~Player() {
    backpack.clear();
    cout << "Игрок \"" << name << "\" удалён из памяти" << endl;
}

// Геттеры
string Player::getName() { return name; }
int Player::getPosX() { return posX; }
int Player::getPosY() { return posY; }
int Player::getHp() { return hp; }
string Player::getActionStatus() { return actionStatus; }
vector<Player::Item> Player::getBackpack() { return backpack; }

// Сеттеры
void Player::setName(string n) { name = n; }
void Player::setPosX(int x) { posX = x; }
void Player::setPosY(int y) { posY = y; }
void Player::setHp(int h) { hp = h; }
void Player::setActionStatus(string status) { actionStatus = status; }
void Player::setBackpack(vector<Item> items) { backpack = items; }

// Получить X урона
void Player::takeDamage(int x) {
    hp = hp - x;
    if (hp < 0) {
        hp = 0;
    }
    cout << name << " получил " << x << " урона. HP: " << hp << endl;
}

// Лечение на X HP
void Player::heal(int x) {
    hp = hp + x;
    cout << name << " вылечился на " << x << ". HP: " << hp << endl;
}

// Открытие лутбокса — случайный предмет идёт в инвентарь
void Player::openLootbox(string lootboxName, vector<Item> possibleItems) {
    if (possibleItems.size() == 0) {
        cout << "Лутбокс пустой!" << endl;
        return;
    }

    int randomIndex = rand() % possibleItems.size();
    Item droppedItem = possibleItems[randomIndex];

    backpack.push_back(droppedItem);

    cout << name << " открыл лутбокс \"" << lootboxName << "\" и получил: " << droppedItem.itemName << endl;
}

// Показать информацию об игроке
void Player::show() {
    cout << "Имя: " << name << endl;
    cout << "Позиция: X=" << posX << " Y=" << posY << endl;
    cout << "HP: " << hp << endl;
    cout << "Статус: " << actionStatus << endl;
    cout << "Инвентарь (" << backpack.size() << " предметов):" << endl;
    if (backpack.size() == 0) {
        cout << "  Инвентарь пуст" << endl;
    }
    for (int i = 0; i < backpack.size(); i++) {
        cout << "  " << i + 1 << ") ";
        backpack[i].show();
    }
    cout << "---------------------" << endl;
}

// operator+ — объединить двух игроков
Player Player::operator+(Player other) {
    Player result;

    result.name = name + " и " + other.name;
    result.posX = (posX + other.posX) / 2;
    result.posY = (posY + other.posY) / 2;
    result.hp = hp + other.hp;
    result.actionStatus = "Объединились";

    result.backpack = backpack;

    for (int i = 0; i < other.backpack.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.backpack.size(); j++) {
            if (other.backpack[i].itemName == result.backpack[j].itemName) {
                found = true;
                break;
            }
        }
        if (found == false) {
            result.backpack.push_back(other.backpack[i]);
        }
    }

    return result;
}

// operator- — вычесть одного игрока из другого
Player Player::operator-(Player other) {
    Player result;

    result.name = name;
    result.posX = posX;
    result.posY = posY;
    result.hp = hp - other.hp / 2;
    if (result.hp < 0) {
        result.hp = 0;
    }
    result.actionStatus = "Проиграл бой";

    result.backpack = backpack;

    for (int i = 0; i < other.backpack.size(); i++) {
        for (int j = 0; j < result.backpack.size(); j++) {
            if (result.backpack[j].itemName == other.backpack[i].itemName) {
                for (int k = j; k < result.backpack.size() - 1; k++) {
                    result.backpack[k] = result.backpack[k + 1];
                }
                result.backpack.pop_back();
                break;
            }
        }
    }

    return result;
}

// operator/ — разделить инвентарь между двумя игроками
Player Player::operator/(Player other) {
    Player result;

    result.name = name + " (часть)";
    result.posX = posX;
    result.posY = posY;
    result.hp = hp / 2;
    result.actionStatus = "Разделился";

    int half = backpack.size() / 2;
    for (int i = 0; i < half; i++) {
        result.backpack.push_back(backpack[i]);
    }

    int half2 = other.backpack.size() / 2;
    for (int i = half2; i < other.backpack.size(); i++) {
        result.backpack.push_back(other.backpack[i]);
    }

    return result;
}