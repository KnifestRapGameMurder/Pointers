#include<iostream>
using namespace std;

//#define WO_BOOL_VARIABLE 
#define WITH_BOOL_VARIABLE

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n], minRand, maxRand;
	do
	{
		system("CLS");
		cout << "Введите минимальное возможное значение"
			"\n(разница между мин. и макс. значениями не может быть меньше 10) : ";	cin >> minRand;		cout << endl;
		cout << "Введите максимальное возможное значение : ";	cin >> maxRand;		cout << endl;
		if (minRand >= maxRand)
		{
			cout << "Минимальное значение должно быть меньше максимального" << endl;			system("PAUSE");
		}
	} while (minRand >= maxRand);




	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % (maxRand + 1 - minRand) + minRand) << "\t";
	} cout << endl;
#ifdef WO_BOOL_VARABLE
	for (int i = 0; i < n; i++)
	{
		int repeats = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])	repeats++;
		}
		if (repeats > 1)		continue;
		for (int j = i; j < n; j++)
		{
			if (arr[i == arr[j]])		repeats++;
		}
		if (repeats > 1)
		{
			cout << "Значение " << arr[i] << " встречается " << repeats << " раз" << endl;
		}

	}
#endif // 
#ifdef WITH_BOOL_VARIABLE
	for (int i = 0; i < n; i++)
	{
		int repeats = 0;
		bool met_before = false;
	}
#endif // WITH_BOOL_VARIABLE


	
}