#include "Checkout.h"

namespace Checkout {
void start(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers) {
  int option = EXIT;
  do {
    system("clear");
    std::cout << std::setw(16) << "CHECKOUT\n"
              << "------------------------\n"
              << " Scan Customer Items: 1\n"
              << " Modify Price:        2\n"
              << " System Menu:         0\n\n"
              << " CHOICE:              ";
    std::cin >> option;
    Buffer::clean(std::cin);

    switch (option) {
      case EXIT:
        break;
      case SCAN: {
        break;
      }
      case MODIFY: {
        if (employee.getAccess() == Access::Level::kManagment) {
          Inventory::modifyItem(items);
        } else {
          Validation::Log("MANGMENT ACCESS ONLY!\n");
        }
        break;
      }
      default: {
        Validation::Log("INPUT NOT IN RANGE TRY AGAIN!\n");
        break;
      }
    }
  } while (option != EXIT);
  return;
}

void Scan(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers) {}
}  // namespace Checkout
