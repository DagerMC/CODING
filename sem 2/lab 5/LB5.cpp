#include <iostream>
#include <string>
using std::string; using std::cout; using std::cin; using std::endl;

class Work {
    protected:
    string type;
    int duration;

    public:
    Work(): type("default"), duration(0)
    {}

    Work(string type_, int duration_): type(type_), duration(duration_)
    {}

    virtual void work() {
        cout << "Doing " << type << " work, it would take " << duration << " minutes.\n";
    }

    string get_type() {return type;}
    int get_duration() {return duration;}

    void set_type(string type_) {type = type_;}
    void set_duration(int dur_) {duration = dur_;}
};

class Performer {
    protected:
    string name;
    string typep;

    public:
    Performer(): name("DEFAULT"), typep("MACHINE")
    {}
    
    Performer(string name_, string typep_): name(name_), typep(typep_)
    {}

    string get_name() {return name;}
    string get_type() {return typep;}

    void set_name(string name_) {name = name_;}
    void set_type(string type_) {typep = type_;}
};

class Job : public Work, private Performer {
    protected:
    int salary;

    public:
    Job(): Work(), Performer(), salary(0)
    {}

    Job(string type_, int duration_, string name_, string typep_, int salary_):
    Work(type_, duration_), Performer(name_, typep_), salary(salary_)
    {}

    Job(string type_, int duration_, int salary_):
    Work(type_, duration_), Performer(), salary(salary_)
    {}

    virtual void work() {
        cout << typep
             << " "
             << name
             << " doing " 
             << type 
             << " job. It will take " 
             << duration 
             << " minutes and will give " 
             << salary 
             << " money.\n";
    }

    int get_salary() {return salary;}

    void set_salary(int sal) {salary = sal;}
};

class Human : private Job {
    protected:
    string name;
    int age;
    
    public:
    Human(): Job(), name("Default"), age(0)
    {}

    Human(string type_, int duration_, int salary_, string name_, int age_):
    Job(type_, duration_, salary_), name(name_), age(age_)
    {}

    Human(string name_, int age_): Job(), name(name_), age(age_)
    {}

    string get_name() {return name;}
    int get_age() {return age;}

    void set_name(string name_) {name = name_;}
    void set_age(int age_) {age = age_;}

    virtual void work() {
        cout << age
             << " years old "
             << name
             << " doing "
             << type 
             << " job. It will take "
             << duration 
             << " minutes, and will give him "
             << salary 
             << " money.\n";
    }
};

class Child : public Human {
    protected:
    string favourite_game;

    public:
    Child(): Human(), favourite_game("nothing")
    {}

    Child(string name_, int age_, string fav_game): Human(name_, age_), favourite_game(fav_game)
    {}

    string get_game() {return favourite_game;}
    void set_game(string game) {favourite_game = game;}

    virtual void work() {
        cout << name
             << " is only "
             << age
             << " years old. He can't work, he's just playing his favourite game - "
             << favourite_game
             << ".\n";
    } 
};

int main() {
    Work work("physical", 20);
    work.work();
    
    Job job("programming", 60, "OpenAI", "Artificial Intelligence", 1800);
    job.work();

    Human human("cleaning", 120, 1000, "Donatello Picking", 45);
    human.work();

    Child child("David", 12, "football");
    child.work();

    return 0;
}