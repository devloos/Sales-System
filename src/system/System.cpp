#include "System.h"

namespace System {
void init(const Employee &employee) {
  if (!MenuInit()) return;
  std::unordered_map<std::string, float> items(std::move(ItemsInit()));
  std::map<std::string, Records::Customer> customers(std::move(CustomersInit()));
  std::vector<Records::Receipt> receipts(std::move(ReceiptsInit()));
  menu(employee, items, customers, receipts);
  Terminate(items, customers, receipts);
}

void Terminate(
    const std::unordered_map<std::string, float> &items,
    const std::map<std::string, Records::Customer> &customers,
    const std::vector<Records::Receipt> &receipts) {
  std::fstream fout("../api/inventory.txt", std::ios::out);

  {
    const int SIZE = items.size();
    int i = 1;

    for (const auto &item : items) {
      fout << item.first << "\n" << item.second;
      if (i != SIZE) fout << "\n";
      ++i;
    }
  }
  fout.close();

  fout.open("../api/customers.txt", std::ios::out);
  {
    const int SIZE = customers.size();
    int i = 1;
    for (const auto &customer : customers) {
      fout << customer.first << "\n"
           << customer.second.getName() << "\n"
           << customer.second.getEmail();
      if (i != SIZE) fout << "\n\n";
      ++i;
    }
  }
  fout.close();

  fout.open("../api/receitps.txt", std::ios::out);
  fout << "   Number of receipts: " << receipts.size() << "\n";
  {
    const int SIZE = receipts.size();
    int i = 1;
    for (const auto &receipt : receipts) {
      receipt.print(fout);
      if (i != SIZE) fout << "\n";
      ++i;
    }
  }
  fout.close();
}

bool MenuInit() {
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

std::vector<Records::Receipt> ReceiptsInit() {
  std::fstream fin("../api/receipts.txt", std::ios::in);
  if (!fin.is_open()) throw std::string("Error initializing Receipts");

  std::vector<Records::Receipt> receipts;
  std::string line;
  int i = 0;

  std::getline(fin, line);
  line = line.substr(STRING_SIZE_BEFORE_NUM, line.size());
  receipts.reserve(std::stoi(line));
  if (receipts.capacity() == 0) return receipts;

  while (!fin.eof()) {
    receipts.emplace_back(std::move(Records::Receipt()));
    receipts[i].read(fin);
    ++i;
  }
  fin.close();
  return receipts;
}

std::map<std::string, Records::Customer> CustomersInit() {
  std::fstream fin("../api/customers.txt", std::ios::in);
  if (!fin.is_open()) throw std::string("Customers file not opened");

  std::string name;
  std::string email;
  std::string uuid;
  std::string discard;
  std::map<std::string, Records::Customer> customers;

  while (!fin.eof()) {
    std::getline(fin, uuid);
    std::getline(fin, name);
    std::getline(fin, email);
    customers.emplace(uuid, Records::Customer(name.c_str(), email.c_str()));
    std::getline(fin, discard);
  }
  fin.close();
  return customers;
}

std::unordered_map<std::string, float> ItemsInit() {
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
  fin.close();
  return items;
}

void menu(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::map<std::string, Records::Customer> &customers,
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
        break;
      }
      case System::Option::kCheckout: {
        Checkout::start(employee, items, receipts, customers);
        break;
      }
      case System::Option::kRecords: {
        Records::start(employee, receipts, customers);
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