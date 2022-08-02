#include "Buffer.h"

namespace Buffer {
void clean(std::istream &in) {
  in.clear();
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}