#ifndef CHECKOUT_H_
#define CHECKOUT_H_
#include <iomanip>
#include <map>
#include <unordered_map>
#include <vector>

#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"
#include "../inventory/Inventory.h"
#include "../records/Customer.h"
#include "../records/Receipt.h"

#define SCAN 1
#define MODIFY 2
#define EXIT 0

namespace Checkout {
/**
 * @brief
 *
 * @param employee
 * @param items
 * @param receipts
 * @param customers
 */
void start(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers);

/**
 * @brief
 *
 * @param employee
 * @param items
 * @param receipts
 * @param customers
 */
void Scan(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers);
}  // namespace Checkout

#endif  // CHECKOUT_H_