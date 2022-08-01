#ifndef SIGNIN_H_
#define SIGNIN_H_
#include <cstdint>
#include <string>
#include <unordered_map>

class Access {
 public:
  Access() {}
  void initAccessCodes(const std::string &filename);
  bool accessVerified(const std::string &workID, const uint16_t &social);

 private:
  std::unordered_map<std::string, uint16_t> accessCodes_;
};

#endif  // SIGNIN_H_