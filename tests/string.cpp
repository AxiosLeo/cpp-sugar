#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;
using namespace std;

TEST(tests_string, test_lowercase) { ASSERT_EQ("test", lowercase("TEST")); }

TEST(tests_string, test_uppercase) { ASSERT_EQ("TEST", uppercase("test")); }

TEST(tests_string, test_url_encode) {
  ASSERT_EQ("a%26%2F%21%20%24%23%28%2A.%2B0%29", url_encode("a&/! $#(*.+0)"));
}

TEST(tests_string, test_url_decode) {
  ASSERT_EQ("a&/! $#(*.+0)", url_decode("a%26%2F%21%20%24%23%28%2A.%2B0%29"));
}

TEST(tests_string, test_explode_implode) {
  string str = string("a.b.c.");
  string delimiter = string(".");
  vector<string> vec = explode(str, delimiter);
  vector<string> vec_expected;
  vec_expected.emplace_back("a");
  vec_expected.emplace_back("b");
  vec_expected.emplace_back("c");
  vec_expected.emplace_back("");
  ASSERT_EQ(vec_expected, vec);

  ASSERT_EQ("a.b.c.", implode(vec, "."));
}

TEST(tests_string, build_http_query) {
  map<string, string> query = {
      {"foo", "bar"}, {"em", ""}, {"link", "http://example.com?foo=bar"}};

  ASSERT_EQ(string("em=&foo=bar&link=http%3A%2F%2Fexample.com%3Ffoo%3Dbar"),
            build_http_query(query));
}

TEST(tests_string, bytes_to_string) {
  string src = "test";
  uint8_t *bytes = string_to_bytes(string("test"));
  string res = bytes_to_string(bytes);
  ASSERT_EQ(src, res);
}