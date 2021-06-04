#include<iostream>
#include<string>
#include<regex>
using namespace std;

#define academy
#define Regex_name
#define Regex_gmail
#define Regex_name
#define delimiter "\n---------------------------------------------------------\n"

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

ostream& operator<<(ostream& os, Human& obj)
{
	os << "First name:\t" << obj.get_first_name() << endl << "Last name:\t" << obj.get_last_name()<<endl << "Old:\t\t" << obj.get_old() <<endl;
	return os;
}

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

ostream& operator<<(ostream& os, student& obj)
{
	os << "First name:\t" << obj.get_first_name() << endl << "Last name:\t" << obj.get_last_name() << endl;
	os << "Old:\t\t" << obj.get_old() << endl << "Speciality:\t" << obj.get_specility() << endl << "Group:\t\t" << obj.get_group() << endl;
	return os;
}
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

ostream& operator<<(ostream& os, Teacher& obj) 
{
	os << "First name:\t" << obj.get_first_name() << endl << "Last name:\t" << obj.get_last_name() << endl;
	os << "Old:\t\t" << obj.get_old() << endl;
	os << "Experiance:\t" << obj.get_experiance() << endl << "Speciality:\t" << obj.get_speciality() << endl;
	return os;
}

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

ostream& operator<<(ostream& os, Graduate& obj)
{
	os << "First name:\t" << obj.get_first_name() << endl << "Last name:\t" << obj.get_last_name() << endl;
	os << "Old:\t\t" << obj.get_old()<<endl << "Project name:\t" << obj.get_project_name() << endl;
	return os;
}

void main()
{
	setlocale(LC_ALL, "russian");

#ifdef academy
	Human kudratov("kudratov", "shahzod", 21);
	//kudratov.info();
	cout << kudratov << endl;
	student aralov("aralov", "yo'lchi", 22, "geodezist", "sbd_011");
	////aralov.info();
	cout << aralov << endl;
	Teacher berkinov("berkinov", "abdusodiq", 23, 5, "developer");
	cout << berkinov << endl;
	//berkinov.info();
	Graduate alimov("alimov", "shamil", 28, "computer science");
	cout << alimov << endl;
	//alimov.info();  
#endif academy
	cout << delimiter;
	Human* p_teacher = &berkinov;
	Human* p_student = &aralov;
	Human* p_alimov = &alimov;
	Human* group[] =
	{
		new Teacher("berkinov", "abdusodiq", 23, 5, "developer"),
		new Graduate("alimov", "shamil", 28, "computer science"),
		new student("aralov", "yo'lchi", 22, "geodezist", "sbd_011"),
		new student("tursunov", "feruz", 24, "perevodchik", "sg_012")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
	}

#ifdef Regex_name
	regex name_template("[A-Z][a-z]{1,30}");
	string name;
	cout << "Введите имя: "; cin >> name;
	//regex_match(наша строка, регулярное выражние, шаблон проверки);
	cout << regex_match(name.c_str(), name_template, std::regex_constants::match_any);
	cout << endl;
#endif // Regex_name

#ifdef Regex_gmail
	regex rgx("[A-za-z0-9]{3,15}@[A-Za-z]{3,8}.[a-z]{2,3}");
	string gmail;
	cout << "Enter the gmail:\t"; cin >> gmail;
	cout << regex_match(gmail, rgx, std::regex_constants::match_any);
#endif // Regex_gmail

}

////1. В проекте Academy для всех классов перегрузить оператор вывода(<< ) и вывести группу на экран с его использованием;
//for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
//{
//	cout << *group[i] << endl;
//}
//2. Построить иерархию объектов игры GTA;

/*https://github.com/okovtun/SPD_011
https://www.youtube.com/watch?v=yPB-sWkSuLE&list=PLeqyOOqxeiINLry6Ho7Xa0xBGZ-YwSsal

MATH:
https://drive.google.com/drive/folders/1PtH0LBlm7PpmBcaE6mwBnkftAcEui32y?usp=sharing

Regex:
https://www.cplusplus.com/reference/regex/
https://www.cplusplus.com/reference/regex/ECMAScript/
https://www.cplusplus.com/reference/regex/regex_match/

Assembler:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing

TODO:
1. В проекте Academy для всех классов перегрузить оператор вывода (<<) и вывести группу на экран с его использованием;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
	}
2. Построить иерархию объектов игры GTA;*/


/*
TODO:
В класс ForwardList добавить методы:
1. void erase(int index);		//Удаляет значение по заданному индексу
2. Написать деструктор таким образом, чтобы он очищал список (удалял из него све элементы) перед удалением;
3. Оптимировать методы удаления элементов;
4. CopyMethods
5. MoveMethods
6. Обеспечить создание списка следующим образом:
	ForwardList list = { 3, 5, 8, 13, 21 };


MATH:
https://drive.google.com/drive/folders/1PtH0LBlm7PpmBcaE6mwBnkftAcEui32y?usp=sharing

Regex:
https://www.cplusplus.com/reference/regex/
https://www.cplusplus.com/reference/regex/ECMAScript/
https://www.cplusplus.com/reference/regex/regex_match/

Assembler:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing
*/