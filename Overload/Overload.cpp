#include <iostream>
using namespace std;

/*Перегрузка функций*/
int Sum(int a, int b) {
    return a + b;
}

double Sum(double a, double b) {
    return a + b;
}

/*Перегрузка операторов*/
class Counter
{
public:
    Counter(int val)
    {
        value = val;
    }
    void print()
    {
        std::cout << "Value: " << value << std::endl;
    }
        
    //Функции оператора
    Counter operator + (const Counter& counter) const
    {
        return Counter{ value + counter.value };
    }
    int operator + (int number) const
    {
        return value + number;
    }

    //Оператор присвоения
    Counter& operator += (const Counter& counter)
    {
        value += counter.value;
        return *this;   // возвращаем ссылку на текущий объект
    }

    //Операторы сравнения:
    bool operator == (const Counter& counter) const
    {
        return value == counter.value;
    }
    bool operator != (const Counter& counter) const
    {
        return value != counter.value;
    }
    bool operator > (const Counter& counter) const
    {
        return value > counter.value;
    }
    bool operator < (const Counter& counter) const
    {
        return value < counter.value;
    }

    //Префиксные операторы
    Counter& operator++ ()
    {
        value += 1;
        return *this;
    }
    Counter& operator-- ()
    {
        value -= 1;
        return *this;
    }

    //Постфиксные операторы
    Counter operator++ (int)
    {
        Counter copy{ *this };
        ++(*this);
        return copy;
    }
    Counter operator-- (int)
    {
        Counter copy{ *this };
        --(*this);
        return copy;
    }
private:
    int value;
};

int main()
{
    Counter counter{ 20 };
    int number = counter + 30;
    cout << number << endl;

    Counter c1(20);
    Counter c2(10);
    bool b1 = c1 == c2;     // false
    bool b2 = c1 > c2;   // true

    cout << "c1 == c2 = " << boolalpha << b1 << endl;    // c1 == c2 = false
    cout << "c1 > c2 = " << boolalpha << b2 << endl;     // c1 > c2 = true

}