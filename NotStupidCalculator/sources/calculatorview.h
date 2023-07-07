#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include "observer.h"
#include "calc.h"

class CalculatorView : public QWidget, public Observer//представление
{
    Q_OBJECT

private:
    Calculator* model_;
    QLabel*     display_;
    QString     strDisplay_;
public:
    CalculatorView(Calculator* model, QWidget* parent = nullptr);
    CalculatorView(CalculatorView &&) = delete;
    CalculatorView(const CalculatorView &) = delete;
    CalculatorView &operator=(CalculatorView &&) = delete;
    CalculatorView &operator=(const CalculatorView &) = delete;

    virtual void update();
    virtual ~CalculatorView();
private:
    QPushButton* createButton(const char *str) const ;
public slots:
    void slotButtonClicked();
};

#endif // CALCULATORVIEW_H
