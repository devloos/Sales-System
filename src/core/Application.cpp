#include "Application.h"

namespace Application {
void start(std::string &username, uint32_t &social, Access::Level &accessLevel) {
  Signin::option opt;
  do {
    std::cout << "Sign in: 1\n"
              << "Exit: 0\n"
              << "Option: ";
    std::cin >> opt;
    switch (opt) {
      case Signin::option::kExit: {
        std::cout << "Goodbye\n";
        break;
      }
      case Signin::option::kSignin: {
        Signin::input(username, social);
        if (!verifyAccess(username, social, accessLevel))
          std::cout << "\nInvalid Credentials\nTry Again!\n\n";
        // Checkout
        break;
      }
      default: {
        std::cout << "\nInvalid option\n\n";
        break;
      }
    }
  } while (opt != Signin::option::kExit);
  return;
}

}  // namespace Application