#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"

namespace System {
bool initMenu();
bool initCustomers();
bool initReciepts(std::vector<std::ostringstream> &reciepts);
bool initItems();
void init(const Employee &employee);
}  // namespace System

#endif  // SYSTEM_H_