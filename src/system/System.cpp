#include "System.h"

namespace System {
bool initMenu() {
  system("clear");
  int systemOption;
  std::cout << "Initialize System: 1\n"
            << "Back to Sign in: Any Number\n"
            << "Option: ";
  std::cin >> systemOption;
  if (std::cin.fail()) throw std::string("Incorrect input for stream");
  Buffer::clean(std::cin);
  if (systemOption != 1) return false;
  return true;
}

bool initCustomers() {}
bool initReciepts(std::vector<std::ostringstream> &reciepts) {
  std::fstream inFile("../api/reciepts.txt", std::ios::in);
  if (!inFile.is_open()) return false;
  std::string line;
  std::string delimiter("PLEASE COME AGAIN\n");
  int i = 0;
  reciepts.push_back(std::ostringstream());
  while (!inFile.eof()) {
    std::getline(inFile, line);
    reciepts[i] << line << '\n';
    if (line == delimiter) {
      reciepts.push_back(std::ostringstream());
      ++i;
    }
  }
  inFile.close();
  reciepts.pop_back();
  std::cout << reciepts[0].str();
  return true;
}
bool initItems() {}

void init(const Employee &employee) {
  if (!initMenu()) return;
  std::map<std::string, std::string> customers;
  std::unordered_map<std::string, float> items;
  std::vector<std::ostringstream> reciepts;
  if (!initReciepts(reciepts)) throw std::string("Error initializing Reciepts");
}
}  // namespace System