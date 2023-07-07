#ifndef WINE_INCLUDED
#define WINE_INCLUDED
#include <iostream>
#include <cstring>
#include <valarray>
template <typename T1, typename T2>
class Pair
{
private:
	T1 first;//год сбора
	T2 second;//количество бутылок
public:
	Pair() {};
	Pair(const T1 & firstVal, const T2 & secondVal) : first(firstVal), second(secondVal) {};
	T1 & getFirst () { return this->first; };
	T2 & getSecond() { return this->second; };
	void setFirst(T1 & first);
	void setSecond(T2 & second);
};
template <typename T1, typename T2>
void Pair<T1, T2>::setFirst(T1 & first)
{
	this->first = first;
}
template <typename T1, typename T2>
void Pair<T1, T2>::setSecond(T2 & second)
{
	this->second = second;
}
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
class Wine : private PairArray, private std::string
{
private:
	int years;
public:
	Wine(const char * l, int y, const int * yr, const int * bot) : std::string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {};
	Wine(const char * l, int y) : std::string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y)) {}; 
	void setBottles();
	const std::string & Label();
	void Show();
	void clear();
	int sum();
	~Wine() {};
};
void Wine::clear()
{
	years = 0;
	std::string::operator=("");
	PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));
}
void Wine::setBottles()
{
	using std::cout;
	using std::endl;
	using std::cin;
	for (int i = 0; i < years; ++i)
	{
		cout << "введите год: ";
		cin >> (PairArray::getFirst())[i];
		cout << "введите кол-во бутылок: ";
		cin >> (PairArray::getSecond())[i];
	}
}
const std::string & Wine::Label()
{
	return (const std::string &) (*this);
}
void Wine::Show()
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << (const std::string &) (*this) << endl;
	cout << "\tYear\tBottles\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "\t" << (PairArray::getFirst())[i] << "\t" << (PairArray::getSecond())[i] << endl;
	}
}
int Wine::sum()
{
	return PairArray::getSecond().sum();
}
#endif