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
        addItem(items);
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
    std::cout << "  [\n"
              << "    \"Item_Name\": \"" << item.first << "\"\n"
              << "    \"Price\": " << item.second << "\n"
              << "  ],\n";
  }
  std::cout << "}\n\n";
  std::cout << "Press Any Key to Exit!\n";
  std::cin.get();
}

void addItem(std::unordered_map<std::string, float> &items) {
  system("clear");
  std::cout << "    Add Item\n"
            << "----------------\n"
            << "Enter Item Name: ";
  std::string itemName;
  std::getline(std::cin, itemName);

  if (items.find(itemName) != items.end()) {
    Validation::invalid("ITEM ALREADY IN INVENTORY!!\n");
    return;
  }

  float price = 0.0f;
  std::cout << "Enter Item Price: ";
  std::cin >> price;
  Buffer::clean(std::cin);

  items[itemName] = price;
  system("clear");
  std::cout << "Item: " << itemName << " ADDED SUCCESSFULLY!!\n";
  usleep(2000000);
}

std::istream &operator>>(std::istream &in, Inventory::Option &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (Inventory::Option)n;
  return in;
}
}  // namespace Inventory