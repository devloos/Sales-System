#include "Access.h"

#include <fstream>
#include <iostream>
#include <limits>

void Access::initAccessCodes(const std::string &filename) {
  std::fstream inFile(filename, std::ios::in);
  if (!inFile.is_open()) throw std::string("File not open");

  std::string workID;
  uint32_t social;
  while (!inFile.eof()) {
    inFile >> workID;
    inFile >> social;
    inFile.clear();
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    accessCodes_[workID] = social;
  }
  inFile.close();
}
bool Access::verified(const std::string &workID, const uint32_t &social) {
  std::unordered_map<std::string, uint32_t>::iterator it = accessCodes_.find(workID);
  if (it == accessCodes_.end()) return false;
  if (it->second != social) return false;
  return true;
}

bool verifyAccess(const std::string &workID, const uint32_t &social) {
  Access access;
  access.initAccessCodes("../api/employee.txt");
  return access.verified(workID, social);
}