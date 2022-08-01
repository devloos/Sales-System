#include <iostream>

#include "employee/Access.h"
#include "employee/Employee.h"

int main() {
  Employee employee("cashier", 421, AccessLevel::kCashier);
  Access access;
  return 0;
}
