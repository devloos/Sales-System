#include "Application.h"

int main() {
  std::string username;
  uint32_t social;
  Access::Level accessLevel;
  try {
    Application::start(username, social, accessLevel);
  } catch (std::string e) {
    std::cout << e << "\n";
  }
  return 0;
}
