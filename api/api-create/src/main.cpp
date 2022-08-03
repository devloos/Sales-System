#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream inFile("../../customers.txt", std::ios::in);
  std::fstream oFile("../../c2ustomers.txt", std::ios::out);

  std::string fname, lname, email;
  while (!inFile.eof()) {
    std::getline(inFile, fname);
    std::getline(inFile, lname);
    std::getline(inFile, email);
    oFile << fname << " " << lname << '\n' << email << '\n';
  }
  return 0;
}
