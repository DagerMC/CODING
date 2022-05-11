#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <iomanip>
#include <cctype>
#include "lb7.h"
using std::cout, std::cin, 
      std::cerr, std::ios, 
      std::string, std::ifstream, 
      std::ofstream, std::fstream,
      std::set;

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    cout << ">> Enter file path <<";
    exit(1);
  }

  string path(argv[1]);
  ifstream input(path, ios::out);
  if (!input) {
    cerr << "ERROR FILE NOT OPEN";
    exit(1);
  }

  set<string> words;
  
  while(!input.eof()) {
    string temp;
    input >> temp;

    for(auto& c : temp) {
      if(!temp.size()) break;
      if(!isalpha(c)) temp.erase(temp.find(c));
    }

    if(temp.size()) {
      temp[0] = tolower(temp[0]);
      words.insert(temp);
    }
  }  

  ofstream test("testing.txt", ios::in), workf("workfile.txt", ios::in);
  if (!test || !workf) {
    cerr << "ERROR FILE NOT OPEN";
    exit(1);
  }

  test << stage("input") << std::endl;
  input.seekg(input.beg);
  while(!input.eof()) {
    string temp;
    std::getline(input, temp);
    test << temp << "\n";
  }

  test << "\n" << stage("getting sorted words") << "\n";
  int length = 0;
  for(const auto word : words) {
    length += word.size();
    if (length > 40) { 
      test << "\n";
      length = 0;
    }
    test << word << ", ";
  }

  test << "\n" << stage("checking letters") << "\n";
  set<std::pair<string, string>> pairs;
  char letter = 'a';
  for(auto word : words) {
    if(word[0] != letter) 
      letter = word[0];
    auto itr = words.find(word);

    try {
      string temp = *(++itr);
      while(temp[0] == letter && itr != words.end()) {

        if (word[word.size() - 1] != temp[temp.size() - 1]) {
          temp = *(++itr);
          continue;
        }

        if (word.size() > temp.size()) {
          pairs.insert(std::pair<string, string> {word, temp});
          temp = *(++itr);
          continue;
        }

        pairs.insert(std::pair<string, string> {temp, word});
        temp = *(++itr);
      }
    } catch (std::length_error const&) {}
  }

  for(const auto pair : pairs) {
    test << std::setw(19) << std::right
         << std::get<0>(pair) << " & " 
         << std::setw(21) << std::left 
         << std::get<1>(pair) << "\n";
    workf << std::setw(19) << std::right
          << std::get<0>(pair) << " & " 
          << std::setw(21) << std::left 
          << std::get<1>(pair) << "\n";
  }
  test << "Amount of pairs - " << pairs.size();
  workf << "Amount of pairs - " << pairs.size();

  workf.close();
  test.close();
  input.close();
  return 0;
}