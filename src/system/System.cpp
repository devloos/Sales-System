#include "System.h"

namespace System {
void init(const Employee &employee) {
  if (!initMenu()) return;
  std::map<std::string, std::string> customers(std::move(initCustomers()));
  std::unordered_map<std::string, float> items(std::move(initItems()));
  std::vector<std::ostringstream> receipts(std::move(initReceipts()));
  for (auto item : items) {
    std::cout << "Item Name: " << item.first << "\nItem Price: " << item.second << '\n';
  }
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

std::vector<std::ostringstream> initReceipts() {
  std::fstream inFile("../api/receipts.txt", std::ios::in);
  if (!inFile.is_open()) throw std::string("Error initializing Receipts");

  std::vector<std::ostringstream> receipts;
  std::string delimiter("PLEASE COME AGAIN!!");
  std::string line;
  int i = 0;

  std::getline(inFile, line);
  line = line.substr(STRING_SIZE_BEFORE_NUM, line.size());
  receipts.reserve(std::stoi(line));
  if (receipts.capacity() != 0) receipts.push_back(std::ostringstream());

  while (std::getline(inFile, line)) {
    receipts[i] << line << "\n";
    if (line == delimiter && !inFile.eof()) {
      receipts[i] << "\n";
      receipts.push_back(std::ostringstream());
      ++i;
    }
  }
  inFile.close();
  return receipts;
}

std::map<std::string, std::string> initCustomers() {
  std::fstream fin("../api/customers.txt", std::ios::in);
  if (!fin.is_open()) throw std::string("Customers file not opened");

  std::string name, email;
  std::map<std::string, std::string> customers;
  while (!fin.eof()) {
    std::getline(fin, name);
    std::getline(fin, email);
    customers[name] = email;
  }
  fin.close();
  return customers;
}

std::unordered_map<std::string, float> initItems() {
  std::fstream fin("../api/inventory.txt", std::ios::in);
  if (!fin.is_open()) throw std::string("Inventory file did not open");

  std::unordered_map<std::string, float> items;
  std::string itemName;
  float itemPrice;
  while (!fin.eof()) {
    std::getline(fin, itemName);
    fin >> itemPrice;
    Buffer::clean(fin);
    items[itemName] = itemPrice;
  }
  return items;
}
}  // namespace System