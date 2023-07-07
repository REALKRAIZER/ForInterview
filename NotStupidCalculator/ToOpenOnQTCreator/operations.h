#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <QMultiMap>
#include "observer.h"

//класс для работы с математическими операциями(можно синусы и другие функции добавить, т.к они тоже по сути операции)
class Operations
{
public:
    using String = QString;
public:
    enum class Type { //тип операции
        UNARY,
        BINARY
    };
    enum class Action { //сама операция
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        PERCENT
    };
    class OperationDescription//класс хранящий операцию и ее описание
    {
    private:
        Action  action_;
        Type    type_;
        int     priority_;
    public:
        OperationDescription(Action act, Type t, int p) : action_(act), type_(t), priority_(p) {}
        Action  getAction() const { return action_;}
        Type    getType() const { return type_;}
        int     getPriority() const { return priority_;}
    };
public:
    static const char* strRegexFormat() {return "[\\+\\-\\/\\*%]";};
    Action       getAction(const String& strOperation) const;
    Type         getType(const String& strOperation) const;
    int          getPriority(const String& strOperation) const;
    template<typename ...Types>
    double       math(const String& strOperation, const Types&... args);
public:
    using OperationInfo = QMultiMap<String, OperationDescription>;
private:
    static OperationInfo operationInfo;//используется для получения информации об операции
};

/*Принимает строку с операцией и неограниченное число операндов*/
template<typename ...Types>
double Operations::math(const Operations::String& strOperation, const Types&... args)
{
    QVector<double> values{args...};
    Action action = Operations::getAction(strOperation);
    switch(action)
    {
    case Action::PLUS :
        return values.at(0) + values.at(1);
    case Action::MINUS :
        return values.at(0) - values.at(1);
    case Action::MULTIPLY :
        return values.at(0) * values.at(1);
    case Action::DIVIDE :
        if(values.at(1) == 0)
            throw std::invalid_argument("Operations::math divide");
        return values.at(0) / values.at(1);
    case Action::PERCENT :
        return values.at(0) * 0.01;
    default:
        throw std::invalid_argument("Operations::math default");
    }
}
#endif // OPERATIONS_H
