#include "mainWindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

        QVBoxLayout* layout = new QVBoxLayout(central);

    table = new QTableWidget();
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"ФИО", "Дата рождения", "Тип"});
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    table->setColumnWidth(1, 130);
    table->setColumnWidth(2, 60);

    loadBtn = new QPushButton("Загрузить");
    loadBtn->setStyleSheet(
        "padding: 8px; font-size: 14px; font-weight: bold;"
        "background-color: #555; color: white; border-radius: 4px;"
        );

    layout->addWidget(table);
    layout->addWidget(loadBtn);

    setWindowTitle("Лабораторная работа 5 — Пропуска");
    resize(560, 400);

    connect(loadBtn, &QPushButton::clicked,
            this,    &MainWindow::onLoadClicked);

    connect(table, &QTableWidget::cellDoubleClicked,
            this,  &MainWindow::onTableDoubleClicked);

}

MainWindow::~MainWindow() {
    for (Person* p : persons) {
        delete p;
    }
}

void MainWindow::onLoadClicked() {
    QString filename = QFileDialog::getOpenFileName(
        this, "Открыть файл с данными", "", "Text files (*.txt);;All files (*)"
    );
    if (filename.isEmpty()) return;
        loadFromFile(filename);
    fillTable();

}

void MainWindow::loadFromFile(QString filename) {
    for (Person* p : persons) delete p;
    persons.clear();

        QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QTextStream in(&file);

    in.setEncoding(QStringConverter::Utf8);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList p = line.split(" ");

        if (p.size() < 8) continue;

        QString type = p[0];
        int code     = p[1].toInt();

        if (type == "R") {
            RuP* person    = new RuP();
            person->code   = code;
            person->lastName  = p[2];
            person->firstName = p[3];
            person->patronymic = p[4];
            person->birthDate.day   = p[5].toInt();
            person->birthDate.month = p[6].toInt();
            person->birthDate.year  = p[7].toInt();
            persons.push_back(person);

        } else if (type == "A") {
            AmP* person    = new AmP();
            person->code   = code;
            person->firstName  = p[2];
            person->middleName = p[3];
            person->lastName   = p[4];
            person->birthDate.month = p[5].toInt();
            person->birthDate.day   = p[6].toInt();
            person->birthDate.year  = p[7].toInt();
            persons.push_back(person);
        }
    }

    file.close();

}

void MainWindow::fillTable() {
    table->setRowCount(0);
    for (int i = 0; i < (int)persons.size(); i++) {
        table->insertRow(i);
        Person* p = persons[i];

        table->setItem(i, 0, new QTableWidgetItem(p->getFullName()));

        table->setItem(i, 1, new QTableWidgetItem(p->getDateRu()));

        RuP* rup = dynamic_cast<RuP*>(p);
        QString typeName = (rup != nullptr) ? "RuP" : "AmP";
        table->setItem(i, 2, new QTableWidgetItem(typeName));
    }

}

void MainWindow::onTableDoubleClicked(int row, int col) {
    if (row < 0 || row >= (int)persons.size()) return;

        bool shouldRemove = persons[row]->Craft(this);

    if (shouldRemove) {
        delete persons[row];
        persons.erase(persons.begin() + row);
        fillTable();
    }
}
