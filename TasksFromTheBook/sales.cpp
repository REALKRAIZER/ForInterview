#include <iostream>
#include "sales.h"
namespace SALES
{
	void setSales(Sales & s, const double *ar, int n)
	{
		for (int i = 0; i < QUARTERS; ++i)
		{
			if (s.sales[i] == 0)
			{
				s.sales[i] = find_min(ar,n);
			}
			else
				continue;
			s.average = find_average(ar,n);
			s.min = find_min(ar,n);
			s.max = find_max(ar,n);
		}
	}
	void showSales(const Sales & s)
	{
		using namespace std;
		for (int i = 0; i< QUARTERS; ++i)
			cout << s.sales[i] << endl;
		cout << "Average: " << s.average << endl;
		cout << "Min: " << s.min << endl;
		cout << "Max: " << s.max << endl;
	}
	template <typename T> T find_min(const T *ar, int n)
	{
		T min = ar[0];
		for (int i = 1; i < n; ++i)
			if (ar[i] < min)
				min = ar[i];
		return min;
	}
	template <typename T> T find_max(const T *ar, int n)
	{
		T max = ar[0];
		for (int i = 1; i < n; ++i)
			if (ar[i] > max)
				max = ar[i];
		return max;
	}
	template <typename T> T find_average(const T *ar, int n)
	{
		T average = 0;
		for (int i = 0; i < n; ++i)
			average += ar[i];
		return average / n;
	}
}