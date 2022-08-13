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
          Utility::Log("MANGMENT ACCESS ONLY!\n");
        }
        break;
      }
      default: {
        Utility::Log("INPUT NOT IN RANGE TRY AGAIN!\n");
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
  std::srand(std::time(nullptr));
  const bool EXISTING_CUSTOMER = bool(rand() % 4);
  CurrCustomer customer;
  Options option = Options::kDropTransaction;

  Handle::Scan(items, CartItems);
  float Subtotal = Handle::Subtotal(CartItems);
  if (EXISTING_CUSTOMER) {
    Handle::ExistingCustomer(customers, customer);
  } else {
    Handle::NewCustomer(customer);
  }

  do {
    system("clear");
    std::cout << std::setw(28) << "CUSTOMER INFO\n"
              << "------------------------------------------\n"
              << "UUID: " << customer.uuid_ << "\n"
              << "NAME: " << customer.name_ << "\n"
              << "EMAIL: " << customer.email_ << "\n"
              << "PURCHASE TOTAL: " << Subtotal << "\n\n"
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
          Utility::Log("MANGMENT AND LEAD ACCESS ONLY!!!\n");
          break;
        }
        Handle::Discount(Subtotal);
        break;
      }
      case Options::kPurchase: {
        Finalize(CartItems, receipts, EXISTING_CUSTOMER, customers, customer);
        std::cout << "\nENTER ANY KEY TO RETURN: ";
        std::cin.get();
        return;
      }
      default: {
        Utility::Log("INPUT NOT IN RANGE TRY AGAIN!!\n");
        break;
      }
    }
  } while (option != Options::kDropTransaction);
}

void Finalize(
    const std::unordered_map<std::string, float> &CartItems,
    std::vector<Records::Receipt> &receipts, const bool &EXISTING_CUSTOMER,
    std::map<std::string, Records::Customer> &customers, const CurrCustomer &customer) {
  system("clear");
  receipts.push_back(Handle::Receipt(CartItems, Handle::Subtotal(CartItems)));
  if (!EXISTING_CUSTOMER) {
    customers[customer.uuid_] =
        Records::Customer(customer.name_.c_str(), customer.email_.c_str());
    std::cout << "NEW CUSTOMER: " << customer.name_ << " ADDED!!!\n\n";
  }
  receipts[receipts.size() - 1].print(std::cout);
}

namespace Handle {
Records::Receipt Receipt(
    const std::unordered_map<std::string, float> CartItems, const float &Subtotal) {
  std::time_t now = time(0);
  tm* ltm = localtime(&now);

  // initializing date
  std::string year = std::to_string(1900 + ltm->tm_year).substr(2, 4);
  std::string month = std::to_string(1 + ltm->tm_mon);
  std::string day = std::to_string(ltm->tm_mday);

  // Formating date
  if (month.size() == 1) month.insert(month.begin(), '0');
  if (day.size() == 1) day.insert(day.begin(), '0');

  // Formating Time
  std::string hour = std::to_string(ltm->tm_hour);
  std::string meta = "AM";
  if (std::stoi(hour) > 12) meta = "PM";

  // Last four format
  std::string strLastFour;
  char temp;
  std::srand(std::time(nullptr));
  for (int i = 0; i < 4; i++) {
    temp = char(rand() % 9 + 48);
    strLastFour.push_back(temp);
  }

  std::vector<std::pair<std::string, float>> items;

  for (const auto &CartItem : CartItems) {
    items.push_back(std::make_pair(CartItem.first, CartItem.second));
  }

  const u_int16_t LastFour = u_int16_t(std::stoi(strLastFour));
  Records::Issuers Issuer = Records::Issuers(rand() % 4);
  const float Tax = Subtotal * TAX_MULTIPLIER;
  const float Total = Subtotal + Tax;
  const std::string Date = month + '/' + day + '/' + year;
  const std::string Time = hour + ':' + std::to_string(ltm->tm_min) + meta;
  const char* Footer = "PLEASE COME AGAIN!!";

  Records::Receipt receipt(
      std::ostringstream(), Footer, Time, Date, LastFour, Issuer, items, Subtotal, Tax,
      Total);

  receipt.getHeader() << "   Carlos Sales System\n4231 NOWHERE BLVD WHERE, NO\n"
                      << "---------------------------\n";

  return receipt;
}

void Discount(float &Subtotal) {
  system("clear");
  float discount;
  std::cout << "           DISCOUNT\n"
            << "-----------------------------\n";
  std::cout << "Enter Discount Amount: ";
  std::cin >> discount;
  Buffer::clean(std::cin);

  if (discount > Subtotal) {
    Utility::Log("INVALID DISCOUNT AMOUNT!!!\n");
    return;
  }

  Subtotal -= discount;
}

float Subtotal(const std::unordered_map<std::string, float> &CartItems) {
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
  Utility::Log("YOU GOT A NEW CUSTOMER!!!\n");
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
  std::srand(std::time(nullptr));
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
