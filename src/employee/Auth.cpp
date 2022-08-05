#include "Auth.h"

std::unordered_map<std::string, Access::Level> stringToLevel = {
    {"cashier", Access::Level::kCashier},
    {"shiftlead", Access::Level::kShiftLead},
    {"managment", Access::Level::kManagment}};

bool Auth::Verified(
    const std::string &filename, const std::string &username, const uint32_t &social,
    Access::Level &accessLevel) {
  std::fstream fin(filename, std::ios::in);
  if (!fin.is_open()) throw std::string("File not open");

  std::string __username, __level;
  uint32_t __social;
  while (!fin.eof()) {
    fin >> __username >> __social >> __level;
    Buffer::clean(fin);
    if (__username != username || __social != social) {
      continue;
    }
    accessLevel = stringToLevel[__level];
    return true;
  }
  fin.close();
  return false;
}

bool VerifiedAccess(
    const std::string &username, const uint32_t &social, Access::Level &accessLevel) {
  Auth access;
  return access.Verified("../api/employee.txt", username, social, accessLevel);
}