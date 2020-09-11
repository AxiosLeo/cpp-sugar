#include "crypt/base64.h"
#include "crypt/hmac.h"
#include "crypt/sha1.h"
#include "crypt/sha256.h"
#include <csugar.h>

std::string csugar::hmacsha1(const std::string &content,
                             const std::string &key) {
  boost::uint8_t hash_val[sha1::HASH_SIZE];
  hmac<sha1>::calc(content, key, hash_val);
  return bytes_to_string(hash_val);
}

std::string csugar::hmacsha256(const std::string &content,
                               const std::string &key) {
  boost::uint8_t hash_val[sha256::HASH_SIZE];
  hmac<sha1>::calc(content, key, hash_val);
  return bytes_to_string(hash_val);
}

std::string csugar::base64_encode(const std::string &content) {
  return base64::encode_from_string(content);
}

std::string csugar::base64_decode(const std::string &content) {
  std::string decoded_str;
  base64::decode(content, decoded_str);
  return decoded_str;
}