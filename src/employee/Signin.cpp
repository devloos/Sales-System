#include "Signin.h"

#include "../utility/Buffer.h"

namespace Signin {
void input(std::string &username, uint32_t &social) {
  system("clear");
  std::cout << "         Login\n"
            << "------------------------\n"
            << " Username: ";
  std::getline(std::cin, username);
  std::cout << " Social-Security: ";
  std::cin >> social;

  if (std::cin.fail()) throw std::string("Invalid integer");
  Buffer::clean(std::cin);
  return;
}

std::istream &operator>>(std::istream &in, Options &option) {
  int choice;
  in >> choice;
  Buffer::clean(in);
  option = (Signin::Options)choice;
  return in;
}
}  // namespace Signin