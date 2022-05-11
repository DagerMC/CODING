#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using std::cout, std::cin,
      std::cerr, std::string,
      std::ifstream, std::ofstream,
      std::fstream, std::ios,
      std::ostream;

const int LENGTH = 15;

ostream& left(ostream&);
ostream& right(ostream&);

void writting(string path) {
  ofstream file(path, ios::in | ios::trunc);
  if (!file) {
    cerr << "\nFILE NOT OPEN";
    exit(1);
  }

  string surname, mobile;
  cout << "\nEnter a recond in such format: Surname mobile;"
       << "\nEnter 0 0 to stop.\n";

  while (true) {
    cin >> surname >> mobile;

    if(surname[0] == '0' && mobile[0] == '0') 
      break;

    file << left << surname
         << right << mobile
         << std::endl;
    // file.write(surname.data(), surname.size())
  }

  file.close();
}

void add_rec(string path) {
  ofstream file(path, ios::app);
  if (!file) {
    cerr << "\nFILE NOT OPEN";
    exit(1);
  }

  string surname, mobile;
  cout << "\nEnter a recond in such format: Surname mobile: "
       << "\nEnter 0 0 to stop.\n";

  while (true) {
    cin >> surname >> mobile;

    if(surname[0] == '0' && mobile[0] == '0') 
      break;

    file << left << surname
         << right << mobile
         << std::endl;
  }

  file.close();
}

void edit_rec(string path) {
  fstream file(path, ios::in | ios::out);
  if (!file) {
    cerr << "\nFILE NOT OPEN";
    exit(1);
  }

  string surname, sn;
  cout << "\nEnter surname of record you want to edit: ";
  cin >> surname;
  while(!file.eof()) {
    file >> sn;
    if (sn == surname)
      break;
  }

  if (sn != surname) {
    cout << "\nNo such record.";
    return;
  }

  long pos = file.tellg();
  file.seekp(pos - sn.size() - 2);
  cout << "\nEnter new record in format: Surname mobile: ";
  cin >> surname >> sn;
  file << left << surname
       << right << sn << std::endl;

  file.close();
}

void print_recs(string path) {
  ifstream file(path);  
  if (!file) {
    cerr << "\nFILE NOT OPEN";
    exit(1);
  }

  while(!file.eof()) {
    string sn, mob;
    file >> sn >> mob;

    cout << left << std::setfill('-') << sn
         << right << mob << "\n";
  }
  
  file.close();
}

void find_mob(string path) {
  ifstream file(path);  
  if (!file) {
    cerr << "\nFILE NOT OPEN";
    exit(1);
  }

  string surname, sn;
  cout << "\nEnter surname: ";
  cin >> surname;

  while(!file.eof()) {
    file >> sn;
    if (sn == surname)
      break;
  }

  if (sn != surname) {
    cout << "\nNo such record.";
    return;
  }
  file >> sn;

  cout << left << std::setfill('-') << surname
       << right << sn << std::endl;

  file.close();
}

ostream& left(ostream& of) {
  of.setf(ios::left, ios::adjustfield);
  of.width(LENGTH);

  return of;
}
 
ostream& right(ostream& of) {
  of.setf(ios::right, ios::adjustfield);
  of.width(LENGTH);

  return of;
}