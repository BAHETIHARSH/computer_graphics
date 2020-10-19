#include <iostream>
#include <string>
using namespace std;
class shape
{
public:
    double length;
    double width;

public:
    void get_data()
    {
        cout << "length : ";
        cin >> length;
        cout << "width : ";
        cin >> width;
    }
};
class triangle : public shape
{
public:
    void display_area()
    {
        double area;
        area = 0.5 * length * width;
        cout << "Area of Triangle is " << area << "\n";
    }
};
class rectangle : public shape
{
public:
    void display_area()
    {
        double area1;
        area1 = length * width;
        cout << "Area of Rectangle " << area1 << endl;
    }
};

int main()
{
    triangle T;
    T.get_data();
    T.display_area();

    rectangle r;
    r.get_data();
    r.display_area();
}