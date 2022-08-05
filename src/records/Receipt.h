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

#include "../exceptions/Buffer.h"

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

class Receipt;
namespace Read {
const uint8_t HEADER_LINE_AMOUNT = 3;
const std::string ITEMS_DELIMITER = "PAYMENT";

/**
 * @brief
 *
 * @param inFile
 * @param receipt
 */
void Header(std::fstream &inFile, Receipt &receipt);

/**
 * @brief
 *
 * @param inFile
 * @param receipt
 */
void Items(std::fstream &inFile, Receipt &receipt);

/**
 * @brief
 *
 * @param inFile
 * @param receipt
 */
void Time(std::fstream &inFile, Receipt &receipt);

/**
 * @brief
 *
 * @param inFile
 * @param receipt
 */
void Payment(std::fstream &inFile, Receipt &receipt);

/**
 * @brief
 *
 * @param inFile
 * @param receipt
 */
void Totals(std::fstream &inFile, Receipt &receipt);
}  // namespace Read

class Receipt {
 private:
  // Documentation in Read namespace
  friend void Read::Header(std::fstream &infile, Receipt &receipt);
  friend void Read::Items(std::fstream &inFile, Receipt &receipt);
  friend void Read::Time(std::fstream &inFile, Receipt &receipt);
  friend void Read::Payment(std::fstream &inFile, Receipt &receipt);
  friend void Read::Totals(std::fstream &inFile, Receipt &receipt);

 public:
  /**
   * @brief Construct a new Receipt object
   *
   */
  Receipt();

  /**
   * @brief
   *
   * @param infile
   */
  void read(std::fstream &infile);

  /**
   * @brief
   *
   * @param os
   */
  void print(std::ostream &os) const;

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