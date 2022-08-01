#ifndef AUTH_H_
#define AUTH_H_
#include <cstdint>
#include <string>
#include <unordered_map>

#include "Employee.h"

bool verifyAccess(
    const std::string &username, const uint32_t &social, Access::Level &accessLevel);

class Auth {
 public:
  Auth() {}
  void initAccessCodes(const std::string &filename, Access::Level &accessLevel);
  bool verified(const std::string &username, const uint32_t &social);

 private:
  std::unordered_map<std::string, uint32_t> accessCodes_;
};

#endif  // AUTH_H_