#include "widget.hpp"
#include "entry.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    // Setup context
    execute(CONTEXT_INIT, &this->context);

    // Setup all widgets
    this->setupWidgets();
}

void Widget::setupWidgets() {
    // Buttons
    loadButton = new QPushButton("Load Data");
    loadButton->setFixedHeight(50);
    calculateButton = new QPushButton("Calculate Metrics");
    calculateButton->setFixedHeight(50);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
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

    // Metric input lines (copyable)
    medianValue = new QLineEdit;
    medianValue->setReadOnly(true);
    medianValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    minimumValue = new QLineEdit;
    minimumValue->setReadOnly(true);
    minimumValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    maximumValue = new QLineEdit;
    maximumValue->setReadOnly(true);
    maximumValue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // Metrics layout using QFormLayout for alignment
    QFormLayout *metricsLayout = new QFormLayout;
    metricsLayout->setLabelAlignment(Qt::AlignRight);
    metricsLayout->addRow("Median:", medianValue);
    metricsLayout->addRow("Minimum:", minimumValue);
    metricsLayout->addRow("Maximum:", maximumValue);

    // Right-side control panel
    QVBoxLayout *rightControlPanel = new QVBoxLayout;
    rightControlPanel->addLayout(metricsLayout);
    rightControlPanel->addStretch();
    rightControlPanel->addLayout(buttonLayout);

    // Main layout
    QHBoxLayout *contentLayout = new QHBoxLayout;
    contentLayout->addWidget(dataTable, 2);
    contentLayout->addLayout(rightControlPanel, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(contentLayout);

    this->setLayout(mainLayout);
    this->setWindowTitle("CSV Metrics Viewer");
    this->setMinimumSize(800, 500);
}


