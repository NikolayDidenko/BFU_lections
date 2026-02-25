#include "player.h"
#include "lootbox.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void myLabRating() {
    cout << "========================================" << endl;
    cout << "Моя оценка лабораторной работы 3:" << endl;
    cout << "Интерес:       8/10" << endl;
    cout << "Наполненность: 7/10" << endl;
    cout << "Сложность:     6/10" << endl;
    cout << "========================================" << endl;
}

int main() {
    srand(time(0));

    // Создаём предметы
    Player::Item sword("Меч", "Редкий", "Острый меч рыцаря");
    Player::Item shield("Щит", "Обычный", "Деревянный щит");
    Player::Item potion("Зелье", "Обычный", "Восстанавливает HP");
    Player::Item bow("Лук", "Эпический", "Эльфийский лук");
    Player::Item helmet("Шлем", "Редкий", "Железный шлем");

    // Создаём игроков тремя способами
    cout << "--- Создание игроков ---" << endl;

    Player player1("Артём", 10, 20, 100, "Бежит");
    player1.backpack.push_back(sword);
    player1.backpack.push_back(shield);

    Player player2("Никита", 5, 15, 80, "Стоит");
    player2.backpack.push_back(potion);
    player2.backpack.push_back(bow);

    Player player3(player1); // конструктор копирования

    cout << "Игрок 1:" << endl;
    player1.show();

    cout << "Игрок 2:" << endl;
    player2.show();

    cout << "Копия игрока 1:" << endl;
    player3.show();

    // Геттеры
    cout << "--- Геттеры ---" << endl;
    cout << "Имя игрока 1: " << player1.getName() << endl;
    cout << "HP игрока 2: " << player2.getHp() << endl;
    cout << "Позиция игрока 1: X=" << player1.getPosX() << " Y=" << player1.getPosY() << endl;

    // Сеттеры
    cout << "--- Сеттеры ---" << endl;
    player1.setActionStatus("Атакует");
    cout << "Новый статус игрока 1: " << player1.getActionStatus() << endl;

    // Урон и лечение
    cout << "--- Урон и лечение ---" << endl;
    player1.takeDamage(30);
    player1.heal(10);
    player2.takeDamage(200); // проверяем что HP не уходит ниже 0

    // Лутбокс
    cout << "--- Лутбокс ---" << endl;
    vector<Player::Item> lootItems;
    lootItems.push_back(helmet);
    lootItems.push_back(bow);
    lootItems.push_back(potion);

    Lootbox lootbox1("Золотой лутбокс", lootItems);
    lootbox1.show();

    // Игрок открывает лутбокс — предмет идёт в инвентарь
    Player::Item dropped = lootbox1.open();
    player1.backpack.push_back(dropped);

    cout << "Инвентарь игрока 1 после лутбокса:" << endl;
    player1.show();

    // Конструктор копирования лутбокса
    Lootbox lootbox2(lootbox1);
    cout << "Копия лутбокса:" << endl;
    lootbox2.show();

    // Операторы
    cout << "--- Оператор + ---" << endl;
    Player player4 = player1 + player2;
    player4.show();

    cout << "--- Оператор - ---" << endl;
    Player player5 = player1 - player2;
    player5.show();

    cout << "--- Оператор / ---" << endl;
    Player player6 = player1 / player2;
    player6.show();

    // Оценка лабораторной
    myLabRating();

    return 0;
}