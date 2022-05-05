#include <iostream>
#include <algorithm>

struct ListElement {
    int value;
    ListElement* next;
};

class LinkedList {
    ListElement* first_element = new ListElement;
    ListElement* head = new ListElement;

    
    ListElement* find_last() {
        ListElement* elem = first_element;
        while (true) {
            if (elem->next == NULL) {
                return elem;
            }
            elem = elem->next;
        }
    }
    public:
    LinkedList(int elements[], int n) {
        first_element->value = elements[0];
        first_element->next = NULL;
        ListElement* temp = first_element;
        for (int i = 1; i < n - 1; i++) {
            ListElement* ptr = new ListElement;
            ptr->value = elements[i];
            temp->next = ptr;
            temp = ptr;
        }
        head->value = elements[n - 1];
        head->next = NULL;
        temp->next = head;
    }

    void end_insert(int element) {
        ListElement* new_element = new ListElement;
        head->next = new_element;
        new_element->value = element;
        new_element->next = NULL;
        head = new_element;
    }

    void start_insert(int element) {
        ListElement* new_element = new ListElement;
        new_element->value = element;
        new_element->next = first_element;
        first_element = new_element;
    }

    void show_list() {
        ListElement* element = first_element;
        while (element) {
            std::cout << element->value << ' ';
            element = element->next;
        }
        std::cout << std::endl;
    }

    int list_size() {
        int i = 0;
        ListElement* iterator = first_element;
        while (iterator) {
            iterator = iterator->next;
            i++; 
        }

        return i;
    }

    void friend selection_sort(LinkedList*);
    friend class ListSort;
};

class ListSort {
    public:
    void bubble_sort(LinkedList* list) {
        int size = list->list_size();
        for (int i = 0; i < size - 1; i++) {
            int j = 0;
            for (ListElement* current = list->first_element; j < size - i - 1; current = current->next, j++) {
                if (current->value > current->next->value) {
                    std::swap(current->value, current->next->value);
                }
            }
        }
    }

    void insert_sort(LinkedList* list) {
        for (ListElement* current = list->first_element; current;) {
            ListElement* iterating_element;
            if (current->next) {
                iterating_element = current->next;
            }
            else {
                iterating_element = current;
            }
            ListElement* iterator = list->first_element;
            bool first_iterating = true;
            while (iterator != iterating_element) {
                if (first_iterating) {
                    if (iterating_element->value < iterator->value) {
                        current->next = iterating_element->next;
                        iterating_element->next = iterator;
                        list->first_element = iterating_element;
                        break;
                    }
                }
                if (iterating_element->value < iterator->next->value) {
                    current->next = iterating_element->next;
                    iterating_element->next = iterator->next;
                    iterator->next = iterating_element;
                    break;
                }
                iterator = iterator->next;
                if (iterator == iterating_element) {
                    current = current->next;
                }
            }
        }
        list->head = list->find_last();
    }
};

void selection_sort(LinkedList* list) {
    ListElement* start_element = list->first_element;
    while (start_element) {
        ListElement* smallest_element = start_element;
        ListElement* current_element = start_element->next;
        while (current_element) {
            if (current_element->value < smallest_element->value) {
                smallest_element = current_element;
            }
            current_element = current_element->next;
        }
        std::swap(start_element->value, smallest_element->value);
        start_element = start_element->next;
    }
}