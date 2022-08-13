#ifndef RECEIPT_H_
#define RECEIPT_H_
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../utility/Buffer.h"

namespace Records {
enum struct Issuers { kVisa = 0, kDiscovery, kMastercard, kAmericanExpress };
const std::unordered_map<std::string, Issuers> StringToIssuer = {
    {"Visa", Issuers::kVisa},
    {"DSC", Issuers::kDiscovery},
    {"MCard", Issuers::kMastercard},
    {"AMEX", Issuers::kAmericanExpress}};

const std::unordered_map<Issuers, std::string> IssuerToString = {
    {Issuers::kVisa, "Visa"},
    {Issuers::kDiscovery, "DSC"},
    {Issuers::kMastercard, "MCard"},
    {Issuers::kAmericanExpress, "AMEX"}};

// This is done to show compiler that there is a class Receipt that exists
class Receipt;

namespace Read {
const uint8_t HEADER_LINE_AMOUNT = 3;
// Where to stop reading items
const std::string ITEMS_DELIMITER = "PAYMENT";

/**
 * @brief Reads header
 *
 * @param fin
 * @param receipt
 */
void Header(std::fstream &fin, Receipt &receipt);

/**
 * @brief Reads Items
 *
 * @param fin
 * @param receipt
 */
void Items(std::fstream &fin, Receipt &receipt);

/**
 * @brief Reads Time
 *
 * @param fin
 * @param receipt
 */
void Time(std::fstream &fin, Receipt &receipt);

/**
 * @brief Reads Payment Type
 *
 * @param fin
 * @param receipt
 */
void Payment(std::fstream &fin, Receipt &receipt);

/**
 * @brief Reads all totals
 *
 * @param fin
 * @param receipt
 */
void Totals(std::fstream &fin, Receipt &receipt);
}  // namespace Read

class Receipt {
 private:
  // Documentation in Read namespace
  friend void Read::Header(std::fstream &fin, Receipt &receipt);
  friend void Read::Items(std::fstream &fin, Receipt &receipt);
  friend void Read::Time(std::fstream &fin, Receipt &receipt);
  friend void Read::Payment(std::fstream &fin, Receipt &receipt);
  friend void Read::Totals(std::fstream &fin, Receipt &receipt);

 public:
  /**
   * @brief Construct a new Receipt object
   *
   */
  Receipt();

  /**
   * @brief Construct a new Receipt object
   *
   * @param header
   * @param footer
   * @param timeCreated
   * @param dateCreated
   * @param lastFour
   * @param issuer
   * @param items
   * @param subtotal
   * @param tax
   * @param total
   */
  Receipt(
      std::ostringstream header, std::string footer, std::string timeCreated,
      std::string dateCreated, u_int16_t lastFour, Issuers issuer,
      std::vector<std::pair<std::string, float>> items, float subtotal, float tax,
      float total);

  /**
   * @brief Delegates work to entire Read namespace
   *
   * @param fin
   */
  void read(std::fstream &fin);

  /**
   * @brief Prints this->Receipts
   *
   * @param os
   */
  void print(std::ostream &os) const;

  /**
   * @brief Get the Header object
   *
   * @return std::ostringstream&
   */
  std::ostringstream &getHeader();

 private:
  std::ostringstream header_;
  std::string footer_;
  std::string timeCreated_;
  std::string dateCreated_;
  u_int16_t lastFour_;
  Issuers issuer_;
  std::vector<std::pair<std::string, float>> items_;
  float subtotal_;
  float tax_;
  float total_;
};

}  // namespace Records
#endif  // RECEIPT_H_