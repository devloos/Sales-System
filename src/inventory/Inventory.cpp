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
        deleteItem(items);
        break;
      }
      case Inventory::Option::kModifyPrice: {
        modifyItem(items);
        break;
      }
      default: {
        Validation::Log("INVALID OPTION! TRY AGAIN\n");
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
    Validation::Log("ITEM ALREADY IN INVENTORY!!\n");
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

int AutoComplete(
    const std::string &result, const std::unordered_map<std::string, float> &items) {
  int count = 0;
  std::cout << std::left << "Search Queue\n"
            << "--------------\n";
  for (const auto &item : items) {
    if (item.first.substr(0, result.size()) == result) {
      std::cout << std::setw(3) << item.first << "\n";
      ++count;
    }
  }
  std::cout << std::right << "\n";
  return count;
}

void deleteItem(std::unordered_map<std::string, float> &items) {
  std::string result;
  if (!Find(items, "Delete Item", result)) return;
  items.erase(result);
  Validation::Log("Item: " + result + " was successfully erased\n");
}

void modifyItem(std::unordered_map<std::string, float> &items) {
  std::string result;
  if (!Find(items, "Modify Price", result)) return;
  float updatedPrice;
  std::cout << "Enter New Price: ";
  std::cin >> updatedPrice;
  Buffer::clean(std::cin);
  items.at(result) = updatedPrice;
  Validation::Log(
      "Item: " + result + "'s price was updated to: " + std::to_string(updatedPrice) +
      " \n");
}

bool Find(
    const std::unordered_map<std::string, float> &items, const std::string &searchType,
    std::string &result) {
  system("clear");
  std::string prev;
  int BufferAutoCompleteNum;
  do {
    std::cout << "    " + searchType + " \n"
              << "----------------------\n"
              << "Enter Item Name: " << prev;
    std::getline(std::cin, result);
    prev.append(result);
    result = prev;
    if (items.find(result) != items.end()) return true;

    system("clear");
    BufferAutoCompleteNum = AutoComplete(result, items);
  } while (BufferAutoCompleteNum > 0);
  Validation::Log("ITEM " + result + " NOT FOUND!!\n");
  return false;
}

std::istream &operator>>(std::istream &in, Inventory::Option &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (Inventory::Option)n;
  return in;
}
}  // namespace Inventory