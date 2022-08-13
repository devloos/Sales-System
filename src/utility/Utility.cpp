#include "Utility.h"

namespace Utility {
void Log(const std::string &e) {
  system("clear");
  std::cout << e;
  usleep(TWO_SECONDS);
}
}  // namespace Utility