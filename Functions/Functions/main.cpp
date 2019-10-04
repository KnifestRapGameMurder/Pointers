#include<iostream>
using std::cout;
using std::cin;
using std::endl;
const int ROWS = 4;
const int COLS=5;

void	FillRand(int Arr[ROWS][COLS], const int ROWS, const int COLS);
void	Print(int Arr[ROWS][COLS], const int ROWS, const int COLS);
int		Sum(int Arr[ROWS][COLS], const int ROWS, const int COLS);
double	avg(int Arr[ROWS][COLS], const int ROWS, const int COLS);
int		minValueIn(int Arr[ROWS][COLS], const int ROWS, const int COLS);
int		maxValueIn(int Arr[ROWS][COLS], const int ROWS, const int COLS);
void	ShiftLeft(int Arr[ROWS][COLS], const int ROWS, const int COLS);
void	ShiftRight(int Arr[ROWS][COLS], const int ROWS, const int COLS);
void	Sort(int Arr[ROWS][COLS], const int ROWS, const int COLS);

void main()
{
	setlocale(LC_ALL, "");
	int Crr[ROWS][COLS];
	FillRand(Crr, ROWS, COLS);
	Print(Crr, ROWS, COLS);
	cout << "Сумма элементов масива: " << Sum(Crr, ROWS, COLS) << endl;;
	cout << "Среднее арифметическое: " << avg(Crr, ROWS, COLS) << endl;;
	cout << "Минимальное значение: " << minValueIn(Crr, ROWS, COLS) << endl;
	cout << "Максимальное значение: " << maxValueIn(Crr, ROWS, COLS) << endl;
	Sort(Crr, ROWS, COLS);
	Sort(Crr, ROWS, COLS);
	Print(Crr, ROWS, COLS);

}

void FillRand(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}
}

void Print(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << "\t";
		}cout << endl;
	}
}

int  Sum(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += Arr[i][j];
		}
	}
	return sum;
}

double avg(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(Arr, ROWS, COLS)/ROWS/COLS;
}

int		minValueIn(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = Arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (Arr[i][j] < min)	min = Arr[i][j];
		}
	}
	return min;
}

int		maxValueIn(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = Arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (Arr[i][j] > max)	max = Arr[i][j];
		}
	}
	return max;
}

void	Sort(int Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int buffer;
	for (int b = 0; b < COLS; b++)
	{
		for (int a = 0; a < COLS; a++)
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 1; j < COLS; j++)
				{
					if (Arr[i][j - 1] > Arr[i][j])
					{
						buffer = Arr[i][j];
						Arr[i][j] = Arr[i][j - 1];
						Arr[i][j - 1] = buffer;
					}
					if (Arr[i][j] > Arr[i+1][j])
					{
						buffer = Arr[i+1][j];
						Arr[i+1][j] = Arr[i][j];
						Arr[i][j] = buffer;
					}
				}
			}
		}
	}
	
}