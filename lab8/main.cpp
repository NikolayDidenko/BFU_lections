#include <iostream>
#include <string>

using namespace std;

struct EndPearl;
struct MidPearl;

struct Lock {
    string name;
    string metal;
    MidPearl* first;
    EndPearl* last;
    int status;
};

struct MidPearl {
    string color;
    MidPearl* next;
};

struct EndPearl {
    string color;
    Lock* zamok;
};



Lock catalog[5];
int catalogSize = 0;

void showJewelry(Lock jewelry) {
    cout << "\n=== Украшение: " << jewelry.name << " ===" << endl;
    cout << "Металл: " << jewelry.metal << endl;
    cout << "Внешний вид: ";
    
    MidPearl* current = jewelry.first;

    if (jewelry.first == nullptr) {
        cout << "Жемчужин нет." << endl;
        return;
    }

    while (current->next != nullptr) {
        cout << "[" << current->color << "]";
        current = current->next;
    }
    
    if (jewelry.last != nullptr) {
        jewelry.status = 1;
        cout << jewelry.last->color;
    }
    
    cout << endl;
}

void showUnfinished() {
    cout << "\n=== Незаконченные украшения ===" << endl;
    
    bool found = false;
    
    for (int i = 0; i < catalogSize; i++) {
        for (int i = 0; i < catalogSize; i++) {
            if (catalog[i].status == 0) {
                found = true;
                cout << i+1 << ". " << catalog[i].name << " (" << catalog[i].metal << ")" << endl;
            }
        }
    }
    
    if (!found) {
        cout << "Незаконченных украшений нет." << endl;
    }
}

int main() {
    catalog[0].name = "Колье Королевы";
    catalog[0].metal = "золото";
    catalog[0].first = nullptr;
    catalog[0].last = nullptr;
    
    catalog[1].name = "Браслет Невесты";
    catalog[1].metal = "серебро";
    
    MidPearl* pearl1 = new MidPearl;
    pearl1->color = "белый";
    
    MidPearl* pearl2 = new MidPearl;
    pearl2->color = "розовый";
    pearl2->next = nullptr;
    pearl1->next = pearl2;
    
    catalog[1].first = pearl1;
    catalog[1].last = nullptr;
    
    catalog[2].name = "Серьги Принцессы";
    catalog[2].metal = "золото";
    
    MidPearl* pearl3 = new MidPearl;
    pearl3->color = "кремовый";
    
    EndPearl* endPearl = new EndPearl;
    endPearl->color = "черный";
    
    pearl3->next = nullptr;
    catalog[2].first = pearl3;
    catalog[2].last = endPearl;
    
    catalogSize = 3;
    
    cout << "В каталоге создано " << catalogSize << " украшения." << endl;
    
    while (true) {
        cout << "---- Меню ----" << endl;
        cout << "1. Показать внешний вид украшения" << endl;
        cout << "2. Показать незаконченные украшения" << endl;
        cout << "3. Выход" << endl;
    
        cout << "Выберите действие (1-3): ";
        int choice;
        cin >> choice;
            
        if (choice == 1) {
            int index;
            cout << "Какое украшение показать? (1-" << catalogSize << "): ";
            cin >> index;
                    
            if (index >= 1 && index <= catalogSize) {
                showJewelry(catalog[index-1]);
            } else {
                cout << "Неверный номер!" << endl;
            }
        } else if (choice == 2) {
            showUnfinished();
        } else if (choice == 3) {
            cout << "Выход из программы." << endl;
        }
    }
                
    for (int i = 0; i < catalogSize; i++) {
        MidPearl* current = catalog[i].first;
        while (current != nullptr) {
            MidPearl* temp = current;
            current = current->next;
            delete temp;
        }
        
        if (catalog[i].last != nullptr) {
            delete catalog[i].last;
        }
    }
    
    return 0;
}