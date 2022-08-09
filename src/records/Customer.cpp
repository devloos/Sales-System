#include "Customer.h"

namespace Records {
Customer::Customer(const char* name, const char* email) {
  if (name != nullptr) {
    const int NAME_SIZE = (strlen(name) + 1);
    name_ = new char[NAME_SIZE];
    memcpy(name_, name, NAME_SIZE);
    name_[NAME_SIZE] = '\0';
  }

  if (email != nullptr) {
    const int EMAIL_SIZE = (strlen(email) + 1);
    email_ = new char[EMAIL_SIZE];
    memcpy(email_, email, EMAIL_SIZE);
    email_[EMAIL_SIZE] = '\0';
  }
}

// copy constructor
Customer::Customer(const Customer &rhs) { *this = rhs; }

// copy assignment
Customer &Customer::operator=(const Customer &rhs) {
  if (this == &rhs) return *this;
  if (rhs.name_ != nullptr) {
    const int NAME_SIZE = strlen(rhs.name_);
    name_ = new char[NAME_SIZE];
    memcpy(name_, rhs.name_, NAME_SIZE);
  }

  if (rhs.email_ != nullptr) {
    const int EMAIL_SIZE = strlen(rhs.email_);
    email_ = new char[EMAIL_SIZE];
    memcpy(email_, rhs.email_, EMAIL_SIZE);
  }
  return *this;
}

// move constructor
Customer::Customer(Customer &&rhs) { *this = std::move(rhs); }

// move constructor
Customer &Customer::operator=(Customer &&rhs) {
  if (this == &rhs) return *this;
  name_ = rhs.name_;
  rhs.name_ = nullptr;

  email_ = rhs.email_;
  rhs.email_ = nullptr;

  return *this;
}

Customer::~Customer() {
  delete[] name_;
  delete[] email_;
}

const char* Customer::getName() const { return name_; }
const char* Customer::getEmail() const { return email_; }
}  // namespace Records