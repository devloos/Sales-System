#include "Receipt.h"

namespace Records {
Receipt::Receipt() {}

void Receipt::read(std::fstream &inFile) {
  Read::Header(inFile, *this);
  Read::Time(inFile, *this);
  Read::Items(inFile, *this);
  Read::Payment(inFile, *this);
  Read::Totals(inFile, *this);
}

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

  os << std::setw(16) << "SUBTOTAL:"
     << "$ " << subtotal_ << '\n'
     << std::setw(16) << "TAX:"
     << "$ " << tax_ << '\n'
     << std::setw(16) << "TOTAL:"
     << "$ " << total_ << "\n\n";
  os << std::right;
  os << std::setw(22) << footer_;
}

namespace Read {
void Header(std::fstream &inFile, Receipt &receipt) {
  std::string line;
  receipt.header_ << "\n";
  for (int i = 0; i < HEADER_LINE_AMOUNT; i++) {
    std::getline(inFile, line);
    receipt.header_ << line << '\n';
  }
  return;
}

void Items(std::fstream &inFile, Receipt &receipt) {
  std::string itemName, discard;
  float price = 0.0f;
  bool itemsRead = false;

  do {
    inFile >> itemName;
    if (itemName == ITEMS_DELIMITER) return;
    inFile >> discard >> price;
    Buffer::clean(inFile);

    receipt.items_.push_back(std::pair<std::string, float>(itemName, price));
  } while (!itemsRead);
  return;
}

void Time(std::fstream &inFile, Receipt &receipt) {
  std::string discard;
  inFile >> receipt.dateCreated_ >> receipt.timeCreated_;
  Buffer::clean(inFile);
  std::getline(inFile, discard);
  return;
}

void Payment(std::fstream &inFile, Receipt &receipt) {
  std::string discard;
  std::string strIssuer;

  inFile >> discard >> strIssuer;
  receipt.issuer_ = StringToIssuer.at(strIssuer);
  inFile >> receipt.lastFour_;

  Buffer::clean(inFile);
  std::getline(inFile, discard);
}

void Totals(std::fstream &inFile, Receipt &receipt) {
  std::string discard;

  auto Helper = [&](float &value) {
    inFile >> discard >> discard >> value;
    Buffer::clean(inFile);
  };

  Helper(receipt.subtotal_);
  Helper(receipt.tax_);
  Helper(receipt.total_);

  std::getline(inFile, discard);
  std::getline(inFile, receipt.footer_);
}

}  // namespace Read
}  // namespace Records