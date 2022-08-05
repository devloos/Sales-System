#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"
#include "../exceptions/Validation.h"
#include "../inventory/Inventory.h"
#include "../records/Receipt.h"

namespace System {
const uint8_t STRING_SIZE_BEFORE_NUM = 23;
enum struct Option { kSignout = 0, kCheckout, kRecords, kInventory };

/**
 * @brief
 *
 * @param employee
 */
void init(const Employee &employee);

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool initMenu();

/**
 * @brief
 *
 * @return std::map<std::string, std::string>
 */
std::map<std::string, std::string> initCustomers();

/**
 * @brief
 *
 * @return std::vector<Records::Receipt>
 */
std::vector<Records::Receipt> initReceipts();

/**
 * @brief
 *
 * @return std::unordered_map<std::string, float>
 */
std::unordered_map<std::string, float> initItems();

/**
 * @brief
 *
 * @param employee
 * @param items
 * @param customer
 * @param receipts
 */
void menu(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::map<std::string, std::string> &customer,
    std::vector<Records::Receipt> &receipts);

/**
 * @brief
 *
 * @param in
 * @param option
 * @return std::istream&
 */
std::istream &operator>>(std::istream &in, System::Option &option);
}  // namespace System

#endif  // SYSTEM_H_