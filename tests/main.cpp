#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;
using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(tests_string, test_lowercase) {
    ASSERT_EQ("test", lowercase("TEST"));
}

TEST(tests_string, test_uppercase) {
    ASSERT_EQ("TEST", uppercase("test"));
}

TEST(tests_string, test_url_encode) {
    ASSERT_EQ("a%26%2F%21%20%24%23%28%2A.%2B0%29", url_encode("a&/! $#(*.+0)"));
}

TEST(tests_string, test_url_decode) {
    ASSERT_EQ("a&/! $#(*.+0)", url_decode("a%26%2F%21%20%24%23%28%2A.%2B0%29"));
}

std::vector<std::string> explode2(const std::string &str, const std::string &delimiter = "") {
    int pos = str.find(delimiter, 0);
    int pos_start = 0;
    int split_n = pos;
    string line_text(delimiter);

    std::vector<std::string> dest;

    while (pos > -1) {
        line_text = str.substr(pos_start, split_n);
        pos_start = pos + 1;
        pos = str.find(delimiter, pos + 1);
        split_n = pos - pos_start;
        dest.push_back(line_text);
    }
    line_text = str.substr(pos_start, str.length() - pos_start);
    dest.push_back(line_text);
    return dest;
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

TEST(tests_json, test_json_decode) {
    std::string json = R"({"foo":"bar"})";
    Json::Value rest = json_decode(json);
    ASSERT_EQ("bar", rest["foo"].asString());
}
