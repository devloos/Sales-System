#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fin("../../customers.txt", std::ios::in);
  std::fstream oFile("../../c2ustomers.txt", std::ios::out);

  std::string ids[100];
  std::string name[100];
  std::string email[100];
  for (int i = 0; i < 100; i++) {
    std::getline(fin, ids[i]);
  }
  for (int i = 0; i < 100; i++) {
    std::getline(fin, name[i]);
    std::getline(fin, email[i]);
  }
  for (int i = 0; i < 100; i++) {
    oFile << ids[i] << '\n';
    oFile << name[i] << '\n';
    oFile << email[i] << "\n\n";
  }
  fin.close();
  oFile.close();
  return 0;
}
