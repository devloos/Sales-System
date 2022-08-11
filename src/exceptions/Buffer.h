#ifndef BUFFER_H_
#define BUFFER_H_
#include <iostream>
#include <istream>
#include <limits>

namespace Buffer {
/**
 * @brief handles cleaning any type of buffer
 * if buffer failed then exception is thrown
 *
 * @param in
 */
void clean(std::istream &in);
}  // namespace Buffer

#endif  // BUFFER_H_