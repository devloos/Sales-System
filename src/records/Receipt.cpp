#include "Receipt.h"

namespace Records {
Receipt::Receipt() {}

Receipt::Receipt(
    std::ostringstream header, std::string footer, std::string timeCreated,
    std::string dateCreated, u_int16_t lastFour, Issuers issuer,
    std::vector<std::pair<std::string, float>> items, float subtotal, float tax,
    float total)
    : footer_(footer),
      timeCreated_(timeCreated),
      dateCreated_(dateCreated),
      lastFour_(lastFour),
      issuer_(issuer),
      items_(items),
      subtotal_(subtotal),
      tax_(tax),
      total_(total) {}

void Receipt::read(std::fstream &fin) {
  Read::Header(fin, *this);
  Read::Time(fin, *this);
  Read::Items(fin, *this);
  Read::Payment(fin, *this);
  Read::Totals(fin, *this);
}

std::ostringstream &Receipt::getHeader() { return header_; }

void Receipt::print(std::ostream &os) const {
  os << header_.str();
  os << std::left;
  os << std::setw(19) << dateCreated_ << timeCreated_ << "\n";
  os << "---------------------------\n";
  for (const auto &item : items_) {
    os << item.first << " - " << item.second << '\n';
  }
  os << '\n';
  os << std::setw(12) << "PAYMENT" << std::setw(5) << "-" << IssuerToString.at(issuer_)
     << " " << lastFour_ << '\n';
  os << "---------------------------\n";

  os << std::setw(16) << "SUBTOTAL:" << std::fixed << std::setprecision(2) << "$ "
     << subtotal_ << '\n'
     << std::setw(16) << "TAX:"
     << "$ " << tax_ << '\n'
     << std::setw(16) << "TOTAL:"
     << "$ " << total_ << "\n\n";
  os << std::right;
  os << std::setw(22) << footer_;
}

namespace Read {
void Header(std::fstream &fin, Receipt &receipt) {
  std::string line;
  receipt.header_ << "\n";
  for (int i = 0; i < HEADER_LINE_AMOUNT; i++) {
    std::getline(fin, line);
    receipt.header_ << line << '\n';
  }
  return;
}

void Items(std::fstream &fin, Receipt &receipt) {
  std::string itemName, discard;
  float price = 0.0f;
  bool itemsRead = false;

  do {
    fin >> itemName;
    if (itemName == ITEMS_DELIMITER) return;
    fin >> discard >> price;
    Buffer::clean(fin);

    receipt.items_.push_back(std::pair<std::string, float>(itemName, price));
  } while (!itemsRead);
  return;
}

void Time(std::fstream &fin, Receipt &receipt) {
  std::string discard;
  fin >> receipt.dateCreated_ >> receipt.timeCreated_;
  Buffer::clean(fin);
  std::getline(fin, discard);
  return;
}

void Payment(std::fstream &fin, Receipt &receipt) {
  std::string discard;
  std::string strIssuer;

  fin >> discard >> strIssuer;
  receipt.issuer_ = StringToIssuer.at(strIssuer);
  fin >> receipt.lastFour_;

  Buffer::clean(fin);
  std::getline(fin, discard);
}

void Totals(std::fstream &fin, Receipt &receipt) {
  std::string discard;

  auto Helper = [&](float &value) {
    fin >> discard >> discard >> value;
    Buffer::clean(fin);
  };

  Helper(receipt.subtotal_);
  Helper(receipt.tax_);
  Helper(receipt.total_);

  std::getline(fin, discard);
  std::getline(fin, receipt.footer_);
}

}  // namespace Read
}  // namespace Records