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
              << "System Menu:     0\n"
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
        break;
      }
      case Options::kRemoveCustomer: {
        break;
      }
      default: {
        break;
      }
    }
  } while (option != Options::kExit);
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
}  // namespace Records