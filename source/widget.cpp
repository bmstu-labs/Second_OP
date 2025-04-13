#include "widget.hpp"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    // Setup all widgets
    this->setupWidgets();
}

void Widget::setupWidgets() {
    // Buttons
    loadButton = new QPushButton("Load Data");
    calculateButton = new QPushButton("Calculate Metrics");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(calculateButton);
    buttonLayout->addStretch();

    // Table
    dataTable = new QTableWidget;
    dataTable->setColumnCount(0);
    dataTable->setRowCount(0);
    dataTable->horizontalHeader()->setStretchLastSection(true);
    dataTable->verticalHeader()->setVisible(false);
    dataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    dataTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Metric labels
    medianValue = new QLabel("Median: -");
    minimumValue = new QLabel("Minimum: -");
    maximumValue = new QLabel("Maximum: -");

    QVBoxLayout *rightControlPanel = new QVBoxLayout;
    rightControlPanel->addWidget(medianValue);
    rightControlPanel->addWidget(minimumValue);
    rightControlPanel->addWidget(maximumValue);
    rightControlPanel->addLayout(buttonLayout);
    rightControlPanel->addStretch();

    // Main layout
    QHBoxLayout *contentLayout = new QHBoxLayout;
    contentLayout->addWidget(dataTable, 3);           // 3:1 ratio for space
    contentLayout->addLayout(rightControlPanel, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(contentLayout);

    this->setLayout(mainLayout);
    this->setWindowTitle("CSV Metrics Viewer");
    this->setFixedSize(800, 500);
}


