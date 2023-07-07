#include <QApplication>
#include "calculatorview.h"
#include "calc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator model;
    CalculatorView view(&model);
    view.show();
    return a.exec();
}
