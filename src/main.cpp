#include <iostream>

#include "employee/Access.h"
#include "employee/Employee.h"
#include "employee/menu.h"

int main() {
  std::string username;
  uint32_t social;
  Signin::input(username, social);
  if (verifyAccess(username, social)) std::cout << "Welcome";
  return 0;
}
