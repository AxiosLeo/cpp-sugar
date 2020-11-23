#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;

TEST(tests_crypt, base64) {
  std::string str = "test string";
  ASSERT_EQ(std::string("dGVzdCBzdHJpbmc="), base64_encode(str));
  ASSERT_EQ(std::string("test string"), base64_decode("dGVzdCBzdHJpbmc="));
}

TEST(tests_crypt, hmacsha1) {
  std::string str = "test string";
  std::string sec = "secret";
  ASSERT_EQ(std::string("3Sa/3fEiwQVdTNWwVCJ3J+Hj7s8="), hmacsha1(str, sec));
}

TEST(tests_crypt, hmacsha256) {
  std::string str = "test string";
  std::string sec = "secret";
  ASSERT_EQ(std::string("4BQwe0aaQ947Iz5dFr9jv5l/oS4Cal2ZC5RBwlinuLY="),
            hmacsha256(str, sec));
}
