#include "Application.h"

#include <unistd.h>

#include "../system/System.h"
#include "../utility/Buffer.h"

namespace Application {
void start() {
  std::string username;
  uint32_t social;
  Access::Level accessLevel;
  Signin::Options opt;
  do {
    system("clear");
    std::cout << "  SIGN IN\n"
              << "------------\n";
    std::cout << " Sign in: 1\n"
              << " Exit:    0\n\n"
              << " Options: ";
    std::cin >> opt;
    switch (opt) {
      case Signin::Options::kExit: {
        std::cout << "\n GOODBYE!\n";
        break;
      }
      case Signin::Options::kSignin: {
        Signin::input(username, social);
        if (!VerifiedAccess(username, social, accessLevel)) {
          std::cout << "\nCredentials not valid\nTry Again!\n";
          usleep(2000000);
          break;
        }
        Employee employee(username, social, accessLevel);
        System::init(employee);
        break;
      }
      default: {
        std::cout << "\nOptions: " << (int)opt << " is not a valid Options\n";
        usleep(2000000);
        break;
      }
    }
  } while (opt != Signin::Options::kExit);
  return;
}

}  // namespace Application