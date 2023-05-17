#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

#pragma region Модификаторы доступа, конструкторы классов
//класс, описывающий объект Человек
class Person {

	//список методов и свойств доступных другим функциям и объектам программы
public:
	//конструктор класса, для инициализации данных объекта
	Person(string p_name, unsigned p_age) {
		name = p_name;
		age = p_age;
	}

	//конструктор по умолчанию, так как не принимает параметров
	Person() {
		name = "Tom";
		age = 17;
	}

	//Конструктор копирования, принимаем параметр по ссылки, чтобы можно было изменить значения нового объекта
	Person(Person& p)
	{
		name = p.name;
		age = p.age;
	}

	string name;
	unsigned age;

	void printPublic()
	{
		cout << "Name: " << name << " " << "Age: " << age << endl;
	}

	//элементы, которые доступны только данному классу или его потомкам
protected:
	void printProtected()
	{
		cout << "Protected method" << endl;
	}

	//элементы, которые доступны только данному классу
private:
	void printPrivate()
	{
		cout << "Private method" << endl;
	}
};


//класс потомок класса Person
class PersonA : Person {

	void print()
	{
		//методы, которые доступны классу потомку - это public и protected
		printPublic();
		printProtected();
	}
};
#pragma endregion

#pragma region Виртуальные методы
class Gun {
public:
	//для того чтобы переопределить этот метод в классе-наследнике, чтобы написать другую реализацию
	virtual void Shoot() {
		cout << "Bang" << endl;
	}
};

class SubMachinGun : public Gun
{
public:
	void Shoot()
	{
		cout << "bang bang bang" << endl;
	}
};
#pragma endregion

#pragma region Дружественные функции
class Point {
private:
	int x, y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Print() {
		int z = x + y;
		cout << "Сумма x и y = " << z << endl;
	}

	//даём понять, что это дружественная функция
	friend void ChangeX(Point& value);
};

void ChangeX(Point& value)
{
	value.x = 7;
}
#pragma endregion

#pragma region Дружественные методы класса
class Apple; //определить класс, чтобы дружественный класс знал что где-то есть класс Apple

class Human {
public:
	void TakeApple(Apple& apple); //сигнатура метода, реализация которого расположена отдельно (прототип метода)
	void EatApple(Apple& apple)
	{

	}
};

class Apple {
private:
	int weight;
	string color;

public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

	friend void Human::TakeApple(Apple& apple);
};

//вынесенная функция класса Human
void Human::TakeApple(Apple& apple)
{
	cout << "TakeApple: " << "Weight = " << apple.weight << " Color = " << apple.color << endl;
}


#pragma endregion

#pragma region Дружественные классы
class Two;
class One;

class One {

public:
	void TakeTwo(Two& two); //сигнатура метода, реализация которого расположена отдельно (прототип метода)
	void Eat(Two& two)
	{

	}
};

class Two {
	friend One;

private:
	int a;
	string b;

public:
	Two(int a, string b)
	{
		this->a = a;
		this->b = b;
	}
};

//вынесенная функция класса One
void One::TakeTwo(Two& two)
{
	cout << "TakeTwo: " << "A = " << two.a << " B = " << two.b << endl;
}
#pragma endregion



int main()
{
	setlocale(LC_ALL, "ru");

#pragma region Модификаторы доступа и конструкторы классов
	//создаём экземпляр класса
	Person person;

	//устанавливаем значения полей класса 
	person.name = "Valeria";
	person.age = 21;

	//вызываем метод класса
	person.printPublic();

	//используется конструктор по умолчанию
	Person tom;
	tom.printPublic();

	//задаём данные для инициализации
	Person bob{ "Bob", 18 };
	bob.printPublic();

	//вызов конструктора копирования (копирует уже существующий объект)
	Person tomas{ tom };
	tomas.printPublic();

	//встроенный конструктор копирования делает то же самое
	cout << endl;
	tom.age = 8;
	tom.printPublic();
	tomas.printPublic();
#pragma endregion

#pragma region Виртуальные методы
	Gun gun;
	SubMachinGun machinGun;

	//указатель на адрес объекта
	Gun* weapon = &machinGun;

	//отработает метод пулемёта благодаря virtual
	weapon->Shoot();
#pragma endregion

#pragma region Дружественные функции
	cout << endl << "Дружественные функции----------------" << endl;
	Point point(5, 6);
	point.Print();
	cout << endl << "Изменим значение x благодаря дружественной функции: " << endl;
	ChangeX(point);
	point.Print();
#pragma endregion

#pragma region Дружественные методы
	cout << endl << "Дружественные методы------------------" << endl;
	Apple apple(150, "Красное");
	Human human;
	human.TakeApple(apple);

#pragma endregion

#pragma region Дружественные классы
	cout << endl << "Дружественные классы----------------" << endl;
	Two two(8, "восемь");
	One one;
	one.TakeTwo(two);
#pragma endregion

	//операторы форматного вывода
	cout << endl;
	printf("dog %E", 0.2899999999999999);
	printf("dog %d", 3);
	cout << endl;

	//операторы форматного ввода
	cout << "Операторы форматного ввода:" << endl;
	int pizza;
	scanf_s("%d", &pizza);
	cout << pizza << endl;

	//форматный ввод и вывод файловый
	FILE* pFile;
	int n;
	char name[100];

	pFile = fopen("myfile.txt", "w");
	puts("please, enter a name: ");
	cin >> name;
	fprintf(pFile, "Name %d [%-10.10s]n", name);
	fclose(pFile);


	//операторы бесформатного вывода
	/*cout << "Операторы бесформатного ввода:" << endl;
	const char* fname = "pizza.bin";
	string s = "Hello everyone! How are you doing? \n \t уруррурурурур ьеь 485739 393 92 9 \t 001010";
	fstream(fname, ios::out | ios::binary) << s;
	cout << s << endl;*/


	string j = "Hello everyone? My name is 45 \t 86 \n 7777 \t gogog 343 01";
	char h[400];
	ofstream f("test.bin", ios::binary);
	if (f.is_open())
	{
		f.write((const char*)&j, sizeof(j));
		f.close();
	}
	else cout << "Файл не может быть открыт" << endl;

	ifstream fo("test.bin", ios::binary);
	fo.read((char*)&h, sizeof(j)*10);
	cout << h << endl;
	fo.close();


	//флаги управлением форматом потоков ввода-вывода
	//Флаги позволяют включить или выключить один из параметров ввода/вывода
	cout.setf(ios::right); //установка флага left (выравнивание по левой границе)
	cout.width(40);
	cout << "cppstudio.com"<< endl;

	//из десятичной в восьмеричную СС
	cout.unsetf(ios::dec); //снятие флага
	cout.setf(ios::oct); //ios - имя класса
	int value;
	cin >> value;
	cout << value << endl;


	//Манипуляторы - объект, который управляет потоками ввода/вывода для форматирования потоков информации
	bool log_true = 1;
	cout << boolalpha << log_true << endl;

	cout << setw(40) << "cppstudio.com" << endl;





	return 0;
}


