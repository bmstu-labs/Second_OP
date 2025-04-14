#pragma once

#include <QtWidgets>

class Widget : public QWidget {
    Q_OBJECT
private:
    QPushButton *loadButton;
    QPushButton *calculateButton;

    QTableWidget *dataTable;

    QLineEdit *medianValue;
    QLineEdit *minimumValue;
    QLineEdit *maximumValue;
public:
    Widget(QWidget *parent = nullptr);

    // Alle Widgets sind in einem Box Layout gepackt
    // Brauch sie nicht im Destruktor freigeben
    ~Widget() = default;
public:
    void setupWidgets();

    void connectSlots();
};
