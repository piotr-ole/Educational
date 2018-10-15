#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

class area
{
private:
	std::string name;
	int size;
	std::pair<int, int>* points;
	static int number;
	int color;
	bool isFromFun = false;
	const area* connectedObject = nullptr;

	void init(std::string name, std::pair<int, int>* points, int size, int col = 0);
	void info(std::string information);
	static void functionEnd();
	static void functionStart(); // need to be called at the beggining of each function

public:
	area();
	area(std::string name, std::pair<int, int>* points, int n);
	area(const area& ar);
	area(area&& ar);
	~area();
	area& operator=(const area& ar);
	area& operator=(area&& ar);
	friend area addAreas(const area& ar1, const area& ar2);
};

