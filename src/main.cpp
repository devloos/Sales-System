#include <iostream>

#include "employee/Access.h"
#include "employee/Employee.h"
#include "employee/menu.h"

int main() {
  std::string username;
  uint32_t social;
  AccessLevel::Level accessLevel;
  Signin::input(username, social);
  if (verifyAccess(username, social, accessLevel)) std::cout << "Welcome";
  return 0;
}
