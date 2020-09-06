#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(tests_json, test_json) {
  std::string json = R"({"foo":"bar"})";
  Json::Value rest = json_decode(json);
  ASSERT_EQ("bar", rest["foo"].asString());
  ASSERT_EQ(json, json_encode(rest));
}
