#include "Inventory.h"

namespace Inventory {
void start(std::unordered_map<std::string, float> &items) {
  Option option = Option::kSystemMenu;
  do {
    system("clear");
    std::cout << "      INVENTORY\n"
              << "---------------------\n"
              << "  View Inventory: 1\n"
              << "  Add Item:       2\n"
              << "  Delete Item:    3\n"
              << "  Modify Price:   4\n"
              << "  System Menu:    0\n"
              << "\n  Choice:         ";
    std::cin >> option;
    switch (option) {
      case Inventory::Option::kSystemMenu: {
        break;
      }
      case Inventory::Option::kViewInventory: {
        viewInventory(items);
        break;
      }
      case Inventory::Option::kAddItem: {
        break;
      }
      case Inventory::Option::kDeleteItem: {
        break;
      }
      case Inventory::Option::kModifyPrice: {
        break;
      }
      default: {
        Validation::invalid("INVALID OPTION! TRY AGAIN\n");
        break;
      }
    }
  } while (option != Option::kSystemMenu);
}
void viewInventory(const std::unordered_map<std::string, float> &items) {
  system("clear");
  std::cout << "{\n";
  for (const auto &item : items) {
    std::cout << "  [\n";
    std::cout << "    \"Price\": " << item.second << "\n";
    std::cout << "    \"Item_Name\": \"" << item.first << "\"\n";
    std::cout << "  ],\n";
  }
  std::cout << "}\n\n";
  std::cout << "Press Any Key to Exit!\n";
  std::cin.get();
}
std::istream &operator>>(std::istream &in, Inventory::Option &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (Inventory::Option)n;
  return in;
}
}  // namespace Inventory