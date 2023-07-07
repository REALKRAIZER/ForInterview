#include "calculatorview.h"
#include "operations.h"
#include <sstream>
#include <iostream>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QFont>
#include <QObject>
CalculatorView::CalculatorView(Calculator* model, QWidget* parent) : QWidget(parent), model_(model)
{
    model_->addObserver(this);

    const unsigned int kHeightTopLayout = 1;

    display_ = new QLabel;
    display_->setFont(QFont("Arial", 20));
    display_->setMinimumSize(150, 100);
    display_->setAlignment(Qt::AlignRight);

    const char* arrNameButtons[][4] = {
        {"AC", "<--", "%", "/"},
        {"7",  "8",   "9", "*"},
        {"4",  "5",   "6", "+"},
        {"1",  "2",   "3", "-"},
        {"0",  ".",   "=", NULL}
    };

    QGridLayout* pTopLayout = new QGridLayout;
    pTopLayout->setSpacing(0);
    pTopLayout->setContentsMargins(0, 5, 0, 0);
    pTopLayout->addWidget(display_, 0, 0, kHeightTopLayout, 4);

    for(unsigned int i = 0; i < sizeof(arrNameButtons) / sizeof(arrNameButtons[0]); ++i) {
        for(unsigned int j = 0; j < sizeof(arrNameButtons[0]) / sizeof(char*); ++j) {
            if(arrNameButtons[i][j] != NULL)
                pTopLayout->addWidget(createButton(arrNameButtons[i][j]), i + kHeightTopLayout, j);
        }
    }
    this->setLayout(pTopLayout);
}
QPushButton* CalculatorView::createButton(const char* str) const
{
    QPushButton* pButton = new QPushButton(str);
    pButton->setMinimumSize(50, 75);
    connect(pButton, &QPushButton::clicked, this, &CalculatorView::slotButtonClicked);
    return pButton;
}
void CalculatorView::slotButtonClicked()
{
    QString str = static_cast<QPushButton*>(sender())->text();

    if(QRegExp(Operations::strRegexFormat()).exactMatch(str)) {
        display_->setText(display_->text() + str);
    }
    else if(QRegExp("[0-9]").exactMatch(str)) {
        display_->setText(display_->text() + str);
    }
    else if(str == ".") {
        if(!display_->text().isEmpty())
            display_->setText(display_->text() + str);
    }
    else if(str == "=") {
        model_->setExpression(display_->text());
    }
    else if(str == "AC") {
        display_->clear();
    }
    else if(str == "<--") {
        QString resultText = display_->text();
        resultText.chop(1);
        display_->setText(resultText);
    }
}

void CalculatorView::update()
{
    QString resultText;
    std::ostringstream ss;
    ss << model_->equals();
    resultText = ss.str().c_str();
    display_->setText(resultText);
}
CalculatorView::~CalculatorView()
{
    model_->removeObserver(this);
}
