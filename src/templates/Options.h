#include <iostream>

#include "../utility/Buffer.h"

/**
 * @brief was going to be used to pass in any menu option
 *
 * @tparam ENUM
 * @param in
 * @param option
 * @return std::istream&
 */
template <typename ENUM>
std::istream &operator>>(std::istream &in, ENUM &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (ENUM)n;
  return in;
}