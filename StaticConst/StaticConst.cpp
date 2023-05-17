#include <iostream>
using namespace std;

class Apple {
public:

    Apple(int weight, string color) {
        this->color = color;
        this->weight = weight;
        Count++;
        id = Count;
    }

    //генератор id-ков
    int GetId() {
        return id;
    }

    //статический метод
    static int GetCount() {
        return Count;
    }

    static void ChangeColor(Apple &apple, string color){    
        apple.color = color;
    }

private:
    int id;
    int weight;
    string color;
    static int Count;//статический объект, нужно инициализировать, один единственный для всех экземпляров класса
};

int Apple::Count = 0;//инициализация статической переменной происходит вне класса, в котором она содержится




//Передаём указатель на массив, и размер массива
void FillArray(int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

void ShowArray(const int* const arr, const int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "/t";        
    }
    cout << endl;
}

class Something
{
public:
    int m_value;

    Something() : m_value{ 0 } { }

    void setValue(int value) { m_value = value; }
    int getValue() const { return m_value; }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Apple apple(150, "red");
    Apple apple2(15, "yellow");
    Apple apple3(200, "yellow");


    cout << "Айдишники яблок:" << endl;
    cout << "id apple = " << apple.GetId() << endl;
    cout << "id apple2 = " << apple2.GetId() << endl;
    cout << "id apple3 = " << apple3.GetId() << endl;

    cout << Apple::GetCount() << endl;


    //также можно просто обратиться через название класса, а не через экземпляр класса
    Apple::ChangeColor(apple, "green");

    cout << "Константные переменные----------------" << endl;
    //Данные переменные не подлежат изменению:
    const int value1 = 5; //копирующая инициализация
    const int value2(3); //прямая
    const int value3{ 9 }; //цнифицированная

    const Something something; //константный экземпляр класса, его значения нельзя изменить в будущем
    
    something.getValue(); //константные экземпляры класса могут вызывать только константные методы
    

}
