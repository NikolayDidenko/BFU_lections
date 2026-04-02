#include "CarWindow.h"
#include "Car.h"

CarWindow::CarWindow(QWidget *parent):
    QWidget(parent)
{
    setWindowTitle("Автомастерская");
    resize(400, 420);

    brandEdit = new QLineEdit();
    modelEdit = new QLineEdit();
    yearEdit  = new QLineEdit();
    plateEdit = new QLineEdit();

    brandEdit->setPlaceholderText("HONDA");
    modelEdit->setPlaceholderText("Civic");
    yearEdit->setPlaceholderText("2002");
    plateEdit->setPlaceholderText("A123AA00");

    petrolBtn = new QRadioButton("Бензин");
    dieselBtn = new QRadioButton("Дизель");
    petrolBtn->setChecked(true);

    QHBoxLayout *engineLayout = new QHBoxLayout();
    engineLayout->addWidget(petrolBtn);
    engineLayout->addWidget(dieselBtn);
    engineLayout->addStretch();

    heatingCheck    = new QCheckBox("Подогрев сидений");
    parktronicCheck = new QCheckBox("Парктроники");
    matsCheck       = new QCheckBox("Коврики");

    QPushButton *resetButton = new QPushButton("Сброс");
    QPushButton *saveButton  = new QPushButton("Сохранить");
    resetButton->setMinimumHeight(30);
    saveButton->setMinimumHeight(30);
    resetButton->setStyleSheet("background-color: #e74c3c; color: white; font-weight: bold;");
    saveButton->setStyleSheet("background-color: #2ecc71; color: white; font-weight: bold;");

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(resetButton);
    buttonsLayout->addWidget(saveButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    mainLayout->addWidget(new QLabel("Марка"));
    mainLayout->addWidget(brandEdit);
    mainLayout->addWidget(new QLabel("Модель"));
    mainLayout->addWidget(modelEdit);
    mainLayout->addWidget(new QLabel("Год выпуска"));
    mainLayout->addWidget(yearEdit);
    mainLayout->addWidget(new QLabel("Гос. номер"));
    mainLayout->addWidget(plateEdit);
    mainLayout->addWidget(new QLabel("Двигатель"));
    mainLayout->addLayout(engineLayout);
    mainLayout->addWidget(new QLabel("Опции"));
    mainLayout->addWidget(heatingCheck);
    mainLayout->addWidget(parktronicCheck);
    mainLayout->addWidget(matsCheck);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    connect(resetButton, &QPushButton::clicked, this, &CarWindow::resetForm);
    connect(saveButton,  &QPushButton::clicked, this, &CarWindow::saveCar);
}

QString CarWindow::validateFields()
{
    QRegularExpression brandRx("^[A-ZА-ЯЁ]+$");

    if (brandEdit->text().isEmpty()) {
        return "Заполните поле 'Марка'";
    }

    if (!brandRx.match(brandEdit->text()).hasMatch()) {
        return "Поле 'Марка': только заглавные буквы (рус или англ), например HONDA или ВАЗ";
    }

    if (modelEdit->text().isEmpty()) {
        return "Заполните поле 'Модель'";
    }

    QRegularExpression yearRx("^[0-9]{4}$");

    if (yearEdit->text().isEmpty()) {
        return "Заполните поле 'Год выпуска'";
    }

    if (!yearRx.match(yearEdit->text()).hasMatch()) {
        return "Поле 'Год выпуска': ровно 4 цифры, например 2002";
    }

    QRegularExpression plateRx(
        "^[АВЕКМНОРСТУХ][0-9]{3}[АВЕКМНОРСТУХ]{2}((0[0-9]|[1-9][0-9])|101|111)$"
        );


    if (plateEdit->text().isEmpty()) {
        return "Заполните поле 'Гос. номер'";
    }

    if (!plateRx.match(plateEdit->text()).hasMatch()) {
        return "Поле 'Гос. номер': формат А111АА22 или А111АА222\n"
               "Буквы: А В Е К М Н О Р С Т У Х\n"
               "Регион из 3 цифр: только 101 или 111";
    }
    return "";
}

void CarWindow::resetForm()
{
    brandEdit->clear();
    modelEdit->clear();
    yearEdit->clear();
    plateEdit->clear();
    petrolBtn->setChecked(true);
    heatingCheck->setChecked(false);
    parktronicCheck->setChecked(false);
    matsCheck->setChecked(false);
    brandEdit->setFocus();
}

void CarWindow::saveCar()
{
    QString error = validateFields();
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", error);
        return;
    }

    Car car(
        brandEdit->text(),
        modelEdit->text(),
        yearEdit->text(),
        plateEdit->text(),
        petrolBtn->isChecked(),
        heatingCheck->isChecked(),
        parktronicCheck->isChecked(),
        matsCheck->isChecked()
        );

    car.saveToFile();
    QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
    resetForm();
}
