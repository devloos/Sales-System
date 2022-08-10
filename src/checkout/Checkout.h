#ifndef CHECKOUT_H_
#define CHECKOUT_H_
#include <stdlib.h>

#include <algorithm>
#include <cstdint>
#include <ctime>
#include <iomanip>
#include <map>
#include <random>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../employee/Employee.h"
#include "../exceptions/Buffer.h"
#include "../inventory/Inventory.h"
#include "../records/Customer.h"
#include "../records/Receipt.h"
#include "../records/Records.h"

#define PURCHASE 1
#define MODIFY 2
#define EXIT 0

namespace Checkout {
struct CurrCustomer {
  std::string uuid_;
  std::string name_;
  std::string email_;
};

enum struct Options { kDropTransaction = 0, kViewItems, kDiscount, kPurchase };

const float TAX_MULTIPLIER = 0.0775f;

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
void Purchase(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers);

void Finalize(
    const std::unordered_map<std::string, float> &CartItems,
    std::vector<Records::Receipt> &receipts, const bool &EXISTING_CUSTOMER,
    std::map<std::string, Records::Customer> &customers, const CurrCustomer &customer);

namespace Handle {
/**
 * @brief
 *
 * @param CartItems
 * @param Subtotal
 * @return Records::Receipt
 */
Records::Receipt Receipt(
    const std::unordered_map<std::string, float> CartItems, const float &Subtotal);

/**
 * @brief
 *
 * @param CurrCustomer
 */
void NewCustomer(Checkout::CurrCustomer &CurrCustomer);

/**
 * @brief
 *
 * @param customers
 * @param customer
 */
void ExistingCustomer(
    std::map<std::string, Records::Customer> &customers, CurrCustomer &customer);
/**
 * @brief
 *
 * @param items
 * @param CartItems
 */
void Scan(
    const std::unordered_map<std::string, float> &items,
    std::unordered_map<std::string, float> &CartItems);

/**
 * @brief
 *
 * @param CartItems
 * @return float
 */
float Subtotal(const std::unordered_map<std::string, float> &CartItems);

/**
 * @brief
 *
 * @param total
 */
void Discount(float &total);
}  // namespace Handle
std::istream &operator>>(std::istream &in, Options &option);
}  // namespace Checkout

#endif  // CHECKOUT_H_