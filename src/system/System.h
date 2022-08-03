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

namespace System {
const uint8_t STRING_SIZE_BEFORE_NUM = 20;
const std::string DELIMITER("PLEASE COME AGAIN!!");

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
 * @return std::vector<std::ostringstream>
 */
std::vector<std::ostringstream> initReceipts();

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
    std::vector<std::ostringstream> &receipts);
}  // namespace System

#endif  // SYSTEM_H_