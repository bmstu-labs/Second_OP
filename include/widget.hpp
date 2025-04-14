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

    // Alle Widgets sind in einem Box Layout gepackt
    // Brauch sie nicht im Destruktor freigeben
    ~Widget() = default;
public:
    void setupWidgets();

    void connectSlots();
};
