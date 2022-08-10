#include "Application.h"

int main() {
  try {
    Application::start();
  } catch (std::string e) {
    std::cout << e << "\n";
  }
  return 0;
}
