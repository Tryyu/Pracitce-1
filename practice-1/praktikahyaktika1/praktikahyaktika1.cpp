#include <iostream>
using namespace std;

union bitDouble { double number; unsigned long int bit[2]; };
union bitFloat { float number; unsigned long int bit; };

void outFloat(unsigned long int num)
{
	for (int i = sizeof(unsigned long int) * 8 - 1; i >= 0; --i)
	{
		cout << ((num >> i) & 1);
		if ((i == sizeof(unsigned long int) * 8 - 1) || (i == sizeof(unsigned long int) * 8 - 9))
			cout << ' ';
	}
	cout << endl;
}
void outDouble(unsigned long int* num) 
{
	for (int i = 1; i >= 0; i--)
	{
		for (int j = sizeof(unsigned long int) * 8 - 1; j >= 0; j--) {
			cout << ((num[i] >> j) & 1);
			if ((i == 1) && ((j == sizeof(unsigned long int) * 8 - 1) || (j == sizeof(unsigned long int) * 8 - 12)))
				cout << ' ';
		}
	}
	cout << endl;
}
void outInt(int num)
{
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		cout << ((num >> i) & 1);
		if (i == sizeof(int) * 8 - 1)
			cout << ' ';
	}
	cout << endl;
}
void showSpace()
{
	int in;
	short int insh;
	long int lin;
	float fl;
	double db;
	long double ldb;
	char ch;
	bool bl;
		cout << "Memory size of integer" << " = " << sizeof in << "\n";
		cout << "Memory size of short integer" << " = " << sizeof insh << "\n";
		cout << "Memory size of long integer" << " = " << sizeof lin << "\n";
		cout << "Memory size of float" << " = " << sizeof fl << "\n";
		cout << "Memory size of double" << " = " << sizeof db << "\n";
		cout << "Memory size of long double" << " = " << sizeof ldb << "\n";
		cout << "Memory size of char " << " = " << sizeof ch << "\n";
		cout << "Memory size of bool" << " = " << sizeof bl << "\n";
}


int main()
{
	bitDouble Dnum;
	bitFloat Fnum;
	int Num;
	char Show;
	int choose, Ichoose;
	do
	{
		cout << "Choose what to do" << endl;
		cout << "1. To show binary converter" << endl;
		cout << "2. To show bit space" << endl;
		cout << "0. End" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Integer number" << endl;
			cin >> Num;
			outInt(Num);
			cout << "Double number" << endl;
			cin >> Dnum.number;
			outDouble(Dnum.bit);
			cout << "Float number" << endl;
			cin >> Fnum.number;
			outFloat(Fnum.bit);
			break;
		case 2:
			showSpace();
			break;
		case 0:
			break;
		}
	} while (choose != 0);
	return 0;
}