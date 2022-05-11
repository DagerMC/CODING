#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cctype>

const int LINE_LENGTH = 40;

std::string stage(std::string str) {
  int padding = (LINE_LENGTH - str.size()) / 2 + str.size();

  for(auto& c : str) {
    c = toupper(c);
  }

  std::stringstream ss;
  ss << std::setw(padding) 
     << std::setfill('#') 
     << str;
     
  for (int i = 0; i < LINE_LENGTH - padding; i++) ss << '#';

  return ss.str();
}