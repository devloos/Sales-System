#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream inFile("j.txt", std::ios::in);
  std::fstream oFile("../../inventory.txt", std::ios::out);

  std::string item;
  int price, decimal;
  while (!inFile.eof()) {
    std::getline(inFile, item);
    price = rand() % 50 + 1;
    decimal = rand() % 100;
    oFile << item << '\n' << price << '.' << decimal << '\n';
  }
  inFile.close();
  oFile.close();
  return 0;
}
