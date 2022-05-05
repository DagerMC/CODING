#include <iostream>
#include "StcQue.h"

int main() {
    int n;
    std::cout << "Enter lenght of Stack:" << std::endl;;
    std::cin >> n;
    std::cout << "Enter elements of Stack: " << std::endl;
    Stack stack(n);
    bool keep = true;
    while(keep) {
        std::cout << "Enter method you want to use. pop(1), push(2), top(3), clear(4), empty(5), print(6). 0 - to exit." << std::endl;
        int method;
        std::cin >> method;
        switch(method) {
            case 1:
                stack.pop();
                std::cout << "Done." << std::endl;
                break;
            case 2:
                std::cout << "Enter value: ";
                int num;
                std::cin >> num;
                stack.push(num);
                break;
            case 3:
                std::cout << stack.top() << std::endl;
                break;
            case 4:
                stack.clear();
                std::cout << "Done" << std::endl;
                break;
            case 5:
                if(stack.empty()) {
                    std::cout << "Empty." << std::endl;
                } 
                else {
                    std::cout << "Not empty" << std::endl;
                }
                break;
            case 6:
                stack.print();
                break;
            case 0:
                keep = false;

        }
    }
    std::cout << "Enter lenght of Queue:" << std::endl;;
    std::cin >> n;
    std::cout << "Enter elements of Queue: " << std::endl;
    Queue queue(n);
    keep = true;
    while(keep) {
        std::cout << "Enter method you want to use. dequeue(1), enqueue(2), front(3), clear(4), empty(5), print(6). 0 - to exit." << std::endl;
        int method;
        std::cin >> method;
        switch(method) {
            case 1:
                queue.dequeue();
                std::cout << "Done." << std::endl;
                break;
            case 2:
                std::cout << "Enter value: ";
                int num;
                std::cin >> num;
                queue.enqueue(num);
                break;
            case 3:
                std::cout << queue.front() << std::endl;
                break;
            case 4:
                queue.clear();
                std::cout << "Done" << std::endl;
                break;
            case 5:
                if(queue.empty()) {
                    std::cout << "Empty." << std::endl;
                } 
                else {
                    std::cout << "Not empty" << std::endl;
                }
                break;
            case 6:
                queue.print();
                break;
            case 0:
                keep = false;

        }
    }

    return 0;
}