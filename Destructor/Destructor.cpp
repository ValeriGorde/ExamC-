#include <iostream>
#include <vector>
using namespace std;


class Person{
public: 
    string name;

    //конструктор
    Person(string p_name){
        name = p_name;
        cout << "Person " << name << " created" << endl;
    }

    //деструктор
    ~Person() {
        cout << "Person " << name << " deleted" << endl;
    }
};



class A {
public: 
    A() {
        cout << "Выделена динамическая память объекта класс А" << endl;
    }
    virtual ~A() {
        cout << "Освобождена динамическая память объекта класс А" << endl;
    }
};

class B : public A
{
public: 
    B() {
        cout << "Выделена динамическая память объекта класс B" << endl;
    }
    ~B() override {
        cout << "Освобождена динамическая память объекта класс B" << endl;
    }

};

class C 
{
public:
    C() {
        cout << "Выделена динамическая память объекта класс C" << endl;
    }
    ~C() {
        cout << "Освобождена динамическая память объекта класс C" << endl;
    }
};

class D: public C
{
public: 
    D() {
        cout << "Выделена динамическая память объекта класс D" << endl;
    }
    ~D() {
        cout << "Освобождена динамическая память объекта класс D" << endl;
    }
};

class Pupil
{
public:
    Pupil(string name, unsigned age) : name{ name }, age{ age } {}
    string getName() const { return name; }
    unsigned getAge() const { return age; }

    void setName(string personName) { name = personName; }
    void setAge(unsigned personAge) { age = personAge; }
private:
    string name;
    unsigned age;
};

//выходной поток (адрес, тк тут так заведено)
ostream& operator << (ostream& os, const Pupil& person)
{
    return os << person.getName() << " " << person.getAge();
}

istream& operator >> (istream& in, Pupil& person)
{
    string name;
    unsigned age;
    in >> name >> age;
    person.setName(name);
    person.setAge(age);
    return in;
}

int main()
{
    setlocale(LC_ALL, "ru");
    {
        //создание тома и боба
        Person tom{ "Tom" };
        Person bob{ "Bob" };
        //удаление сначала Боба, а потом Тома
    }
    //создаётся Сэм
    Person sam{ "Sam" };
    //удаляется Сэм

    cout << endl << "Работа с виртуальным деструктором: " << endl;

    cout << "Корректная очистка памяти: " << endl;
    A *b = new B;
    delete b;

    cout << endl << "Утечка памяти: " << endl;
    C *d = new D;
    delete d;


    //перегрузка операций вывода
    Pupil tom{ "Tom", 38 };
    cout << tom << endl;

    Pupil bob{ "Bob", 42 };
    cout << bob << endl;

    //перегрузка операций ввода
    Pupil hob{ "",0 };
    cout << "Input name and age: ";
    cin >> bob;
    cout << "Name: " << hob.getName() << "\tAge: " << hob.getAge() << endl;

    return 0;

}
