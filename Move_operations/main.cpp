#include "area.h"
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void table()
{
		SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
	std::cout << std::internal << std::setw(15) << "RETURNED ADRESS" << std::setw(22)
		<< "SOURCE ADRESS" << std::setw(25) << "CALLED" << std::setw(13) << " \n";
	SetConsoleTextAttribute(hConsole, 12);
}

int main()
{
	table();
	std::pair<int, int> points[] = { {2,3}, {0,1}, {3, 4} };
	area ar1;
	area ar2("Zoo", points, 3);
	area ar3(ar2);
	area ar4 = addAreas(ar2, ar3);
	ar4 = ar2;
	ar1 = addAreas(ar2, ar3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	std::cout << "\nEND OF MAIN\n\n";
}