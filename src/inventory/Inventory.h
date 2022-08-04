#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <unistd.h>

#include <iomanip>
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

/**
 * @brief
 *
 * @param items
 */
void start(std::unordered_map<std::string, float> &items);

/**
 * @brief
 *
 * @param items
 */
void viewInventory(const std::unordered_map<std::string, float> &items);

/**
 * @brief
 *
 * @param items
 */
void addItem(std::unordered_map<std::string, float> &items);

/**
 * @brief
 *
 * @param keys
 * @param items
 */
int AutoComplete(
    const std::string &keys, const std::unordered_map<std::string, float> &items);

/**
 * @brief
 *
 * @param items
 */
void deleteItem(std::unordered_map<std::string, float> &items);

/**
 * @brief
 *
 * @param items
 */
void modifyItem(std::unordered_map<std::string, float> &items);

/**
 * @brief
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