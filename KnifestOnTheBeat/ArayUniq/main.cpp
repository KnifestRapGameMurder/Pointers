#include<iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n], minRand, maxRand;
	do
	{
		system("CLS");
		cout << "������� ����������� ��������� ��������"
			"\n(������� ����� ���. � ����. ���������� �� ����� ���� ������ 10) : ";	cin >> minRand;		cout << endl;
		cout << "������� ������������ ��������� �������� : ";	cin >> maxRand;		cout << endl;
		/*if (maxRand - minRand < 10 && maxRand - minRand > -10)
		{
			cout << "������� ����� ���. � ����. ���������� �� ����� ���� ������ 10" << endl;	system("PAUSE");
		}*/
		if (minRand >= maxRand)
		{
			cout << "����������� �������� ������ ���� ������ �������������" << endl;			system("PAUSE");
		}
	} while (minRand >= maxRand);
	
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand + 1 - minRand) + minRand;
		cout << arr[i] << "\t";
	} cout << endl;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		for (int j =0; j<i; j++)
		{
			if (arr[i] == arr[j])
			{
				int e = 0;
				for (int m = 0; m < n; m++)
				{
					if (arr[i] == arr[m])
					{
						a++;
					}

				}
				for (int m = 0; m < i; m++)
				{
					if (arr[i] == arr[m])
					{
						e++;
					}

				}
				if(e<=1)
				{
					cout << arr[i] << "\t" << a << " ����" << endl;
					break;
				}
			}
		}
		
	}
}