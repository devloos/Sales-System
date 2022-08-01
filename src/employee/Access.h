#ifndef SIGNIN_H_
#define SIGNIN_H_
#include <cstdint>
#include <string>
#include <unordered_map>

bool verifyAccess(const std::string &workID, const uint32_t &social);

class Access {
 public:
  Access() {}
  void initAccessCodes(const std::string &filename);
  bool verified(const std::string &workID, const uint32_t &social);

 private:
  std::unordered_map<std::string, uint32_t> accessCodes_;
};

#endif  // SIGNIN_H_