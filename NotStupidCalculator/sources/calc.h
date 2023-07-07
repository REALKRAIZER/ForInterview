#ifndef CALC_H
#define CALC_H
#include "operations.h"
#include <QStack>
#include <stack>
#include "observer.h"

class Calculator : public Observable//модель
{
private:
    QStack<double>              stackOperands_;
    QStack<Operations::String>  stackOperations_;
    Operations::String          expression_;
    static Operations           operations_;
private:
    void fill();
    bool math();
    void clear();
public:
    Calculator();
    Calculator(Calculator &&) = delete;
    Calculator(const Calculator &) = delete;
    Calculator &operator=(Calculator &&) = delete;
    Calculator &operator=(const Calculator &) = delete;

    void setExpression(const Operations::String& str);
    double equals();
};
#endif // CALC_H
