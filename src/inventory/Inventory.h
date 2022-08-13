#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../utility/Buffer.h"
#include "../utility/Utility.h"

namespace Inventory {
enum struct Option {
  kSystemMenu = 0,
  kViewInventory,
  kAddItem,
  kDeleteItem,
  kModifyPrice,
};

/**
 * @brief Handles menu for Inventory, with that comes the delegation of the menu
 * such as View Inventory, Add Item, Delete Item, and Modify Price only Management access
 *
 * @param items
 */
void start(std::unordered_map<std::string, float> &items);

/**
 * @brief Outputs items in json format
 *
 * @param items
 */
void viewInventory(const std::unordered_map<std::string, float> &items);

/**
 * @brief Handles adding an item into items data structure
 *
 * @param items
 */
void addItem(std::unordered_map<std::string, float> &items);

/**
 * @brief Auto completes user input used for Deleting Item currently cannot add
 * input into the istream buffer so hardcoded search add to ostream
 *
 * @param keys
 * @param items
 */
int AutoComplete(
    const std::string &keys, const std::unordered_map<std::string, float> &items);

/**
 * @brief Handles deleting an item from items data structure
 *
 * @param items
 */
void deleteItem(std::unordered_map<std::string, float> &items);

/**
 * @brief Updates item price if it exists
 *
 * @param items
 */
void modifyItem(std::unordered_map<std::string, float> &items);

/**
 * @brief Handles Utility that item exists in data structure
 *
 * @param items
 * @param searchType
 * @param result
 * @return true
 * @return false
 */
bool Find(
    const std::unordered_map<std::string, float> &items, const std::string &searchType,
    std::string &result);

/**
 * @brief
 *
 * @param in
 * @param option
 * @return std::istream&
 */
std::istream &operator>>(std::istream &in, Inventory::Option &option);
}  // namespace Inventory

#endif  // INVENTORY_H_