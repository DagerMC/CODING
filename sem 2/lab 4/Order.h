#include <iostream>
#include <string>
#include <ctime>
using std::string; using std::cout; using std::cin; using std::endl;

enum Category {
    null,
    cold_snacks,
    first_course,
    second_course,
    dessert,
    drinks,
};

class Date {
    int day;
    int month;
    int year;

    public:
    Date() {
        time_t now = time(0);

        tm *ltm = localtime(&now);
        day = ltm->tm_mday;
        month = ltm->tm_mon;
        year = ltm->tm_year + 1900;
    }

    Date(int day_, int month_, int year_):
    day(day_), month(month_), year(year_)
    {}

    Date(const Date& date) {
        day = date.day;
        month = date.month;
        year = date.year;
    }

    ~Date() {}

    inline int get_day() {return day;}

    inline int get_month() {return month;}

    inline int get_year() {return year;}

    void print() {
        cout << day << "." << month << "." << year << endl;
    }

    Date& set_day(int day_) {
        day = day_;

        return *this;
    }

    Date& set_month(int month_) {
        month = month_;

        return *this;
    }

    Date& set_year(int year_) {
        year = year_;

        return *this;
    }
};

class Cook {
    string name_;
    string surname_;

    public:
    
    Cook() {
        name_ = "default";
        surname_ = "default";
    }
    
    Cook(string name, string surname): 
    name_(name), surname_(surname)
    {}
    
    Cook(const Cook &cook) {
        name_ = cook.name_;
        surname_ = cook.surname_;
    }
    
    ~Cook() {}

    inline string get_name() {return name_;}

    inline string get_surname() {return surname_;}

    void print_data() {
        cout << name_ << " " << surname_ << endl;
    }

    Cook& set_name(string name) {
        name_ = name;

        return *this;
    }

    Cook& set_surname(string surname) {
        surname_ = surname;

        return *this;
    }
};

class Dish {
    string name_;
    int price_;
    int duration_; // в хвилинах
    Category category_;
    Cook *cook_;

    public:

    Dish() {
        name_ = "default";
        price_ = 0;
        duration_ = 0;
        category_ = null;
        cook_ = new Cook();
    }

    Dish(string name, int price, int duration, Category category, Cook* cook):
    name_(name), price_(price), duration_(duration), category_(category), cook_(cook)
    {}

    Dish(const Dish &dish) {
        name_ = dish.name_;
        price_ = dish.price_;
        duration_ = dish.duration_;
        category_ = dish.category_;
        cook_ = dish.cook_;
    }

    ~Dish() {}

    inline string get_name() {return name_;}

    inline int get_price() {return price_;}

    inline int get_duration() {return duration_;}

    inline Category get_category() {return category_;}

    inline Cook* get_cook() {return cook_;}

    void print_data() {
        cout << name_ << " " << price_ << " " << duration_ << " " << category_ << " ";
        cook_->print_data();
    }

    Dish& set_name(string name) {
        name_ = name;
        
        return *this;
    }

    Dish& set_price(int price) {
        price_ = price;
        
        return *this;
    }

    Dish& set_duration(int duration) {
        duration_ = duration;

        return *this;
    }

    Dish& set_category(Category category) {
        category_ = category;

        return *this;
    }

    Dish& set_cook(Cook* cook) {
        cook_ = cook;

        return *this;
    }
};

class Order {
    string cafe_name_;
    Date date_;
    int dish_num_;
    Dish* dishes_;

    public:

    Order() {
        cafe_name_ = "default";
        date_ = Date();
        dish_num_ = 0;
    }

    Order(string name, Date date, int dish_num, Dish dishes[]) {
        cafe_name_ = name;
        date_ = date;
        dish_num_ = dish_num;
        dishes_ = dishes;
    }

    Order(const Order &order) {
        cafe_name_ = order.cafe_name_;
        date_ = order.date_;
        dish_num_ = order.dish_num_;
        dishes_ = order.dishes_;
    }

    ~Order() {}

    void add_dish(Dish dish) {
        Dish* new_dishes = new Dish[dish_num_ + 1];
        for(int i = 0; i < dish_num_; i++) {
            new_dishes[i] = dishes_[i];
        }
        new_dishes[dish_num_] = dish;
        dish_num_ += 1;
        dishes_ = new_dishes;
    }

    inline string get_name() {return cafe_name_;}

    inline Date get_date() {return date_;}

    inline Dish* get_dishes() {return dishes_;}

    void print_data() {
        cout << endl << cafe_name_ << endl;
        date_.print();
        for (int i = 0; i < dish_num_; i++) { 
            dishes_[i].print_data();
        }
    }

    void short_print() {
        cout << endl << cafe_name_ << endl;
        date_.print();
        int overall_duration = 0;
        for (int i = 0; i < dish_num_; i++) {
            overall_duration += dishes_[i].get_duration();
        }
        cout << "It will take " << overall_duration << " minutes." << endl;
    }

    Order& set_name(string name) {
        cafe_name_ = name;
        
        return *this;
    }

    Order& set_date(Date date) {
        date_ = date;

        return *this;
    }

    Order& set_dishes(Dish* dishes, int dish_num) {
        dishes_ = dishes;
        dish_num_ = dish_num;

        return *this;
    }

};