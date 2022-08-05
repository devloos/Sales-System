#include "System.h"

namespace System {
void init(const Employee &employee) {
  if (!initMenu()) return;
  std::unordered_map<std::string, float> items(std::move(initItems()));
  std::map<std::string, std::string> customers(std::move(initCustomers()));
  std::vector<Records::Receipt> receipts(std::move(initReceipts()));
  std::fstream oFile("../api/receipts.txt", std::ios::out);
  menu(employee, items, customers, receipts);
}

bool initMenu() {
  system("clear");
  int systemOption;
  std::cout << "      Initialize Menu\n"
            << "----------------------------\n"
            << "   Initialize System: 1\n"
            << "   Sign Out:          0\n"
            << "\n   Option:            ";
  std::cin >> systemOption;
  if (std::cin.fail()) throw std::string("Incorrect input for stream");
  Buffer::clean(std::cin);
  if (systemOption != 1) return false;
  return true;
}

std::vector<Records::Receipt> initReceipts() {
  std::fstream inFile("../api/receipts.txt", std::ios::in);
  if (!inFile.is_open()) throw std::string("Error initializing Receipts");

  std::vector<Records::Receipt> receipts;
  std::string line;
  int i = 0;

  std::getline(inFile, line);
  line = line.substr(STRING_SIZE_BEFORE_NUM, line.size());
  receipts.reserve(std::stoi(line));
  if (receipts.capacity() == 0) return receipts;

  while (!inFile.eof()) {
    receipts.emplace_back(std::move(Records::Receipt()));
    receipts[i].read(inFile);
    ++i;
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

void menu(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::map<std::string, std::string> &customers,
    std::vector<Records::Receipt> &receipts) {
  System::Option option = System::Option::kSignout;
  do {
    system("clear");
    std::cout << " Sales System\n"
              << "--------------\n"
              << " Checkout:  1\n"
              << " Records:   2\n"
              << " Inventory: 3\n"
              << " SIGN OUT:  0\n"
              << "\n Choice:    ";
    std::cin >> option;
    switch (option) {
      case System::Option::kSignout: {
        std::cout << "SIGN OUT\n";
        break;
      }
      case System::Option::kCheckout: {
        std::cout << "CHECKOUT\n";
        break;
      }
      case System::Option::kRecords: {
        std::cout << "RECORDS\n";
        break;
      }
      case System::Option::kInventory: {
        if (employee.getAccess() != Access::Level::kManagment) {
          Validation::Log("ACCESS DENIED: MANAGEMENT ACCESS ONLY!\n");
          break;
        }
        Inventory::start(items);
        break;
      }
      default: {
        Validation::Log("INVALID OPTION! TRY AGAIN\n");
        break;
      }
    }
  } while (option != System::Option::kSignout);
}

std::istream &operator>>(std::istream &in, System::Option &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (System::Option)n;
  return in;
}
}  // namespace System