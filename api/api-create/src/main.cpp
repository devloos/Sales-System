#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <thread>

static bool finished = false;

void print() {
  while (!finished) {
    std::cout << "WORKING...\n";
  }
}

int main() {
  print()

      std::cin.get();
  finished = true;

  return 0;
}
