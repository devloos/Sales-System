#include <cstdint>
#include <iostream>
#include <limits>
#include <string>

namespace Signin {
void input(std::string &username, uint32_t &social) {
  std::cout << "Sign in\n------------------\n";
  std::cout << "Username: ";
  std::getline(std::cin, username);
  std::cout << "Social-Security: ";
  std::cin >> social;
  if (std::cin.fail()) throw std::string("Invalid integer");
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return;
}
}  // namespace Signin
