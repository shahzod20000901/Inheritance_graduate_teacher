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

	explicit Human(const string first_name, const string last_name, int old)
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
	explicit student
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

class Teacher :public Human
{
private:
	int experiance;
	string speciality;
public:
	const int get_experiance() const
	{
		return experiance;
	}
	const string get_speciality() const
	{
		return speciality;
	}
	Teacher operator()(const int experiance, const string speciality)
	{
		this->experiance = experiance;
		this->speciality = speciality;
		return *this;
	}
	Teacher
	(const string first_name, const string last_name, int old,
		const int experiance, const string speciality) :Human(first_name, last_name, old)
	{
		this->experiance = experiance;
		this->speciality = speciality;
	}

	void info()
	{
		Human::info();
		cout << "Experiance:\t" << experiance << endl;
		cout << "Speciality:\t" << speciality << endl;
	}

	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
};

class Graduate :public Human
{
private:
	string project_name;
public:
	const string get_project_name() const
	{
		return project_name;
	}
	string set_project_name(const string project_name)
	{
		this->project_name = project_name;
	}
	Graduate
	(
		const string first_name, const string last_name, int old,
		const string project_name
	) :Human(first_name, last_name, old)
	{
		this->project_name = project_name;
	}

	void info()
	{
		Human::info();
		cout << "Project name:\t" <<project_name<< endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "russian");
	Human Kudratov("Kudratov", "Shahzod", 21);
	Kudratov.info();
	student Aralov("Aralov", "Yo'lchi", 22, "geodezist", "SBD_011");
	Aralov.info();
	Teacher Berkinov("Berkinov", "Abdusodiq", 23, 5, "developer");
	Berkinov.info();
	Graduate Alimov("Alimov", "Shamil", 28, "Computer science");
	Alimov.info();
}

//			https://github.com/shahzod20000901/OOP_CPP/tree/Fraction_separation/Intro/overloading%20operators
