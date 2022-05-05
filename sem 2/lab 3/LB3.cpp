#include <iostream>
#include "LinkedList.h"

void plus_one(ListElement*);

int main() {
    std::cout << "Enter size of the list: ";
    int n1;
    std::cin >> n1;
    int* arr1 = new int[n1];
    std::cout << "Enter elements: ";
    for(int i = 0; i < n1; i++) {
        std::cin >> arr1[i];
    }
    LinkedList list1(arr1, n1); 
    list1.show_list();
    std::cout << "Enter size of the list: ";
    int n2;
    std::cin >> n2;
    int* arr2 = new int[n2];
    std::cout << "Enter elements: ";
    for(int i = 0; i < n2; i++) {
        std::cin >> arr2[i];
    }
    LinkedList list2(arr2, n2); 
    list2.show_list();
    list1 = list1 + list2;
    list1.show_list();
    FILE* f = fopen("test.txt", "w");
    list1 >> f;
    fclose(f);
    LinkedList list3;
    f = fopen("test.txt", "r");
    list3 << f;
    fclose(f);
    list3.show_list();
    list3.pop_back();
    list3.push_back(10);
    std::cout << list3.max() << " " << list3.min() << " " << list3.accumulate() << std::endl;
    list3.show_list();
    list1.swap(&list2, 2);
    list1.show_list();
    list2.show_list();
    list1.push_back(5);
    list1.push_back(5);
    list1.push_front(5);
    list1.insert(10, 3);
    list1.show_list();
    if(list1.find(5)) {
        list1.sort();
        list1.show_list();
        list1.unique();
        list1.show_list();
        list1.push_front(5);
        list1.show_list();
        list1.remove(5);
    }
    list1.show_list();
    list1.for_each(plus_one);
    list1.show_list();
    if(list1 == list2) {
        std::cout << "list1 equals list2" << std::endl;
    } else {
        std::cout << "list1 not equals list2" << std::endl;
    }
    list1 = list2;
    if(list1 == list2) {
        std::cout << "list1 equals list2" << std::endl;
    } else {
        std::cout << "list1 not equals list2" << std::endl;
    }

    return 0;
}

void plus_one(ListElement* element) {
    element->value += 1;
}