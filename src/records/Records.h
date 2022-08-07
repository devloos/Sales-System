#ifndef RECORDS_H_
#define RECORDS_H_

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

#include "../employee/Employee.h"
#include "../exceptions/Validation.h"
#include "Customer.h"
#include "Receipt.h"

namespace Records {
enum struct Options { kExit = 0, kReceipts, kCustomers, kAddCustomer, kRemoveCustomer };
const uint8_t ID_LENGTH = 36;
const uint8_t THREE_SECONDS = 3;
const int ONE_SECONDS = 1000000;

/**
 * @brief
 *
 * @param employee
 * @param receipts
 * @param customers
 */
void start(
    const Employee &employee, const std::vector<Receipt> &receipts,
    std::map<std::string, Customer> &customers);
/**
 * @brief
 *
 * @param customers
 */
void AddCustomer(std::map<std::string, Customer> &customers);

void RemoveCustomer(std::map<std::string, Customer> &customers);

namespace Print {
/**
 * @brief
 *
 * @return true
 * @return false
 */
bool AnotherFive();

/**
 * @brief
 *
 * @param receipts
 */
void receipts(const std::vector<Receipt> &receipts);

/**
 * @brief
 *
 * @param customers
 */
void customers(const std::map<std::string, Customer> &customers);
}  // namespace Print

/**
 * @brief
 *
 * @return std::string
 */
std::string GenerateId();

/**
 * @brief
 *
 * @param in
 * @param option
 * @return std::istream&
 */
std::istream &operator>>(std::istream &in, Options &option);
}  // namespace Records

#endif  // RECORDS_H_