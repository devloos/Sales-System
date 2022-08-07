#include "Checkout.h"

namespace Checkout {
void start(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers) {
  int option = EXIT;
  do {
    system("clear");
    std::cout << std::setw(16) << "CHECKOUT\n"
              << "------------------------\n"
              << " Scan Customer Items: 1\n"
              << " Modify Price:        2\n"
              << " System Menu:         0\n\n"
              << " CHOICE:              ";
    std::cin >> option;
    Buffer::clean(std::cin);

    switch (option) {
      case EXIT:
        break;
      case PURCHASE: {
        Purchase(employee, items, receipts, customers);
        break;
      }
      case MODIFY: {
        if (employee.getAccess() == Access::Level::kManagment) {
          Inventory::modifyItem(items);
        } else {
          Validation::Log("MANGMENT ACCESS ONLY!\n");
        }
        break;
      }
      default: {
        Validation::Log("INPUT NOT IN RANGE TRY AGAIN!\n");
        break;
      }
    }
  } while (option != EXIT);
  return;
}

void Purchase(
    const Employee &employee, std::unordered_map<std::string, float> &items,
    std::vector<Records::Receipt> &receipts,
    std::map<std::string, Records::Customer> &customers) {
  std::unordered_map<std::string, float> CartItems;
  const bool NewCustomer = rand() % 2;
  CurrCustomer customer;
  Options option = Options::kDropTransaction;

  Handle::Scan(items, CartItems);
  float total = Handle::Total(CartItems);
  if (NewCustomer) {
    Handle::NewCustomer(customer);
  } else {
    Handle::ExistingCustomer(customers, customer);
  }

  do {
    system("clear");
    std::cout << std::setw(28) << "CUSTOMER INFO\n"
              << "------------------------------------------\n"
              << "UUID: " << customer.uuid_ << "\n"
              << "NAME: " << customer.name_ << "\n"
              << "EMAIL: " << customer.email_ << "\n"
              << "PURCHASE TOTAL: " << total << "\n\n"
              << "           PURCHASE\n"
              << "------------------------------\n"
              << " View Items:               1\n"
              << " Discount:                 2\n"
              << " Purchase & Print Receipt: 3\n"
              << " Drop Transaction:         0\n\n"
              << " CHOICE:                   ";
    std::cin >> option;
    switch (option) {
      case Options::kDropTransaction: {
        break;
      }
      case Options::kViewItems: {
        Inventory::viewInventory(CartItems);
        break;
      }
      case Options::kDiscount: {
        if (employee.getAccess() == Access::Level::kCashier) {
          Validation::Log("MANGMENT AND LEAD ACCESS ONLY!!!\n");
          break;
        }
        Handle::Discount(total);
        break;
      }
      case Options::kPurchase: {
        break;
      }
      default: {
        Validation::Log("INPUT NOT IN RANGE TRY AGAIN!!\n");
        break;
      }
    }
  } while (option != Options::kDropTransaction);
}

void Finalize() {}

namespace Handle {
void Discount(float &total) {
  system("clear");
  float discount;
  std::cout << "           DISCOUNT\n"
            << "-----------------------------\n";
  std::cout << "Enter Discount Amount: ";
  std::cin >> discount;
  Buffer::clean(std::cin);

  if (discount > total) {
    Validation::Log("INVALID DISCOUNT AMOUNT!!!\n");
    return;
  }

  total -= discount;
}
float Total(const std::unordered_map<std::string, float> &CartItems) {
  float sum = 0.0f;
  for (const auto &item : CartItems) {
    sum += item.second;
  }
  return sum;
}

void ExistingCustomer(
    std::map<std::string, Records::Customer> &customers, CurrCustomer &customer) {
  auto rand_between = [](const int &start, const int &end) {
    int difference = end - start;
    return rand() % difference + start;
  };

  auto random_it = std::next(customers.begin(), rand_between(0, customers.size() - 1));
  customer.uuid_ = random_it->first;
  customer.name_ = random_it->second.getName();
  customer.email_ = random_it->second.getEmail();

  return;
}

void NewCustomer(Checkout::CurrCustomer &customer) {
  Validation::Log("YOU GOT A NEW CUSTOMER!!!\n");
  system("clear");
  std::cout << std::setw(37) << "DETAILS OF NEW CUSTOMER\n"
            << "------------------------------------------\n"
            << "UUID: ";
  customer.uuid_ = Records::GenerateId();
  std::cout << customer.uuid_ << '\n' << "NAME: ";
  std::getline(std::cin, customer.name_);
  std::cout << "EMAIL: ";
  std::getline(std::cin, customer.email_);
  return;
}

void Scan(
    const std::unordered_map<std::string, float> &items,
    std::unordered_map<std::string, float> &CartItems) {
  if (items.empty()) return;
  const uint8_t TOTAL_ITEMS = rand() % 20 + 1;

  auto rand_between = [](const int &start, const int &end) {
    int difference = end - start;
    return rand() % difference + start;
  };

  for (int i = 0; i < TOTAL_ITEMS; i++) {
    auto random_it = std::next(std::begin(items), rand_between(0, items.size() - 1));
    CartItems[random_it->first] = random_it->second;
  }
}
}  // namespace Handle
std::istream &operator>>(std::istream &in, Options &option) {
  int n;
  in >> n;
  Buffer::clean(in);
  option = (Options)n;
  return in;
}
}  // namespace Checkout
