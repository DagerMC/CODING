#include <iostream>
#include "Lib.h"
#include <string>
using std::cout, std::string;

int main() {
  const int SIZE = 10;
  int numbers[SIZE] = {4, 5, 3, 7, -1, 9, -5, 11, 12, -100};
  List<int> list(numbers, SIZE);
  list.print();
  list.pop_back();
  list.pop_front();
  list.push_back(120);
  list.push_front(-125);
  cout << "\n";
  list.print();
  cout << "\n" << list.count()
       << " " << list.find(5);
  list.clear();
  list.push_back(5);
  list.push_front(10);
  cout << "\n";
  list.print();

  string strs[SIZE] = {"hey", "bubu", "htot", "muda", "k", "", "/", "i don't know",
                       "maybe later", "not today"};
  List<string> lstr(strs, SIZE);
  cout << std::endl;
  lstr.print();
  lstr.pop_back();
  lstr.pop_front();
  lstr.push_back("COW");
  lstr.push_front("NOWHERE");
  cout << "\n";
  lstr.print();
  cout << "\n" << lstr.count()
       << " " << lstr.find(7);
  lstr.clear();
  lstr.push_back("I'm");
  lstr.push_front("Here");
  cout << "\n";
  lstr.print();

  return 0;
}
