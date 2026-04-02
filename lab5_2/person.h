#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QWidget>

struct Date {
    int day;
    int month;
    int year;
};

class Person {
public:
    // int code;
    QString lastName;
    QString firstName;
    Date birthDate;

        virtual ~Person() {}

    virtual bool Craft(QWidget* parent) = 0;

    virtual QString getFullName() = 0;

    QString getDateRu() {
        return QString("%1.%2.%3")
        .arg(birthDate.day,   2, 10, QChar('0'))
            .arg(birthDate.month, 2, 10, QChar('0'))
            .arg(birthDate.year,  4, 10, QChar('0'));
    }
};

class RuP : public Person {
public:
    QString patronymic;
        bool Craft(QWidget* parent) override;

    QString getFullName() override {
        return lastName + " " + firstName + " " + patronymic;
    }

};

class AmP : public Person {
public:
    QString middleName;

        bool Craft(QWidget* parent) override;

    QString getFullName() override {
        return firstName + " " + middleName + " " + lastName;
    }

    QString getDateAm() {
        return QString("%1-%2-%3")
        .arg(birthDate.month, 2, 10, QChar('0'))
            .arg(birthDate.day,   2, 10, QChar('0'))
            .arg(birthDate.year,  4, 10, QChar('0'));
    }

};

#endif
