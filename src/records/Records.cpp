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
  } while (option != Options::kExit);
}
namespace Print {
void receipts(const std::vector<Receipt> &receipts) {}
void customers(const std::map<std::string, Customer> &customers) {}
}  // namespace Print
}  // namespace Records