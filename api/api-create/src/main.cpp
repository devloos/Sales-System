#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fin("../../customers.txt", std::ios::in);
  std::fstream oFile("../../c2ustomers.txt", std::ios::out);

  std::string fname, lname, email;
  while (!fin.eof()) {
    std::getline(fin, fname);
    std::getline(fin, lname);
    std::getline(fin, email);
    oFile << fname << " " << lname << '\n' << email << '\n';
  }
  return 0;
}
