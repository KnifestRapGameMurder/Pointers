#include<iostream>
#include<Windows.h>
#include<string>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>

#include<stack>
#include<queue>

#include<map>
#include<set>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-----------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
//#define STL_FORWARD_LIST
//#define STL_STACK
//#define STL_QUEUE
//#define STL_MAP
#define STL_SET

void print(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void reverse_print(const deque<int>& d)
{
	for (std::deque<int>::const_reverse_iterator it = d.crbegin(); it != d.crend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void multimap_print(const multimap<string, string>& m)
{
	string prevWord;
	for (multimap <string, string>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		if (prevWord.compare(it->first) == 0) cout << tab << it->second << endl;
		else cout << it->first << tab << it->second << endl;
		prevWord = it->first;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int n = 5;
	/*int Arr[n] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(Arr)/sizeof(int); i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
	cout << delimiter << endl;
	//range based for:
	for (int i : Arr)
	{
		cout << i << tab;
	}
	cout << endl;*/

	array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	//vector може увеличиваться и уменьшаться.
	vector<char> vec = { 0, 1, 1, 3, 5, 8, 13, 21, 34, 55 };
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vec.push_back(89);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max size:\t" << vec.max_size() << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	//DEQue (Double Ended Quee - Двунаправленная очередь) представляет собой двусвязный список векторов.
	deque<int> d = { 3, 5, 8, 13, 21 };
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << d.size() << endl;
	cout << d.max_size() << endl;
	print(d);
	reverse_print(d);
	d.push_front(2);
	d.push_front(1);
	d.push_front(0);
	d.push_front(0);
	try
	{
		for (int i = 0; i <= d.size(); i++)
		{
			//cout << d[i] << tab;
			cout << d.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception & e)
	{
		cerr << e.what() << endl;
	}
#endif // STL_DEQUE

#ifdef STL_LIST
	//List - это самый обычный двусвязный список
	list<int> l = { 3, 5, 8, 13, 21 };
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	int value, index;
	cout << "Введите значение: "; cin >> value;
	cout << "Введите позицию:  "; cin >> index;

	list<int>::iterator it = l.begin();
	for (int i = 0; i < index; i++) it++;
	l.insert(it, value);

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << tab;
	}
#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	forward_list<int> fl = { 3, 5, 8, 13, 21 };
	for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	/*int value, index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	cout << "Введите инжекс добавляемого элемента:   "; cin >> index;
	forward_list<int>::iterator position = fl.begin();
	for (int i = 0; i < index-1; i++) position++;
	fl.insert_after(position, value);*/

	fl.insert_after(fl.begin(), 123);

	for (int i : fl)
	{
		cout << i << tab;
	}
#endif // STL_FORWARD_LIST

#ifdef STL_STACK
	//int n; cout << "Введите размер стэка: "; cin >> n;
	stack<int> stk;
	stk.push(3);
	stk.push(5);
	stk.push(8);
	stk.push(13);
	stk.push(21);
	while (!stk.empty())
	{
		cout << stk.top() << tab;
		stk.pop();
	}
#endif // STL_STACK

#ifdef STL_QUEUE
	queue<int> fifo;
	fifo.push(3);
	fifo.push(5);
	fifo.push(8);
	fifo.push(13);
	fifo.push(21);

	cout << fifo.front() << endl;
	cout << fifo.back() << endl;

	while (fifo.size())
	{
		cout << fifo.front() << tab << fifo.back() << endl;
		fifo.pop();
	}
#endif // STL_QUEUE

#ifdef STL_MAP

	//Использовал multimap потому-что в map нельзя добавлять несколько одинаковых ключей

	multimap <string, string> vocabulary = { { "сlose", "закрывать" },
											 { "desert", "пустыня" },
											 { "desert", "покидать" } };

	multimap_print(vocabulary);

	string key, value;
	cout << "Введите английское слово которое хотите добавить: ";
	SetConsoleCP(1251);
	cin >> key;
	SetConsoleCP(866);
	cout << "Введите перевод: ";
	SetConsoleCP(1251);
	cin >> value;
	SetConsoleCP(866);
	cout << endl;

	vocabulary.insert(pair<string, string>(key, value));

	multimap_print(vocabulary);

#endif // STL_MAP

#ifdef STL_SET

	set <pair<string, list<string>>> base;
	string key;
	list<string> l;
	base.insert(pair<string, list<string>>("BI0000BI", list<string>{"Поехал на красный", "Плюнул в лицо полицейскому"}));
	base.insert(pair<string, list<string>>("BI0001BI", list<string>{"Ехал 320км/ч"}));
	base.insert(pair<string, list<string>>("BI0002BI", list<string>{"Пьяный сел за руль"}));
	base.insert(pair<string, list<string>>("BI0003BI", list<string>{"Заснул на трассе"}));
	base.insert(pair<string, list<string>>("BI0004BI", list<string>{"Сбил дорожный знак", "Пьяный сел за руль"}));

	//Вывод всех номеров и их нарушений
	cout << "Список нарушителей: " << endl;
	for (set<pair<string, list<string>>>::iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ": ";
		for (list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			cout << *lit << "; ";
		}
		cout << "\b\b." << endl;
	}
	cout << endl;

	//Добавление нарушения по номеру
	const int n = 256;
	char newViolation[n];
	cout << "Введите нарушение: ";
	SetConsoleCP(1251);
	cin.getline(newViolation, n);
	SetConsoleCP(866);

	string newNumber;
	cout << "Введите номер: "; cin >> newNumber;

	list<string> lviol;
	bool check = false;

	for (set<pair<string, list<string>>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first == newNumber)
		{
			lviol = it->second;
			lviol.push_back(newViolation);
			it = base.erase(it);
			base.insert(pair<string, list<string>>(newNumber, lviol));
			it++;
			check = true;
		}
	}
	if (check != true) base.insert(pair<string, list<string>>(newNumber, list<string>{newViolation}));
	cout << endl;

	//Вывод всех номеров и их нарушений
	cout << "Список нарушителей: " << endl;
	for (set<pair<string, list<string>>>::iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ": ";
		for (list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			cout << *lit << "; ";
		}
		cout << "\b\b." << endl;
	}
	cout << endl;

	//Вывод нарушений по номеру
	/*string car_number;

	cout << "Введите номер машины: ";
	SetConsoleCP(1251);
	cin >> car_number;
	SetConsoleCP(866);

	for (set<pair<string, list<string>>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first == car_number)
		{
			cout << it->first << ": ";
			for (list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
			{
				cout << *lit << "; ";
			}
			cout << "\b\b." << endl;
		}
	}
	cout << endl;*/

	//Вывод номеров по диапазону
	/*int from, to;
	cout << "Введите диапазон номеров: c ";	cin >> from;
	cout << "по "; cin >> to;

	set<pair<string, list<string>>>::iterator fromIt = base.begin();
	set<pair<string, list<string>>>::iterator toIt = base.begin();
	for (int i = 0; i < from; i++) fromIt++;
	for (int i = 0; i <= to; i++) toIt++;

	for (set<pair<string, list<string>>>::iterator it = fromIt; it != toIt; it++)
	{
		cout << it->first << ": ";
		for (list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			cout << *lit << "; ";
		}
		cout << "\b\b." << endl;
	}
	cout << endl;*/

	//Вывод номеров по нарушению
	/*const int n = 256;
	char violation[n];
	cout << "Введите нарушение: ";
	SetConsoleCP(1251);
	cin.getline(violation, n);
	SetConsoleCP(866);

	string violationBuf = violation;
	for (int i = 0; i < violationBuf.size(); i++)
	{
		violationBuf[i] = tolower(violationBuf[i]);
	}

	for (set<pair<string, list<string>>>::iterator it = base.begin(); it != base.end(); it++)
	{
		for (list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			string litBuf = *lit;
			for (int i = 0; i < litBuf.size(); i++)
			{
				litBuf[i] = tolower(litBuf[i]);
			}

			if (litBuf == violationBuf)
			{
				cout << it->first << endl;
			}
			else if (litBuf.find(violationBuf) != -1)
			{
				cout << it->first << endl;
			}
		}
	}*/

#endif //STL_SET
}