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
  Customer(const char* name = nullptr, const char* email = nullptr);

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

  /**
   * @brief Get the Name object
   *
   * @return const char*
   */
  const char* getName() const;

  /**
   * @brief Get the Email object
   *
   * @return const char*
   */
  const char* getEmail() const;

 private:
  char* name_;
  char* email_;
};
}  // namespace Records
#endif  // CUSTOMER_H_