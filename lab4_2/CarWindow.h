#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

class CarWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CarWindow(QWidget *parent = nullptr);

private slots:
    void resetForm();
    void saveCar();

private:
    QLineEdit *brandEdit;
    QLineEdit *modelEdit;
    QLineEdit *yearEdit;
    QLineEdit *plateEdit;

    QRadioButton *petrolBtn;
    QRadioButton *dieselBtn;

    QCheckBox *heatingCheck;
    QCheckBox *parktronicCheck;
    QCheckBox *matsCheck;

    QString validateFields();
};

#endif
