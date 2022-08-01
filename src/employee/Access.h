#ifndef SIGNIN_H_
#define SIGNIN_H_
#include <cstdint>
#include <string>
#include <unordered_map>

#include "Employee.h"

bool verifyAccess(
    const std::string &username, const uint32_t &social, AccessLevel::Level &accessLevel);

class Access {
 public:
  Access() {}
  void initAccessCodes(const std::string &filename, AccessLevel::Level &accessLevel);
  bool verified(const std::string &username, const uint32_t &social);

 private:
  std::unordered_map<std::string, uint32_t> accessCodes_;
};

#endif  // SIGNIN_H_