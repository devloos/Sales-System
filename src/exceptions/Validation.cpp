#include "Validation.h"

namespace Validation {
void Log(const std::string &e) {
  system("clear");
  std::cout << e;
  usleep(TWO_SECONDS);
}
}  // namespace Validation