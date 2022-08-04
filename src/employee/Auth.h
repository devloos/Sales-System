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
 * @brief
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
   * @brief
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