#pragma once

#include <QtWidgets>
#include "context.h"

class Widget : public QWidget {
    Q_OBJECT
private:
    Context context;

    QPushButton *loadButton;
    QPushButton *calculateButton;
    QTableWidget *dataTable;
    QLineEdit *medianValue;
    QLineEdit *minimumValue;
    QLineEdit *maximumValue;
public:
    Widget(QWidget *parent = nullptr);

    // Do not need to deallocating memory after the widgets
    // Because they are stored in BoxLayouts
    ~Widget() = default;
public:
    void setupWidgets();

    void connectSlots();
};
