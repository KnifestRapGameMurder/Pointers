#include<iostream>
using namespace std;

class Engine;
class FuelTank;

class Car 
{

};

class Engine 
{

};

class FuelTank
{
	double fuel = 0;
public:
	FuelTank(double fuel = 20) 
	{
		Refuel(fuel);
	};
	void Consume(double liters) 
	{

	}
	void Refuel(double liters)
	{
		if (60 > this->fuel + liters) 
		{
			this->fuel = this->fuel + liters;
		}
		else if (this->fuel + liters < 0) cout << "Min fuel level is 0" << endl;
		else cout << "Back is full." << endl;
	}
	void showFuelLevel()
	{
		cout << "Fill level: " << this->fuel << endl;
	}
};

void main() 
{
	setlocale(LC_ALL, "Russian");
	FuelTank tank;
	tank.Refuel(20);
	tank.Refuel(100);
	tank.showFuelLevel();
}