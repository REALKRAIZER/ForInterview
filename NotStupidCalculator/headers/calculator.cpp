#include "calc.h"
#include <regex>
#include <QRegExp>
#include <QList>
#include <stdexcept>
#include <iostream>
#include <QDebug>

Calculator::Calculator() : expression_("")
{

}
void Calculator::clear()
{
    while(!(stackOperands_.empty()))
        stackOperands_.pop();
    while(!stackOperations_.empty())
        stackOperations_.pop();
    expression_ = "";
}
void Calculator::setExpression(const Operations::String& str)
{
    while(!(stackOperands_.empty()))
        stackOperands_.pop();
    while(!stackOperations_.empty())
        stackOperations_.pop();
    try {
        expression_ = str;
        fill();
        notifyUpdate();
    }
    catch(const std::exception& err)
    {
        std::cerr << err.what() << std::endl;
        clear();
        return;
    }
}
bool Calculator::math()//вычисляет одну операцию
{
     if( stackOperands_.empty() || stackOperations_.empty() )
        return false;
    Operations::String strOperation = stackOperations_.top();
    stackOperations_.pop();
    if(operations_.getType(strOperation) == Operations::Type::UNARY) {
        double a;
        a = stackOperands_.top();
        stackOperands_.pop();
        stackOperands_.push(operations_.math(strOperation, a));
    }
    else if(operations_.getType(strOperation) == Operations::Type::BINARY) {
        double a, b;
        b = stackOperands_.top();
        stackOperands_.pop();
        a = stackOperands_.top();
        stackOperands_.pop();
        stackOperands_.push(operations_.math(strOperation, a, b));
    }
    return true;
}
void Calculator::fill()
{   //\\-?\\d+([,.]\\d)* //проблема : в регулярке - неправильно захватывается из за чего 2 - 3 будет = 5(в операндах 2 и -2, а в операциях -, в итоге - на - = +)
    /*Заполняем стеки строк со ВСЕМИ операциями и операндами*/
    QRegExp regexOperands("\\d+([,.]\\d)*");//дробные или целые операнды
    QStringList strListOperands;//хранит все совпадения
    int pos = 0;//указывает позицию в строке, с которой мы начинаем искать свопадения
    /* ищем все совпадения */
    while ((pos = regexOperands.indexIn(expression_, pos)) != -1) {//ищет совпадение с шаблоном и возвращает позицию первого символа совпадения(подстроки)
        strListOperands << regexOperands.cap(0);//заносим в список совпадение
        pos += regexOperands.matchedLength();//возвращает длину совпадения
    }

    QRegExp regexOperations(Operations::strRegexFormat());//все операции
    QStringList strListOperations;
    pos = 0;
    while ((pos = regexOperations.indexIn(expression_, pos)) != -1) {
        strListOperations << regexOperations.cap(0);
        pos += regexOperations.matchedLength();
    }
    char i = 0, n = 0;
    auto itOperands = strListOperands.begin();
    /*заполняем стеки с операциями и операндами, также вычисляем отдельные операции
      для "выравнивания" их приоритетов в стеке*/
    for(const auto& itOperations : strListOperations)
    {
        while ((!stackOperands_.empty() && !stackOperations_.empty()) &&
                (operations_.getPriority(itOperations) <= operations_.getPriority(stackOperations_.top())) )
            math();

        stackOperations_.push(itOperations);
        if(operations_.getType(stackOperations_.top()) == Operations::Type::UNARY)
            n = 0;
        else if(operations_.getType(stackOperations_.top()) == Operations::Type::BINARY)
            n = 1;
        if(stackOperands_.empty())
            ++n;
        for(i = 0; i < n ; ++i)
        {
            if(itOperands == strListOperands.end())
                return;
            double a = itOperands->toDouble();
            stackOperands_.push(a);
            ++itOperands;
        }
    }
    while(math()) {};//вычисляем оставшиеся операции(остались только с одним приоритетом)
}
double Calculator::equals()
{
    if(stackOperands_.size() == 1)
        return stackOperands_.top();
    else
        return 0;
}
Operations Calculator::operations_;
