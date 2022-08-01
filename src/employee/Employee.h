#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <cstdint>
#include <string>
#include <unordered_map>

namespace Access {
enum struct Level { kCashier = 0, kShiftLead, kManagment };
}  // namespace Access

class Employee {
 public:
  Employee(
      const std::string &username, const uint32_t &social,
      const Access::Level &accessLevel);

 private:
  Employee(const Employee &rhs) {}
  Employee(Employee &&rhs) {}
  Employee &operator=(const Employee &rhs);
  Employee &operator=(Employee &&rhs);

  Access::Level accessLevel_;
  std::string username_;
  uint32_t social_;
};

#endif  // EMPLOYEE_H_