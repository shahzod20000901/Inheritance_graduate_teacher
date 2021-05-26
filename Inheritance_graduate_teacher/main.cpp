#include<iostream>
using namespace std;

class Human
{
	string first_name;
	string last_name;
	int old;
public:
	const string get_first_name() const
	{
		return first_name;
	}
	const string get_last_name() const
	{
		return last_name;
	}
	int get_old() const
	{
		return old;
	}
	Human operator() (const string first_name, const string last_name, int old)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->old = old;
		return *this;
	}

	Human(const string first_name, const string last_name, int old)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->old = old;
		cout << "HConstructor:\t" << this << endl;
	}

	void info()
	{
		cout << "first name is->\t" << first_name << endl;
		cout << "last name is ->\t" << last_name << endl;
		cout << "old is ->\t" << old << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
};

class student :public Human
{
	string specility;
	string group;
public:
	const string get_specility() const
	{
		return specility;
	}
	const string get_group() const
	{
		return group;
	}
	student operator()(const string specility, const string group)
	{
		this->specility = specility;
		this->group = group;
		return *this;
	}
	student 
	(
		const string first_name, const string last_name, int old,
		const string specility, const string group) :Human(first_name, last_name, old)
	{
		this->specility = specility;
		this->group = group;
		cout << "SConstructor:\t" << this << endl;
	}

	void info() 
	{
		Human::info();
		cout << "Specility is ->\t" << specility << endl;
		cout << "group is ->\t" << group << endl;
	}

	~student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "russian");
	Human Kudratov("Kudratov", "Shahzod", 21);
	Kudratov.info();
	student Aralov("Aralov", "Yo'lchi", 22, "geodezist", "SBD_011");
	Aralov.info();
}