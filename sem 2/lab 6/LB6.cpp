#include <iostream>
#include <string>
using std::string, std::cin, std::cout;

class ValueException {
    float x;
    float y;
    public:
    ValueException(float _x, float _y): x(_x), y(_y)
    {}

    string output() {
        if ((x < 0. || x > 20.) && (y < 0. || y > 20.))
            return string("HEIGHT and WIDTH out of range.");
        else if (x < 0. || x > 20.)
            return string("WIDTH out of range");
        else 
            return string("HEIGHT out of range");
    }
};

class Rectangle {
    float width;
    float height;
    
    public:
    Rectangle(): width(0), height(0)
    {}

    int perimeter() {return width * 2 + height * 2;}

    int area() {return width * height;}

    void set_sides(float x, float y) {
        if (x < 0. || x > 20. || y < 0. || y > 20.) 
            throw ValueException(x, y);
        width = x;
        height = y;
    }

};

int main() {
    Rectangle rect;

    while (true) {
        cout << "\nEnter width and height of rectangle(CTRL+C to exit): ";
        float width, height;
        cin >> width >> height;
        try {
            rect.set_sides(width, height);
            cout << "\nAre of rectangle: " << rect.area() << "; perimeter: " << rect.perimeter();
        } catch (ValueException exc) {
            cout << "\n" << exc.output();
        }
    }

    return 0;
}