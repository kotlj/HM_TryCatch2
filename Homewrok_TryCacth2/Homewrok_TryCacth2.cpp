
#include <iostream>
#include <fstream>

class Bank
{
private:
	float balance;
public:
	Bank()
	{
		balance = 0;
	}
	Bank(float _balance)
	{
		try
		{
			if (_balance < 0)
			{
				balance = 0;
				throw -1;
			}
			else
			{
				balance = _balance;
			}
		}
		catch (int)
		{
			std::cerr << "INVALID BALANCE\n";
		}
	}

	void addBalance(float _balance)
	{
		try
		{
			if (_balance < 0)
			{
				throw -1;
			}
			else
			{
				balance += _balance;
			}
		}
		catch (int)
		{
			std::cerr << "INVALID BALANCE\n";
		}
	}
	float getBalance() const
	{
		return balance;
	}
	void removeBalance(float _remove)
	{
		try
		{
			if (_remove > balance || _remove < 0)
			{
				throw - 1;
			}
			else
			{
				balance -= _remove;
			}
		}
		catch (int)
		{
			std::cerr << "INVALID SUM TO REMOVE\n";
		}
	}
};

class Base
{
private:
public:
	virtual void Display(const char* path) = 0;
};
class fileASCII : public Base
{
private:
public:
	void Display(const char* path) override
	{
		char* buff = new char[2];
		buff[1] = '\0';
		try
		{
			std::ifstream in(path);
			if (in.is_open())
			{
				while (!in.eof())
				{
					in.get(buff, 2);
					std::cout << buff;
				}
				std::cout << '\n';
				delete[] buff;
				in.close();
			}
			else
			{
				throw -1;
			}
		}
		catch (int)
		{
			std::cerr << "FILE ERROR: OPEN ERROR\n";
		}
		
	}
};

class BaseA
{
protected:
	double first;
	double second;
public:
	BaseA()
	{
		first = 0;
		second = 0;
	}
	BaseA(double _first, double _second)
	{
		try
		{
			if (_first > 0 && _second > 0)
			{
				first = _first;
				second = _second;
			}
			else
			{
				throw -1;
			}
		}
		catch (int)
		{
			std::cerr << "INVALID NAUMBERS\n";
		}
	}
	double virtual area() = 0;
};
class Rectangle : public BaseA
{
private:
public:
	Rectangle() : BaseA()
	{}
	Rectangle(double _first, double _second) : BaseA(_first, _second)
	{}
	double area() override
	{
		try
		{
			if (first * second == 0)
			{
				throw true;
			}
			return first * second;
		}
		catch (bool)
		{
			std::cerr << "LOGIC_ERROR\n";
		}
	}
};

int main()
{
	Bank pract(1000.0);
	pract.addBalance(100);
	pract.removeBalance(1200);
	fileASCII file;
	file.Display("C:/Users/Admin/source/repos/Homework_FileClass/Homework_FileClass/tester.txt");
	Rectangle A(10, 10);
	std::cout << A.area() << '\n';
}
