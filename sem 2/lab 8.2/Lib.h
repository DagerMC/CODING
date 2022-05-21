#ifndef LIB_H
#define LIB_H

#include <stdexcept>
#include <iostream>
using std::cout;

template<class T>
class Item {
  T value;

  public:
  Item<T>(): value(T()), next(NULL), prev(NULL)
  {}

  Item<T>(T val): value(val), next(NULL), prev(NULL)
  {}

  Item<T>(const Item<T> &itm) {
    value = itm.value;
    next = NULL;
    prev = NULL;
  }

  ~Item<T>() {}

  Item<T>* next;
  Item<T>* prev;
  T& val() {return value;}
};

template<class T>
class List {
  Item<T>* first_;
  Item<T>* last_;

  public:
  List<T>(): first_(Item<T>()), last_(Item<T>())
  {}

  List<T>(T arr[], int n) {
    first_ = new Item(arr[0]);

    if(n == 1) {
      last_ = first_;
      return;
    }

    Item<T>* temp = first_;
    for(int i = 1; i < n; i++) {
      Item<T>* new_itm = new Item<T>(arr[i]);
      temp->next = new_itm;
      new_itm->prev = temp;
      temp = temp->next;
    }

    last_ = temp;
  }

  List<T>(const List<T> &list) {
    Item<T>* temp = new Item(first_);
    Item<T>* itr = first_->next;

    while(itr) {
      Item<T>* new_itm = new Item(itr);
      temp->next = new_itm;
      new_itm->prev = temp;
      
      itr = itr->next;
      temp = new_itm;
    }

    last_ = temp;
  }

  ~List<T>() {}

  void print() {
    Item<T>* itr = first_;

    while(itr) {
      cout << " " << itr->val();
      itr = itr->next;
    }
  }

  int count() {
    int count = 0;
    Item<T>* itr = first_;

    while(itr) {
      count++;
      itr = itr->next;
    }

    return ++count;
  }

  T find(int pos) {
    int pos_ = 0;
    Item<T>* itr = first_;

    while (itr) {
      if (pos == pos_)
        return itr->val();
      itr = itr->next;
      pos_++;
    }

    throw std::out_of_range("out of range");
  }

  T first() {return first_->val();}
  T last() {return last_->val();}

  void clear() {
    Item<T>* itr = first_->next;

    while (itr) {
      delete itr->prev;
      itr = itr->next;
    }
    delete last_;
    first_ = NULL;
    last_ = NULL;
  }

  void push_front(T val) {
    Item<T>* new_itm = new Item(val);

    if (!first_) {
      first_ = new_itm;
      last_ = new_itm;
      return;
    }

    new_itm->next = first_;
    first_->prev = new_itm;
    first_ = new_itm;
  }

  void push_back(T val) {
    Item<T>* new_itm = new Item(val);

    if (!last_) {
      first_ = new_itm;
      last_ = new_itm;
      return;
    }

    new_itm->prev = last_;
    last_->next = new_itm;
    last_ = new_itm;
  }

  T pop_back() {
    Item<T> temp = Item(*last_);
    last_ = last_->prev;

    delete last_->next;
    last_->next = NULL;

    return temp.val();
  }

  T pop_front() {
    Item<T> temp = Item(*first_);
    first_ = first_->next;

    delete first_->prev;
    first_->prev = NULL;

    return temp.val();
  }

  void insert(int pos, T val) {
    int pos_ = 0;
    Item<T>* itr = first_;

    while (itr) {
      if (pos_ == pos)
        break;
      itr = itr->next;
      pos_++;
    }

    if (!itr)
      throw std::out_of_range("out of range");
    
    if (itr == first_) {
      push_front(val);
      return;
    }

    if (itr == last_) {
      push_back(val);
      return;
    }

    Item<T>* new_itm = new Item(val);
    new_itm->prev = itr;
    new_itm->next = itr->next;
    new_itm->prev->next = new_itm;
    new_itm->next->prev = new_itm;
  }
};

#endif