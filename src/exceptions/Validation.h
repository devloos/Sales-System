#ifndef VALIDATION_H_
#define VALIDATION_H_
#include <unistd.h>

#include <iostream>
#include <string>

namespace Validation {
// Used for system sleep
const int TWO_SECONDS = 2000000;

/**
 * @brief Logging system
 *
 * @param e
 */
void Log(const std::string &e);
}  // namespace Validation

#endif  // VALIDATION_H_