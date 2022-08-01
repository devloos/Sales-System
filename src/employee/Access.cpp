#include "Access.h"

#include <fstream>
#include <iostream>
#include <limits>

void Access::initAccessCodes(const std::string &filename) {
  std::fstream inFile(filename, std::ios::in);
  if (!inFile.is_open()) throw std::string("File not open");

  std::string username;
  uint32_t social;
  while (!inFile.eof()) {
    inFile >> username;
    inFile >> social;
    inFile.clear();
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    accessCodes_[username] = social;
  }
  inFile.close();
}
bool Access::verified(const std::string &username, const uint32_t &social) {
  std::unordered_map<std::string, uint32_t>::iterator it = accessCodes_.find(username);
  if (it == accessCodes_.end()) return false;
  if (it->second != social) return false;
  return true;
}

bool verifyAccess(const std::string &username, const uint32_t &social) {
  Access access;
  access.initAccessCodes("../api/employee.txt");
  return access.verified(username, social);
}