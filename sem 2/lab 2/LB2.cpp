#include <iostream>
#include "LinkedList.h"

int main() {
    int n;
    std::cout << "Enter size of list: ";
    std::cin >> n;
    int* elements = new int[n];
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> elements[i];
    }
    LinkedList list(elements, n);
    list.show_list();
    list.end_insert(-1);
    list.show_list();
    ListSort sort;
    sort.insert_sort(&list);
    list.show_list();
    list.end_insert(-1);
    list.show_list();
    selection_sort(&list);
    list.show_list();
    list.start_insert(10);
    list.show_list();
    sort.bubble_sort(&list);
    list.show_list();

    return 0;
}