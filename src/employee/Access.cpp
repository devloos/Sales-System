#include "Access.h"

#include <fstream>
#include <iostream>
#include <limits>

std::unordered_map<std::string, AccessLevel::Level> stringToLevel = {
    {"cashier", AccessLevel::Level::kCashier},
    {"shiftlead", AccessLevel::Level::kShiftLead},
    {"managment", AccessLevel::Level::kManagment}};

void Access::initAccessCodes(
    const std::string &filename, AccessLevel::Level &accessLevel) {
  std::fstream inFile(filename, std::ios::in);
  if (!inFile.is_open()) throw std::string("File not open");

  std::string username;
  std::string level;
  uint32_t social;
  while (!inFile.eof()) {
    inFile >> username;
    inFile >> social;
    inFile >> level;
    inFile.clear();
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    accessCodes_[username] = social;
    accessLevel = stringToLevel[level];
  }
  inFile.close();
}

bool Access::verified(const std::string &username, const uint32_t &social) {
  std::unordered_map<std::string, uint32_t>::iterator it = accessCodes_.find(username);
  if (it == accessCodes_.end()) return false;
  if (it->second != social) return false;
  return true;
}

bool verifyAccess(
    const std::string &username, const uint32_t &social,
    AccessLevel::Level &accessLevel) {
  Access access;
  access.initAccessCodes("../api/employee.txt", accessLevel);
  return access.verified(username, social);
}