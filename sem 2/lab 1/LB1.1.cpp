#include <ctime>
#include <iostream>

class Stopwatch {
    private:
    clock_t start_time;
    clock_t end_time;
    bool ended;
    
    public:
    Stopwatch() {
        start_time = 0;
        ended = false;
    }

    void start() {
        start_time = clock();
        ended = false;
    }

    void end() {
        end_time = clock();
        ended = true;
    }

    void show() {
        if (ended) {
            std::cout << (end_time - start_time)/1000. << " ᥪ㭤" << std::endl;
        }
        else {
            end_time = clock();
            std::cout << (end_time - start_time)/1000. << " ᥪ㭤" << std::endl;
        }
    }
};

int main() {
    Stopwatch watch1, watch2;
    watch1.start();
    for(int i = 0; i < 1000000000; i++);
    std::cout << "1 ";
    watch1.show();
    for(int i = 0; i < 1000000000; i++);
    std::cout << "1 ";
    watch1.show();
    watch1.end();
    std::cout << "1 ";
    watch1.show();
    watch2.start();
    for(int i = 0; i < 1000000000; i++);
    std::cout << "1 ";
    watch1.show();
    watch2.end();
    std::cout << "2 ";
    watch2.show();

    return 0;
}