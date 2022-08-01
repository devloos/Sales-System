#include <iostream>

#include "employee/Access.h"
#include "employee/Employee.h"

int main() {
  Employee employee("cashier", 610644209, AccessLevel::kCashier);
  if (verifyAccess("cashier", 61044209)) {
    std::cout << "working";
  }
  return 0;
}
