#include "Employee.h"

Employee::Employee(
    const std::string &username, const uint32_t &social,
    const AccessLevel::Level &accessLevel)
    : username_(username), social_(social), accessLevel_(accessLevel) {}