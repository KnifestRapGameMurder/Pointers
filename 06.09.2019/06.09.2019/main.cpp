#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

#define Escape 27
#define Space 32
#define w 119
#define W 87
#define s 115
#define S 83

class Engine
{
	bool started;
	double consumption;
	double consumption_per_second;
public:
	Engine(double consumption)
	{
		this->started = false;
		this->consumption = consumption;
		this->consumption_per_second = consumption / 30000;
	}
	bool getIsStarted()
	{
		return started;
	}
	double getConsumpt()
	{
		return consumption;
	}
	double getConsumptPerSec()
	{
		return consumption_per_second;
	}
	void Start()
	{
		this->started = true;
	}
	void Stop()
	{
		this->started = false;
	}
	void setConsumpt(double consumpt)
	{
		this->consumption = consumpt;
	}
	void info()
	{
		cout << "Is started: " << this->started << endl;
		cout << "Consumption: " << this->consumption << endl;
		cout << "Consumption per second: " << this->consumption_per_second << endl;
	}
};

class FuelTank
{
	double tank;
	double fuelLevel;
public:
	FuelTank(double tank)
	{
		this->tank = tank;
		fuelLevel = 0;
	};
	double getTank()
	{
		return tank;
	}
	double getFuelLevel()
	{
		return fuelLevel;
	}
	void Consume(double liters)
	{
		if (this->fuelLevel - liters >= 0) this->fuelLevel = this->fuelLevel - liters;
		else
		{
			this->fuelLevel = 0;
			cout << "Fuel is over" << endl;
		}
	}
	void Refuel(double liters)
	{
		if (this->fuelLevel + liters <= 0) cout << "Min fuel level is 0" << endl;
		else if (this->fuelLevel + liters <= this->tank)
		{
			this->fuelLevel = this->fuelLevel + liters;
		}
		else cout << "Back is full." << endl;
	}
};

class Car
{
	Engine engine;
	FuelTank tank;
	double speed;
	double maxSpeed;
	double current_consumption;
public:
	const Engine& getEngine() const
	{
		return this->engine;
	}
	Engine& getEngine()
	{
		return this->engine;
	}
	const FuelTank& getTank()const
	{
		return this->tank;
	}
	FuelTank& getTank()
	{
		return this->tank;
	}

	Car(Engine engine, FuelTank tank, double maxSpeed) :engine(engine), tank(tank)
	{
		this->speed = 0;
		this->maxSpeed = maxSpeed;
		this->current_consumption = 0;
	}
	double getSpeed()
	{
		return speed;
	}
	double getMaxSpeed()
	{
		return maxSpeed;
	}
	void speedUp(double speed)
	{
		if (this->speed + speed > maxSpeed) cout << "Maximum speed reached" << endl;
		else this->speed = this->speed + speed;
	}
	void speedDown(double speed)
	{
		if (this->speed - speed < 0);
		else this->speed = this->speed - speed;
	}
	void fill(double fuel)
	{
		tank.Refuel(fuel);
	}
	void start()
	{
		engine.Start();
	}
	void stop()
	{
		engine.Stop();
		/*for (int i = 0; i < (getSpeed() / 10) + 10; i++)
		{
			if (getSpeed() - 10 != 0) speedDown(10);
			else speedDown(getSpeed());
			Sleep(50);
			system("cls");
			info();
		}*/
	}
	void fuelConsume(double fuelAmount)
	{
		tank.Consume(fuelAmount);
	}
	void setConsumpt(double consumpt)
	{
		engine.setConsumpt(consumpt);
	}
	double getConsumpt()
	{
		return engine.getConsumpt();
	}
	double getFuelLevel()
	{
		return tank.getFuelLevel();
	}
	bool getStatus()
	{
		return engine.getIsStarted();
	}
	void info()
	{
		system("CLS");
		int n = 9;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (i == 0)
				{
					if (j == 0) cout << char(218);
					else if (j == 24) cout << char(191);
					else cout << char(196);
				}

				if (i != 0 && i != n - 1 && j == 0) cout << char(179);

				if (i == n - 1)
				{
					if (j == 0) cout << char(192);
					else if (j == 24) cout << char(217);
					else cout << char(196);
				}
			}
			if (i == 1) cout << "Tank size: " << tank.getTank() << "\t\t" << char(179);
			if (i == 2) cout << "Fuel level:   " << tank.getFuelLevel() << "\t" << char(179);
			if (i == 3)
			{
				cout << "Status: ";
				if (engine.getIsStarted() == true) cout << "ON";
				else cout << "OFF";
				cout << "\t\t" << char(179);
			}
			if (i == 4) cout << "Consumpt:  " << engine.getConsumpt() << " l/100km\t" << char(179);
			if (i == 5) cout << "Speed:     " << getSpeed() << " km/h\t" << char(179);
			if (i == 6) cout << "Max speed: " << getMaxSpeed() << " km/h\t" << char(179);
			if (i == 7)
			{
				if (getFuelLevel() > 5) cout << "Fuel lamp: all is ok\t" << char(179);
				else cout << "Fuel lamp: need a fill\t" << char(179);
			}
			cout << endl;
		}
	}

	void idle()
	{
		char key = 0;
		do
		{
			Sleep(50);
			info();
			cout << "  Instruction to drive: " << endl;
			cout << "Press N to ON engine;" << endl;
			cout << "Press F to OFF engine;" << endl;
			cout << "Press W to driving forward;" << endl;
			cout << "Press Space to brake;" << endl;
			cout << "Press R to refuel." << endl;
			cout << endl;
			speedDown(2);
			if (speed / 100 > 0)
			{
				current_consumption = engine.getConsumpt() * (speed / 100);
			}
			if (tank.getFuelLevel() > 0 && engine.getIsStarted() == true)
			{
				//Sleep(500);
				fuelConsume(engine.getConsumptPerSec());
				if (speed > 0)
				{
					fuelConsume(current_consumption / 5);
				}
			}
			else if (tank.getFuelLevel() == 0 && engine.getIsStarted() == true) stop();
			if (kbhit())
			{
				key = getch();
				switch (key)
				{
				case 'n':
				case 'N':
					if (getFuelLevel() == 0) cout << "Refuel a car first!" << endl;
					else
					{
						cout << "Status is ON" << endl;
						engine.Start();
					}
					break;

				case 'f':
				case 'F': cout << "Status is OFF" << endl; engine.Stop(); break;

				case 'w':
				case 'W':
					if (getStatus() == true && getFuelLevel() > 0)
					{
						cout << "Driving forward" << endl;
						speedUp(10);
					}
					break;

				case ' ':
					cout << "Car is braking" << endl;
					speedDown(10);
					break;

				case 'r':
				case 'R':
					double fuel;
					cout << "Enter fuel amount: "; cin >> fuel;
					fill(fuel);
					break;

				case Escape:cout << "Exit" << endl; break;
				}
			}
		} while (key != 27);
	}
};

void main()
{
	Car car(Engine(1), FuelTank(60), 240);
	Car car2();
	car.fill(5.3);
	car.idle();

}