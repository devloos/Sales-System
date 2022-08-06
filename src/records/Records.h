#ifndef RECORDS_H_
#define RECORDS_H_
#include <iomanip>
#include <map>
#include <string>
#include <vector>

#include "../employee/Employee.h"
#include "../templates/Options.h"
#include "Customer.h"
#include "Receipt.h"

namespace Records {
enum struct Options { kExit = 0, kReceipts, kCustomers, kAddCustomer, kRemoveCustomer };
void start(
    const Employee &employee, const std::vector<Receipt> &receipts,
    std::map<std::string, Customer> &customers);
namespace Print {
void receipts(const std::vector<Receipt> &receipts);
void customers(const std::map<std::string, Customer> &customers);
}  // namespace Print
}  // namespace Records

#endif  // RECORDS_H_