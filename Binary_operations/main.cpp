#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	/*Program shows how to use mask in binary operations.
	In this particular case, we hava a color in RGB encoded as hexadecimal number
	ex. ab77f7, where first two numbers are amount of Red, second two of Green and last 
	two of Blue in specyfic color. Program changes this numbers into decimals. */
	int w;
	int maska=255;
	bitset<24> b(maska);
	bitset<24> result;
	cout << "Input a hexadecimal number (ex. ab77f7): ";
	cin >> hex >> w;
	cout << "\nVersion nr 1 (manipulating number)\n\n";
	bitset<24> a(w);
	for (int i = 0; i < 3; i++)
	{
		cout << "Number: " << a << endl;
		cout << "Mask  : " << b << endl;
		cout << "Result: " << (a&b) << "  Hence as int: " << (a&b).to_ullong() << endl << endl;
		a = a >> 8;
	}
	a = bitset<24> (w);
	cout << "\nVersion nr 2 (manipulating mask)\n\n";
	for (int i = 0, j = 0; i < 3; i++, j = j + 8)
	{
		cout << "Number: " << a << endl;
		cout << "Mask  : " << b << endl;
		result = (a&b);
		cout << "Result: " << result << "  Hence as int: " << result.to_ullong() << endl;
		result = result >> j;
		cout << "Final : " << result << "  Hence as int: " << result.to_ullong() << endl << endl;
		b = b << 8;
	}
	
}