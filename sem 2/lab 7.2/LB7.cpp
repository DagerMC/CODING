#include <iostream>
#include <string>
#include "lb7.h"
using std::cout, std::cin,
      std::cerr, std::string;

int main(int argc, char* argv[]) {
  int choice;
  if(argc <= 1) {
    cerr << ">> Enter file path <<";
    exit(1);
  }
  string path(argv[1]);
  do {
    cout << "\nChoose option"
         << "\n1.Writting to a clear file;"
         << "\n2.Adding new record to a file;"
         << "\n3.Edit existing record;"
         << "\n4.Print all records;"
         << "\n5.Find mobile by surname;"
         << "\n0.Exit.\n";
    cin >> choice;
    switch (choice) {
       case 0:
        break;
       case 1:
        writting(path);
        break;
       case 2:
        add_rec(path);
        break;
       case 3:
        edit_rec(path);
        break;
       case 4:
        print_recs(path);
        break;
       case 5:
        find_mob(path);
        break;
       default:
        cout << "\nwrong choice.";
    }
  } while(choice);

  return 0;
}