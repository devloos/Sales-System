#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <limits>

#include "../employee/Auth.h"
#include "../employee/Employee.h"
#include "../employee/Signin.h"

namespace Application {
/**
 * @brief
 *
 * @param username
 * @param social
 * @param accessLevel
 */
void start(std::string &username, uint32_t &social, Access::Level &accessLevel);
}  // namespace Application

#endif  // APPLICATION_H_