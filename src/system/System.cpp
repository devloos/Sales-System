#include "System.h"

namespace System {
void init(const Employee &employee) {
  if (!initMenu()) return;
  std::map<std::string, std::string> customers;
  std::unordered_map<std::string, float> items;
  std::vector<std::ostringstream> reciepts(std::move(initReciepts()));
  std::cin.get();
}

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

std::vector<std::ostringstream> initReciepts() {
  std::fstream inFile("../api/reciepts.txt", std::ios::in);
  if (!inFile.is_open()) throw std::string("Error initializing Reciepts");

  std::vector<std::ostringstream> reciepts;
  std::string delimiter("PLEASE COME AGAIN!!");
  std::string line;
  int i = 0;

  std::getline(inFile, line);
  line = line.substr(STRING_SIZE_BEFORE_NUM, line.size());
  reciepts.reserve(std::stoi(line));
  if (reciepts.capacity() != 0) reciepts.push_back(std::ostringstream());

  while (std::getline(inFile, line)) {
    reciepts[i] << line << "\n";
    if (line == delimiter && !inFile.eof()) {
      reciepts[i] << "\n";
      reciepts.push_back(std::ostringstream());
      ++i;
    }
  }
  inFile.close();
  return reciepts;
}

std::map<std::string, std::string> initCustomers() {}
std::unordered_map<std::string, float> initItems() {}
}  // namespace System