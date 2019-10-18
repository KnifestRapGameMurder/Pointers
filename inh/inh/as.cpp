#include<iostream>

using namespace std;

class Human
{
	int age;
public:
	int get_age() const
	{
		return this->age;
	}

	void set_age(int age)
	{
		this->age = age;
	}
};

class Student :public Human
{
	int year;
public:
	int get_year() const
	{
		return this->year;
	}

	int set_year(int year)
	{
		return this->year = year;
	}

	Student(const string& int age, const string& int year) :Human(age)
	{
		this->year = year;
		cout << "SConstructor:\t" << this << endl;
	} 
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
};