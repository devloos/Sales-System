#include "Customer.h"

namespace Records {
Customer::Customer(const char* name, const char* email) {
  const int NAME_SIZE = (strlen(name) + 1);
  name_ = new char[NAME_SIZE];
  memcpy(name_, name, NAME_SIZE);
  name_[NAME_SIZE] = '\0';

  const int EMAIL_SIZE = (strlen(email) + 1);
  email_ = new char[EMAIL_SIZE];
  memcpy(email_, email, EMAIL_SIZE);
  email_[EMAIL_SIZE] = '\0';
}

Customer::Customer(const Customer &customer) {}
Customer &Customer::operator=(const Customer &customer) {}

Customer::Customer(Customer &&customer) {}
Customer &Customer::operator=(Customer &&customer) {}

Customer::~Customer() {
  delete[] name_;
  delete[] email_;
}

}  // namespace Records