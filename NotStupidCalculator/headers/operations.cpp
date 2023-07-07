#include "operations.h"
#include <QVector>

Operations::Action Operations::getAction(const Operations::String& strOperation) const
{
    auto it = this->operationInfo.find(strOperation);
    if(it != this->operationInfo.end())
        return it.value().getAction();
    else
        throw std::invalid_argument("Operations::getAction");
}
Operations::Type Operations::getType(const Operations::String& strOperation) const
{
    auto it = this->operationInfo.find(strOperation);
    if(it != this->operationInfo.end())
        return it.value().getType();
    else
        throw std::invalid_argument("Operations::getType");
}
int Operations::getPriority(const Operations::String& strOperation) const
{
    auto it = this->operationInfo.find(strOperation);
    if(it != this->operationInfo.end())
       return it.value().getPriority();
    else
       throw std::invalid_argument("Operations::getPriority");
}
Operations::OperationInfo Operations::operationInfo = {
    {"+", OperationDescription(Action::PLUS, Type::BINARY, 1)},
    {"-", OperationDescription(Action::MINUS, Type::BINARY, 1)},
    {"*", OperationDescription(Action::MULTIPLY, Type::BINARY, 2)},
    {"/", OperationDescription(Action::DIVIDE, Type::BINARY, 2)},
    {"%", OperationDescription(Action::PERCENT, Type::UNARY, 3)}
};

