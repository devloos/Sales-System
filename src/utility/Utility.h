#ifndef UTILITY_H_
#define UTILITY_H_
#include <unistd.h>

#include <iostream>
#include <string>

namespace Utility {
// Used for system sleep
const int TWO_SECONDS = 2000000;

/**
 * @brief Logging system
 *
 * @param e
 */
void Log(const std::string &e);
}  // namespace Utility

#endif  // UTILITY_H_