#include "Application.h"

#include <unistd.h>

namespace Application {
void start(std::string &username, uint32_t &social, Access::Level &accessLevel) {
  Signin::option opt;
  do {
    system("clear");
    std::cout << "Sign in: 1\n"
              << "Exit: 0\n"
              << "Option: ";
    std::cin >> opt;
    switch (opt) {
      case Signin::option::kExit: {
        std::cout << "\nGOODBYE!\n";
        break;
      }
      case Signin::option::kSignin: {
        Signin::input(username, social);
        if (!verifyAccess(username, social, accessLevel)) {
          std::cout << "\nCredentials not valid\nTry Again!\n";
          usleep(2000000);
          break;
        }
        // std::cout <<
        // Checkout::initSystem();
        break;
      }
      default: {
        std::cout << "\nOption: " << (int)opt << " is not a valid option\n";
        usleep(2000000);
        break;
      }
    }
  } while (opt != Signin::option::kExit);
  return;
}

}  // namespace Application