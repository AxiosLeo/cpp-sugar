#include "gtest/gtest.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <csugar.h>
#include <map>
#include <vector>

using namespace csugar;

TEST(tests_json, test_json_decode_to_any) {
  std::string json =
      R"({"bool":true,"foo":"bar","long":9223372036854775807,"map":{"foo":"bar"},"string":"string","vector":["foo","bar"]})";
  std::map<std::string, boost::any> m = {
      {"foo", boost::any("bar")},
      {"string", boost::any(std::string("string"))},
      {"long", boost::any(LONG_MAX)},
      {"bool", boost::any(true)},
      {"vector", boost::any(std::vector<boost::any>({{boost::any("foo")}}))},
      {"map", boost::any(std::map<std::string, boost::any>(
                  {{"foo", boost::any("bar")}}))}};
  std::stringstream ss(json);
  boost::property_tree::ptree pt;
  read_json(ss, pt);
  boost::any target = csugar::json_decode(pt);
  std::map<std::string, boost::any> data =
      boost::any_cast<std::map<std::string, boost::any>>(target);
  std::vector<boost::any> vec =
      boost::any_cast<std::vector<boost::any>>(data["vector"]);

  ASSERT_EQ(std::string("foo"), boost::any_cast<std::string>(vec[0]));
  ASSERT_EQ(std::string("bar"), boost::any_cast<std::string>(vec[1]));
  ASSERT_EQ(true, boost::any_cast<bool>(data["bool"]));
}
