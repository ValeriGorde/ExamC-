#include <iostream>
using namespace std;


void Foo1()
{
    cout << "void Foo1()" << endl;
}

void Foo2(int a)
{
    cout << "void Foo2() = " << a - 1<< endl;
}

//структуры служат для хранения общедоступных данных в виде публичных переменных
struct T {
    int a{ 5 };
};

class A {
public:
    int x;
    int y;
    A() {

    }
};


class BaseA {
private:
    int x = 0;
public:
    void print() {
        cout << x << endl;
    }
};


class BaseB: public BaseA {
private:
    int x = 1;
public:
    void print() {
        cout << x << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    
    BaseA* b = new BaseB();
    b->print();
    


    int a = 5;
    int *pa = &a;
    *pa = 7;

    cout << "Указатели: " << endl;
    cout << "Переменная а = " << a << endl;
    cout << "*pa = " << *pa << endl;


    cout << endl << "Указатели на функцию: " << endl;

    //указатель на функцию
    void (*fooPointer)();
    //указатель на функцию с параметрами
    void (*fooPointer1)(int a);

    fooPointer1 = Foo2;
    fooPointer = Foo1;

    //указатель вызовет функцию на которую он ссылается
    fooPointer();
    fooPointer1(4);

    //адресация компонентов класса
    cout << endl << "Адресация компонентов структуры" << endl;
    cout << "Прямая адресация: " << (new T)->a << endl;
    T *p = new T;
    cout << "Косвенная адресация: " << (*p).a << endl;

    cout << endl << "Адресация компонентов класса" << endl;
    cout << "Прямая адресация: " << (new A)->x << endl;
    A* _a = new A;
    cout << "Косвенная адресация: " << (*_a).x << endl;




}
