#include <iostream>
#include <cmath>
#include <valarray>
#define U 1
using namespace std;
template<typename ...Args>
double sum(Args ...args)
{
	valarray<double> a = {args...};
	return a.sum();

}
int main(int argc, char const *argv[])
{
	template<typename ...Types>
double Operations::math(const OpString &op, const Types&... args)
{
    std::tuple<Types...> values{args...};
    OpAction action = Operations::getAction(op);
    switch(action)
    {
    case OpAction::plus :
        return std::get<0>(values) + std::get<1>(values);
    case OpAction::minus :
        return std::get<0>(values) - std::get<0>(values);
    case OpAction::multiply :
        return std::get<0>(values) * std::get<0>(values);
    case OpAction::divide :
        return std::get<0>(values) / std::get<0>(values);
    default:
        return -1;
    }
}
	return 0;
}
/*Знаю что код ужасный, но оно работает*/