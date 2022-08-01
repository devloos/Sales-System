#include "Employee.h"

Employee::Employee(
    const std::string &workID, const uint32_t &social, const AccessLevel &accessLevel)
    : workID_(workID), social_(social), accessLevel_(accessLevel) {}