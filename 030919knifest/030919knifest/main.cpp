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
		cout << "������� ����������� ��������� ��������"
			"\n(������� ����� ���. � ����. ���������� �� ����� ���� ������ 10) : ";	cin >> minRand;		cout << endl;
		cout << "������� ������������ ��������� �������� : ";	cin >> maxRand;		cout << endl;
		if (minRand >= maxRand)
		{
			cout << "����������� �������� ������ ���� ������ �������������" << endl;			system("PAUSE");
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
			cout << "�������� " << arr[i] << " ����������� " << repeats << " ���" << endl;
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