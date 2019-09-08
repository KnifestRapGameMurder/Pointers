#include<iostream>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 4;
	const int COLS = 5;
	int arr[ROWS][COLS]=
	{
		{1,2,3,},
		{4,5,6,},
		{7,8,9}
	};

	//Заполнение случайными числами:
	int buf = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
		
	}

	//Сортировка массива:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS-1; j++)
		{
			if (arr[i][j] > arr[i][j+1])
			{
				buf = arr[i][j];
				arr[i][j] = arr[i][j+1];
				arr[i][j+1] = buf;
			}
		}

	}

	//Вывод массива на экран:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}