#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

namespace Records {
class Customer {
 public:
  /**
   * @brief Construct a new Customer object
   *
   * @param name
   * @param email
   */
  Customer(const char* name, const char* email);

  /**
   * @brief Construct a new Customer object
   *
   * @param customer
   */
  Customer(const Customer &customer);

  /**
   * @brief
   *
   * @param customer
   * @return Customer&
   */
  Customer &operator=(const Customer &customer);

  /**
   * @brief Construct a new Customer object
   *
   * @param customer
   */
  Customer(Customer &&customer);

  /**
   * @brief
   *
   * @param customer
   * @return Customer&
   */
  Customer &operator=(Customer &&customer);

  /**
   * @brief Destroy the Customer object
   *
   */
  ~Customer();

 private:
  char* name_;
  char* email_;
};

bool operator<(const Customer &lhs, const Customer &rhs);
}  // namespace Records
#endif  // CUSTOMER_H_