#include <iostream>
#include <string>
#include "Order.h"
using std::string; using std::cout; using std::cin; using std::endl;

int main() {
    Cook* cooks = new Cook[3];
    cooks[0] = Cook();
    cout << "Enter cook's name and surname: ";
    string name, surname;
    cin >> name >> surname;
    cooks[1] = Cook(name, surname);
    cooks[2] = Cook(cooks[1]);
    cooks[2].set_name("David").set_surname("Gonchar");

    Dish* dishes = new Dish[3];
    dishes[0] = Dish();
    cout << "Enter name, price, cooking duration, category and cook(1 or 2) of the dish: ";
    int price, duration, choice;
    int category_;
    cin >> name >> price >> duration >> category_ >> choice;
    Category category = static_cast<Category>(category_);
    dishes[1] = Dish(name, price, duration, category, &cooks[choice]);
    dishes[2] = Dish(dishes[1]);
    dishes[2].set_name("Borsch").set_price(50).set_duration(45).set_category(first_course);

    Order* orders = new Order[3];
    orders[0] = Order();
    cout << "Enter cafe's name, date: ";
    int day, month, year;
    Date date;
    cin >> name >> day >> month >> year;
    date.set_day(day).set_month(month).set_year(year);
    orders[1] = Order(name, date, 3, dishes);
    orders[2] = Order(orders[1]);
    orders[2].set_name("Paulo's cafe");
    for(int i = 0; i < 3; i++) {
        orders[i].print_data();
        orders[i].short_print();
    }
    orders[2].add_dish(Dish("Fish", 20, 30, second_course, &cooks[1]));
    orders[2].print_data();
    orders[2].short_print();

    return 0;
}