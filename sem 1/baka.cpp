#include <cstdio>
#include <iostream>
#include <cstring>

class Airship {
    private:
    char destination[256];
    int capacity;
    public:
    Airship(const char* destination_, int capacity_) {
        strcpy(destination, destination_);
        capacity = capacity_;
    }
    char* get_dest() {return destination;}
    int get_cap() {return capacity;}
};

int main() {
    const int size = 3;
    Airship ship_array[size] = {
        Airship("Minsk", 15),
        Airship("Kiev", 10),
        Airship("Berlin", 20)
    };
    std::cout << ship_array[0].get_dest() << std::endl;
    std::cout << ship_array[1].get_dest() << std::endl;
    std::cout << ship_array[2].get_cap() << std::endl;

    return 0;
}