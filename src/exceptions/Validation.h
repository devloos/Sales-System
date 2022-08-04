#ifndef VALIDATION_H_
#define VALIDATION_H_
#include <unistd.h>

#include <iostream>
#include <string>

namespace Validation {
const int TWO_SECONDS = 2000000;

/**
 * @brief
 *
 * @param e
 */
void invalid(const std::string &e);
}  // namespace Validation

#endif  // VALIDATION_H_