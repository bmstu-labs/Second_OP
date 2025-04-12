#include "widget.hpp"

Widget::Widget(QWidget *parent) : QWidget(parent) {

}

void Widget::setupWidgets() {
    this->setFixedSize(500, 500);

    dataTable = new QTableWidget();

    loadButton = new QPushButton("Load data");
    calculateButton = new QPushButton("Calculate");

    maximumValue = new QLabel;
    minimumValue = new QLabel;
    medianValue = new QLabel;
}
