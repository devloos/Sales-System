#ifndef AUTH_H_
#define AUTH_H_
#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

#include "../exceptions/Buffer.h"
#include "Employee.h"

/**
 * @brief Delegates work to Auth class method Verified
 *
 * @param username
 * @param social
 * @param accessLevel
 * @return true
 * @return false
 */
bool VerifiedAccess(
    const std::string &username, const uint32_t &social, Access::Level &accessLevel);

class Auth {
 public:
  Auth() {}

  /**
   * @brief Handles verifying user login input, reads file and if credentials not found
   * return false
   *
   * @param filename
   * @param username
   * @param social
   * @param accessLevel
   * @return true
   * @return false
   */
  bool Verified(
      const std::string &filename, const std::string &username, const uint32_t &social,
      Access::Level &accessLevel);
};

#endif  // AUTH_H_