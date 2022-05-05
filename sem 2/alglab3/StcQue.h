#include <iostream>

struct Item {
    int value;
    Item* next;
};

class Stack {
    Item* _top;

    public:
    Stack() {
        _top = NULL;
    }

    Stack(int n) {
        Item* itm = new Item;
        itm->next = NULL;
        std::cin >> itm->value;
        for(int i = 0; i < n - 1; i++) {
            Item* ptr = new Item;
            std::cin >> ptr->value;
            ptr->next = itm;
            itm = ptr;
        }
        _top = itm;
    }

    void push(int num) {
        Item* new_itm = new Item;
        new_itm->next = _top;
        new_itm->value = num;
        _top = new_itm;
    }

    void pop() {
        if(!(_top->next)) {
            delete _top;
            _top = NULL;
            return;
        }
        Item* temp = _top->next;
        delete _top;
        _top = temp;
    }

    int top() { return _top->value; }

    void clear() {
        Item* iterator = _top;
        while(iterator->next) {
            Item* temp = iterator->next;
            delete iterator;
            iterator = temp;
        }
        delete iterator;
        _top = NULL;
    }

    bool empty() {
        if(!_top) {
            return true;
        }
        return false;
    }

    void print() {
        Item* iterator = _top;
        while(iterator) {
            std::cout << iterator->value << "->";
            iterator = iterator->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~Stack() { clear(); }
};

class Queue {
    Item* _front;
    Item* back;

    public:
    Queue() {
        _front = NULL;
        back = NULL;
    }
    
    Queue(int n) {
        Item* itm = new Item;
        itm->next = NULL;
        std::cin >> itm->value;
        _front = itm;
        for(int i = 0; i < n - 1; i++) {
            Item* ptr = new Item;
            std::cin >> ptr->value;
            itm->next = ptr;
            itm = ptr;
        }
        back = itm;
        back->next = NULL;
    }

    void clear() {
        Item* iterator = _front;
        while(iterator->next) {
            Item* ptr = iterator->next;
            delete iterator;
            iterator = ptr;
        }
        _front = NULL;
        back = NULL;
    }

    int front() { return _front->value; }

    void enqueue(int num) {
        Item* new_item = new Item;
        new_item->value = num;
        new_item->next = NULL;
        if(!back) {
            _front = new_item;
            back = new_item;
            return;
        }
        back->next = new_item;
        back = new_item;
    }

    void dequeue() {
        if(!_front->next) {
            delete _front;
            back = NULL;
            _front = NULL;
            return;
        }
        Item* temp = _front->next;
        delete _front;
        _front = temp;
    }

    bool empty() {
        if(!_front) return true;
        return false;
    }

    void print() { 
        Item* iterator = _front;
        while(iterator) {
            std::cout << iterator->value << "->";
            iterator = iterator->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~Queue() { clear(); }
};