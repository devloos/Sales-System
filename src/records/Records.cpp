#include "Records.h"

namespace Records {
void start(
    const Employee &employee, const std::vector<Receipt> &receipts,
    std::map<std::string, Customer> &customers) {
  Options option = Options::kExit;
  do {
    system("clear");
    std::cout << std::setw(14) << "RECORDS\n"
              << "-------------------\n"
              << "Print Receipts:  1\n"
              << "Print Customers: 2\n"
              << "Add Customer:    3\n"
              << "Remove Customer: 4\n"
              << "System Menu:     0\n\n"
              << "CHOICE:          ";
    std::cin >> option;
    switch (option) {
      case Options::kExit:
        break;
      case Options::kReceipts: {
        Print::receipts(receipts);
        break;
      }
      case Options::kCustomers: {
        Print::customers(customers);
        break;
      }
      case Options::kAddCustomer: {
        if (employee.getAccess() == Access::Level::kCashier) {
          Validation::Log("MANAGMENT AND LEAD ACCESS ONLY!!\n");
          break;
        }
        AddCustomer(customers);
        break;
      }
      case Options::kRemoveCustomer: {
        if (employee.getAccess() == Access::Level::kCashier) {
          Validation::Log("MANAGMENT AND LEAD ACCESS ONLY!!\n");
          break;
        }
        RemoveCustomer(customers);
        break;
      }
      default: {
        Validation::Log("ENTER NUMBER IN RANGE\n");
        break;
      }
    }
  } while (option != Options::kExit);
}

void AddCustomer(std::map<std::string, Customer> &customers) {
  system("clear");
  std::string name;
  std::string email;

  auto header = []() {
    std::cout << std::setw(23) << "ADD CUSTOMER\n"
              << "----------------------------------\n";
  };
  header();
  std::cout << "NAME: ";
  std::getline(std::cin, name);
  std::cout << "EMAIL: ";
  std::getline(std::cin, email);

  for (int i = 1; i <= THREE_SECONDS; i++) {
    system("clear");
    header();
    std::cout << "NAME: " << name << "\n"
              << "EMAIL: " << email << "\n\n";
    std::cout << "GENERATING ID " << std::setw(i + 1) << std::setfill('.') << '\n'
              << std::setfill(' ');
    usleep(ONE_SECONDS);
  }
  customers.emplace(GenerateId(), Customer(name.c_str(), email.c_str()));
  Validation::Log("CUSTOMER: " + name + " HAS BEEN ADDED!\n");
}

void RemoveCustomer(std::map<std::string, Customer> &customers) {
  system("clear");
  std::string UUID;

  std::cout << std::setw(30) << "REMOVE CUSTOMER\n"
            << "------------------------------------------\n"
            << "UUID: ";
  std::getline(std::cin, UUID);
  if (!customers.erase(UUID)) {
    Validation::Log("CUSTOMER WITH UUID: " + UUID + " WAS NOT FOUND\n");
    return;
  }
  Validation::Log("CUSTOMER WITH UUID: " + UUID + " WAS ERASED\n");
  return;
}

namespace Print {
void receipts(const std::vector<Receipt> &receipts) {
  int i = 0;
  system("clear");
  auto header = []() {
    std::cout << std::setw(18) << "RECEIPTS\n"
              << "---------------------------\n";
  };
  header();
  while (i < receipts.size()) {
    receipts[i].print(std::cout);
    std::cout << "\n";
    if ((i + 1) % 5 == 0) {
      if (!AnotherFive()) return;
      header();
    }
    ++i;
  }
  std::cout << "\nALL RECEIPTS PRINTED [Any Key to Continue]: ";
  std::cin.get();
}

void customers(const std::map<std::string, Customer> &customers) {
  int i = 0;
  system("clear");
  auto header = []() {
    std::cout << std::setw(26) << "Customers\n"
              << "------------------------------------------\n";
  };
  header();
  for (const auto &customer : customers) {
    std::cout << "\n";
    std::cout << "UUID: " << customer.first << '\n'
              << "NAME: " << customer.second.getName() << '\n'
              << "EMAIL: " << customer.second.getEmail() << '\n';
    if ((i + 1) % 5 == 0) {
      if (!AnotherFive()) return;
      header();
    }
    ++i;
  }
  std::cout << "\nALL CUSTOMERS PRINTED [Any Key to Continue]: ";
  std::cin.get();
}

bool AnotherFive() {
  char a;
  std::cout << "\nWould you like to print another 5 [N]: ";
  std::cin.get(a);
  if (a != '\n') Buffer::clean(std::cin);
  if (toupper(a) == 'N') return false;
  system("clear");
  return true;
}
}  // namespace Print

std::string GenerateId() {
  std::string _id;
  char c;
  srand(time(NULL));
  for (int i = 0; i < ID_LENGTH; i++) {
    if (rand() % 2) {
      c = rand() % 25 + 97;
    } else {
      c = rand() % 9 + 48;
    }
    switch (i) {
      case 9:
      case 14:
      case 19:
      case 24:
        c = '-';
        break;
      default:
        break;
    }
    _id.push_back(c);
  }
  return _id;
}
std::istream &operator>>(std::istream &in, Options &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (Options)n;
  return in;
}
}  // namespace Records