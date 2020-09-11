#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;

TEST(tests_crypt, base64_encode) {
  std::string str = "test string";
  ASSERT_EQ(std::string("dGVzdCBzdHJpbmc="), base64_encode(str));
}
