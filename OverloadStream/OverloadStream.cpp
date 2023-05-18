#include <iostream>
using namespace std;

class Point {
public: 
    int x;
    int y;
    int z;

    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }


};


//перегрузка оператора форматного вывода
ostream& operator << (ostream& os, const Point& point) {
    os << point.x << " " << point.y << " " << point.z;
    return os;
}

//перегрузка оператора форматного ввода
istream& operator >> (istream& is, Point& point) {
    is >> point.x >> point.y >> point.z;
    return is;
}



int main()
{
    Point p{ 12, 10, 7 };
    cout << p;

    //можем также с помощью перегруженного оператора записать данные в файл
}
