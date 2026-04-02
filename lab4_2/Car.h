#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

struct Car {
    QString brand;
    QString model;
    QString year;
    QString plateNum;
    bool isPetrol;
    bool hasHeating;
    bool hasParktronic;
    bool hasMats;

    Car(QString br, QString mo, QString yr, QString pl, bool petrol, bool heating, bool park, bool mats):
        brand(br), model(mo), year(yr), plateNum(pl), isPetrol(petrol), hasHeating(heating), hasParktronic(park), hasMats(mats) {}

    void saveToFile() {
        QFile file(QDir::homePath() + "/Desktop/result.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out.setEncoding(QStringConverter::Utf8);
            out << "Автомобиль:\n";
            out << "Марка: "        << brand   << "\n";
            out << "Модель: "       << model   << "\n";
            out << "Год выпуска: "  << year    << "\n";
            out << "Гос. номер: "   << plateNum << "\n";
            out << "Двигатель: "    << (isPetrol ? "Бензин" : "Дизель") << "\n";
            out << "Опции: ";
            if (!hasHeating && !hasParktronic && !hasMats) {
                out << "нет";
            } else {
                if (hasHeating) {
                    out << "Подогрев сидений ";
                }
                if (hasParktronic){
                    out << "Парктроники ";
                }
                if (hasMats) {
                    out << "Коврики";
                }
            }
            out << "\n------------------------\n";
            file.close();
        }
    }
};

#endif
