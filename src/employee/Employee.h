#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <cstdint>
#include <string>

enum struct AccessLevel { kCashier = 0, kShiftLead, kManagment };

class Employee {
 public:
  Employee(
      const std::string &workID, const uint16_t &social, const AccessLevel &accessLevel);

 private:
  Employee(const Employee &rhs) {}
  Employee(Employee &&rhs) {}
  Employee &operator=(const Employee &rhs);
  Employee &operator=(Employee &&rhs);

  AccessLevel accessLevel_;
  std::string workID_;
  uint16_t social_;
};

#endif  // EMPLOYEE_H_