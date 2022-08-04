#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <unistd.h>

#include <iostream>
#include <string>
#include <unordered_map>

#include "../exceptions/Buffer.h"
#include "../exceptions/Validation.h"

namespace Inventory {
enum struct Option {
  kSystemMenu = 0,
  kViewInventory,
  kAddItem,
  kDeleteItem,
  kModifyPrice,
};
void start(std::unordered_map<std::string, float> &items);
void viewInventory(const std::unordered_map<std::string, float> &items);
std::istream &operator>>(std::istream &in, Inventory::Option &option);
}  // namespace Inventory

#endif  // INVENTORY_H_