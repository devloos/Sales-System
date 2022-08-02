#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <fstream>
#include <iostream>

#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"

namespace System {
bool initMenu();
void init(const Employee &employee);
}  // namespace System

#endif  // SYSTEM_H_