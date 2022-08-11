#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include <limits>

#include "../employee/Auth.h"
#include "../employee/Employee.h"
#include "../employee/Signin.h"

namespace Application {
/**
 * @brief Starts the Appication, handles sign in menu. This does not handle sign in
 * input though, finally delegates system init
 */
void start();
}  // namespace Application

#endif  // APPLICATION_H_