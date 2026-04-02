#ifndef PASSFORM_H
#define PASSFORM_H

#include <QDialog>
#include "person.h"

class PassForm : public QDialog {
    Q_OBJECT

public:
    bool printed;

    explicit PassForm(Person* person, QWidget* parent = nullptr);

    private slots:
        void onPrintClicked();
    void onCancelClicked();
};

#endif
