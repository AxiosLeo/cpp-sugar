#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;

TEST(tests_datetime, test_utc_datetime) {
  std::string now = utc_datetime();
  printf("%s", now.c_str());
  std::string gmt_datetime = "2020-08-08T08:08:08Z";
  time_t t = utc_strtotime(gmt_datetime);
  ASSERT_EQ(1596874088, t);
  std::string res = utc_datetime(t);
  ASSERT_EQ(gmt_datetime, res);
}

TEST(tests_datetime, test_timestamp) {
  ASSERT_TRUE(timestamp() > 1599362561);
}

TEST(tests_datetime, test_datetime) {
  ASSERT_EQ(std::string("2020-08-08 08:08:08"), datetime(1596874088));
}