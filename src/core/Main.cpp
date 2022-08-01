#include "Application.h"

int main() {
  std::string username;
  uint32_t social;
  Access::Level accessLevel;
  Application::start(username, social, accessLevel);
  return 0;
}
