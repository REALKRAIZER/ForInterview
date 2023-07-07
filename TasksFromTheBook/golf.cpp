#include "golf.h"
#include <cstring>
#include <iostream>
golf::golf(const char * name, int hc)
{
	strncpy(m_fullname,name,Len);
	m_handicap = hc;
}
int golf::setgolf()
{
	std::cout << "Введите имя: ";
	std::cin.getline(m_fullname,Len);
	if(strlen(m_fullname) > 0)
	{
		std::cout << "Введите гандикап: ";
		(std::cin >> m_handicap).get();
		return 1;
	}
	else 
		return 0;
}
void golf::handicap(int hc)
{
	m_handicap = hc;
}
void golf::showgolf() const
{
	std::cout << m_fullname << std::endl;
	std::cout << m_handicap << std::endl;
}