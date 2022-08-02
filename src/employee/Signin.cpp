#include "Signin.h"

#include "../exceptions/Buffer.h"

namespace Signin {
void input(std::string &username, uint32_t &social) {
  system("clear");
  std::cout << "Sign in\n------------------\n"
            << "Username: ";
  std::getline(std::cin, username);
  std::cout << "Social-Security: ";
  std::cin >> social;

  if (std::cin.fail()) throw std::string("Invalid integer");
  Buffer::clean(std::cin);
  return;
}

std::istream &operator>>(std::istream &in, option &option) {
  int choice;
  in >> choice;
  if (in.fail()) throw std::string("incorrect input in stream");
  Buffer::clean(in);
  option = (Signin::option)choice;
  return in;
}
}  // namespace Signin