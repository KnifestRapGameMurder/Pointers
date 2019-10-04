#include<iostream>
#include<array>
#include<vector>
using namespace std;

#define tab "\t"
//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef STL_ARRAY



	int Arr[] = {1,2,3,4,5};
	array<int, 5> arr = {1,2,3,4,5};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl; 
#endif 
	//int* d_arr = new int[5]{ 34,88,123 };
	//for(int i:d_arr)
	//delete[] d_arr;
	
#ifdef STL_VECTOR
	vector<int> vec = {0,1,2,3,5,8,13,21,34};
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\t";
	}
	cout <<"size:\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;


	vec.push_back(55);
	vec.push_back(89);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
		}
	cout << endl;
	for (vector<int>::iterator it = vec.end()-1; /*it != vec.begin()*/; it--)
	{
		cout << *it << "\t";
		if (it == vec.begin())break;
	}
	std::cout << endl;
	vec.resize(8);
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		std::cout << *it << "\t";
	
	}
std:cout << endl;
	vec.shrink_to_fit();
	vec.reserve(13);
	vec.reserve(23);
	cout << "size:\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.data() << endl;
	int* vec_arr = vec.data();
	
	int index;
	int data;
	cout << "Введите индекс добавляемого элемента"; cin >> index;
	cout << "Введите значение добавляемого элемента"; cin >> index;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position,5, data);
	for (int i : vec)cout << i << tab; cout << endl;

#endif // STL_VECTOR


}