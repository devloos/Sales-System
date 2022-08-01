#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <cstdint>
#include <string>

enum struct AccessLevel { kCashier = 0, kShiftLead, kManagment };

class Employee {
 public:
  Employee(
      const std::string &username, const uint32_t &social,
      const AccessLevel &accessLevel);

 private:
  Employee(const Employee &rhs) {}
  Employee(Employee &&rhs) {}
  Employee &operator=(const Employee &rhs);
  Employee &operator=(Employee &&rhs);

  AccessLevel accessLevel_;
  std::string username_;
  uint32_t social_;
};

#endif  // EMPLOYEE_H_