#ifndef SIGNIN_H_
#define SIGNIN_H_
#include <string>
#include <unordered_map>

#include "Employee.h"

class Access {
 private:
  std::unordered_map<std::string, uint16_t> accessCodes_;
};

#endif  // SIGNIN_H_