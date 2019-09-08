#include<iostream>
using namespace std;

int add(int a, int b)
{
	int c = a + b;
	return c;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

double div_(int a, int b)
{
	double c = (double)a / b;
	return c;
}

int factorial(int a)
{
	int c = 1;
	for (int b = 2; b <= a; b++)
	{
		c *= b;
	}
	return c;
}

int power(int a)
{
	int c;
	return c;
}

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int b = 3;
	int c = add(a, b);
	cout << a << "+" << b << "=" << c << endl;
	cout << sub(8, 3) << endl;
	cout << mul(5, 3) << endl;
	cout << div_(10, 4) << endl;
	cout << factorial(5) << endl;
}