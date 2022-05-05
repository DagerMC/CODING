#include <iostream>
#include <algorithm>
#include <cstdio>

struct Element {
    int value;
    Element* next;
    Element* prev;
};

class List {
    Element* tail = new Element;
    Element* head = new Element;

    public:
    List(const List& list) {
        Element* iterator = list.tail->next;
        tail->value = list.tail->value;
        tail->prev = NULL;
        Element* temp = tail;
        while(iterator) {
            Element* ptr = new Element;
            ptr->value = iterator->value;
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            temp = ptr;
            iterator = iterator->next;
        }
        head = temp;
    }

    List() {
        tail = NULL;
        head = NULL;
    }

    List(int elements[], int n) {
        tail->value = elements[0];
        tail->next = NULL;
        tail->prev = NULL;
        Element* temp = tail;
        for (int i = 1; i <= n - 1; i++) {
            Element* ptr = new Element;
            ptr->value = elements[i];
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            temp = ptr;
        }
        head = temp;
    }

    int size() {
        int i = 0;
        Element* iterator = tail;
        while(iterator) {
            i++;
            iterator = iterator->next;
        }

        return i;
    }

    Element* retrieve(int element) {
        int size_ = size();
        if (element > size_) return NULL;
        Element* elem = tail;
        for(int i = 0; i != element; i++) {
            elem = elem->next;
        }
        return elem;
    }

    Element* end() {
        return head;
    }

    Element* first() {
        return tail;
    }

    bool insert(int value, int position) {
        Element* new_element = new    Element;
        new_element->value = value;
        Element* elem = retrieve(position);
        if (!elem) return false;
        if (elem == tail) {
            push_front(value);
            return true;
        }
        if (elem == head) {
            push_back(value);
            return true;
        }
        new_element->next = elem;
        new_element->prev = elem->prev;
        new_element->prev->next = new_element;
        elem->prev = new_element;
        
        return true;
    }

    void push_back(int value) {
        Element* new_element = new    Element;
        new_element->value = value;
        new_element->prev = NULL;
        new_element->next = tail;
        if(!tail) tail = new_element;
        else tail->prev = new_element;
        if(!head) head = new_element;
        tail = new_element;
    }

    void push_front(int value) {
        Element* new_element = new    Element;
        new_element->value = value;
        new_element->next = NULL;
        new_element->prev = head;
        if(!head) head = new_element;
        else head->next = new_element;
        if(!tail) tail = new_element;
        head = new_element;
    }

    int locate(int element) {
        Element* iterator = tail;
        int i = 0;
        while(iterator) {
            if(iterator->value == element) return i;
            i++;
            iterator = iterator->next;
        }
        
        return -1;
    }

    void print() {
        Element* element = tail;
        while (element) {
            std::cout << element->value << ' ';
            element = element->next;
        }
        std::cout << std::endl;
    }

    void delete_(int element) {
        Element* iterator = tail;
        while(iterator) {
            if(iterator->value == element) {
                if(iterator == tail) {
                    tail = tail->next;
                    delete tail->prev;
                    tail->prev = NULL;
                }
                else if(iterator == head) {
                    head = head->prev;
                    delete head->next;
                    head->next = NULL;
                }
                else {
                    iterator->prev->next = iterator->next;
                    iterator->next->prev = iterator->prev;
                    delete iterator;
                }
                return;
            }
            iterator = iterator->next;
        }
    }

    ~List() {
        while(tail->next) {
            tail = tail->next;
            delete tail->prev;
        }
        delete tail;
    }
};