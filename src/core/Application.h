#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <limits>

#include "../employee/Access.h"
#include "../employee/Employee.h"
#include "../employee/Signin.h"

namespace Application {
void start(std::string &username, uint32_t &social, AccessLevel::Level &accessLevel);
}  // namespace Application

#endif  // APPLICATION_H_