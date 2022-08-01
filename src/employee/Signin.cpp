#include "Signin.h"

namespace Signin {
void input(std::string &username, uint32_t &social) {
  std::cout << "\n\nSign in\n------------------\n";
  std::cout << "Username: ";
  std::getline(std::cin, username);
  std::cout << "Social-Security: ";
  std::cin >> social;
  if (std::cin.fail()) throw std::string("Invalid integer");
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return;
}

std::istream &operator>>(std::istream &in, option &option) {
  int choice;
  in >> choice;
  if (in.fail()) throw std::string("incorrect input in stream");
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  option = (Signin::option)choice;
  return in;
}
}  // namespace Signin