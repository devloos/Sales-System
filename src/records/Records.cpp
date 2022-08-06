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
  std::cout << std::setw(18) << "RECEIPTS\n"
            << "---------------------------\n";
  while (i < receipts.size()) {
    receipts[i].print(std::cout);
    std::cout << "\n";
    if ((i + 1) % 5 == 0) {
      char a;
      std::cout << "\nWould you like to print another 5 [N]: ";
      std::cin.get(a);
      if (a != '\n') Buffer::clean(std::cin);
      if (toupper(a) == 'N') return;
      system("clear");
    }
    ++i;
  }
  std::cout << "\nALL RECEIPTS PRINTED [Any Key to Continue]: ";
  std::cin.get();
}
void customers(const std::map<std::string, Customer> &customers) {}
}  // namespace Print
}  // namespace Records