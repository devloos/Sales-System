#ifndef SIGNIN_H_
#define SIGNIN_H_
#include <cstdint>
#include <iostream>
#include <istream>
#include <limits>
#include <string>

namespace Signin {
enum struct option { kExit = 0, kSignin };
void input(std::string &username, uint32_t &social);
std::istream &operator>>(std::istream &in, option &option);
}  // namespace Signin

#endif  // SIGNIN_H_