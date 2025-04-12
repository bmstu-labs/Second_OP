#pragma once

#include <QtWidgets>

class Widget : public QWidget {
    Q_OBJECT
private:
    QTableWidget *dataTable;

    QPushButton *loadButton;
    QPushButton *calculateButton;

    QLabel *minimumValue;
    QLabel *maximumValue;
    QLabel *medianValue;
public:
    Widget(QWidget *parent = nullptr);

    ~Widget() = default;
public:
    void setupWidgets();

    void connectSlots();
};
