#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../checkout/Checkout.h"
#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"
#include "../exceptions/Validation.h"
#include "../inventory/Inventory.h"
#include "../records/Customer.h"
#include "../records/Receipt.h"
#include "../records/Records.h"

namespace System {
const uint8_t STRING_SIZE_BEFORE_NUM = 23;
enum struct Option { kSignout = 0, kCheckout, kRecords, kInventory };

/**
 * @brief Declares and holds items, customers, and receipts data structures
 * if user initializes system then all data structures get initialized
 * handles self termination call
 * @param employee - hold employee signed in
 */
void init(const Employee &employee);

/**
 * @brief Terminates program and writes files to store data
 *
 * @param items
 * @param customers
 * @param receipts
 */
void Terminate(
    const std::unordered_map<std::string, float> &items,
    const std::map<std::string, Records::Customer> &customers,
    const std::vector<Records::Receipt> &receipts);

/**
 * @brief User choice to init system
 *
 * @return true
 * @return false
 */
bool MenuInit();

/**
 * @brief Initializes Customers
 *
 * @return std::map<std::string, Records::Customer>
 */
std::map<std::string, Records::Customer> CustomersInit();

/**
 * @brief Initializes Receipts
 *
 * @return std::vector<Records::Receipt>
 */
std::vector<Records::Receipt> ReceiptsInit();

/**
 * @brief Initializes Items
 *
 * @return std::unordered_map<std::string, float>
 */
std::unordered_map<std::string, float> ItemsInit();

/**
 * @brief This is the main menu of the application every flows back and through here
 * Delegates to Checkout, Records, and Inventory
 *
 * @param employee
 * @param items
 * @param customer
 * @param receipts
 */
void menu(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::map<std::string, Records::Customer> &customer,
    std::vector<Records::Receipt> &receipts);

/**
 * @brief Overloaded bitwise operator to handle System::Option
 *
 * @param in
 * @param option
 * @return std::istream&
 */
std::istream &operator>>(std::istream &in, System::Option &option);
}  // namespace System

#endif  // SYSTEM_H_