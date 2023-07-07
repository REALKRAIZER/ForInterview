#include "vect.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
int main(int argc, char const *argv[])
{
	using namespace VECTOR;
	using namespace std;
	Vector result, step;
	short stepLen, distance;
	short temp;
	unsigned int steps = 0;
	ofstream file;
	file.open("temp.txt");
	while (1)
	{
		cout << "Введите длину шага: ";
		if (!(cin >> stepLen)) {
			cin.clear();
			while (cin.get() != '\n') {};
			continue;
		}
		cout << "Введите расстояние: ";
		if (!(cin >> distance)) {
			cin.clear();
			while (cin.get() != '\n') {};
			continue;
		}
		break;
	} 
	file << "Distance: " << distance << " Step: " << stepLen << std::endl;
	srand(time(NULL));
	while (result.getLength() < distance)
	{
		file << steps << ": " << result << std::endl;

		temp = rand() % 361;
		step.reset(stepLen, temp, Vector::POL);
		result = result + step;
		++steps;
	}
	file << "Понадобилось " << steps << " шагов" << std::endl;
	file << "Среднее расстояние на 1 шаг: " << result.getLength() / steps << std::endl;
	file.close();
	return 0;
}