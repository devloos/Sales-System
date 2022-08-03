#include "Buffer.h"

namespace Buffer {
void clean(std::istream &in) {
  if (in.fail()) throw std::string("Stream failed");
  in.clear();
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}