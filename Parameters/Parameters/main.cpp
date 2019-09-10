#include<iostream>
using namespace std;

int add(int a, int b);		//Прототип (обьявление) функции - Function declaration
int sub(int a, int b);
int mul(int a, int b);
double div_(int a, int b);
int factorial(int a);
int power(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int b = 3;
	int c = add(a, b);
	cout << a << "+" << b << "=" << c << endl;
	cout << sub(8, 3) << endl;		//Вызов функции - Function call
	cout << mul(5, 3) << endl;
	cout << div_(10, 4) << endl;
	cout << factorial(5) << endl;
	cout << power(3, 6) << endl;
}

int add(int a, int b)		//Реализация функции - Function definition
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
	return a * b;
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

int power(int a, int b)
{
	int c = a;
	for (int d = 1; d < b; d++)
	{
		c *= a;
	}
	return c;
}

