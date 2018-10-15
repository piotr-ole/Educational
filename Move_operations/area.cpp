#include "area.h"


int area::number = 0;

void area::init(std::string name, std::pair<int, int>* points, int size, int col)
{
	if (col == 0)
	{
		color = 9 + number;
		if (number == 7)
			number = number + 2;
		else
			number++;
	}
	else
		color = col;
	this->name = name;
	this->size = size;
	if (points != nullptr)
	{
		this->points = new std::pair<int, int>[size];
		for (int i = 0; i < size; i++)
		{
			this->points[i] = points[i];
		}
	}
	else
		this->points = nullptr;
}

void area::info(std::string information)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << std::right << std::setw(12) << this << std::right << std::setw(22);
	if (connectedObject != nullptr)
		SetConsoleTextAttribute(hConsole, connectedObject->color);
	else
		SetConsoleTextAttribute(hConsole, 8);
	std::cout << this->connectedObject << "             ";
	SetConsoleTextAttribute(hConsole, color);
	std::cout << std::left << std::setw(30) << information << "\n";
}

void area::functionEnd()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	std::cout << "FUNCTION EXIT. Shortly a destructor of returned object will be called...\n";
}

void area::functionStart()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	std::cout << "FUNCION ENTRY.\n";
}

area::area()
{
	init(" ", nullptr, 0);
	info("Empty constructor");
}

area::area(std::string name, std::pair<int, int>* points, int n)
{
	init(name, points, n);
	info("Costructor with parameters");
}

area::area(const area& ar)
{
	connectedObject = &ar;
	init(ar.name, ar.points, ar.size);
	info("Copy constructor");
}

area::area(area&& ar)
{
	name = ar.name;
	size = ar.size;
	points = ar.points;
	color = 9 + number;
	connectedObject = &ar;
	number++;
	// this is because destructor should not be executed with releasing memory
	ar.points = nullptr;
	info("Copy constructor (moving)");
}

area::~area()
{
	if (isFromFun)
		functionEnd();
	connectedObject = nullptr;
	if (points != nullptr)
	{
		delete[] points;
		info("Destructor: release memory");
	}
	else
		info("Destructor: do nothing");
}

area& area::operator=(const area& ar)
{
	if (this != &ar)
	{
		connectedObject = &ar;
		init(ar.name, ar.points, ar.size, color);
	}
	info("Assign operator");
	return *this;
}

area& area::operator=(area&& ar) // cannot be const area&&, because we do: ar.points = nullptr
{
	if (this != &ar)
	{
		name = ar.name;
		size = ar.size;
		points = ar.points;
		connectedObject = &ar;
		ar.points = nullptr;
	}
	info("Assign operator (moving)");
	return *this;
}

area addAreas(const area& ar1, const area& ar2)
{
	area::functionStart();
	area sum;
	sum.isFromFun = true;
	sum.name = ar1.name + " + " + ar2.name;
	sum.size = ar1.size + ar2.size;
	sum.points = new std::pair<int, int>[sum.size];
	return sum;
}