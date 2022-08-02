#include "System.h"

namespace System {
bool initMenu() {
  system("clear");
  int systemOption;
  std::cout << "Initialize System: 1\n"
            << "Back to Sign in: Any Number\n"
            << "Option: ";
  std::cin >> systemOption;
  if (std::cin.fail()) throw std::string("Incorrect input for stream");
  Buffer::clean(std::cin);
  if (systemOption != 1) return false;
  return true;
}

void init(const Employee &employee) {
  if (!initMenu()) return;
}
}  // namespace System