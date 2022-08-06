#include <iostream>

#include "../exceptions/Buffer.h"

/**
 * @brief
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