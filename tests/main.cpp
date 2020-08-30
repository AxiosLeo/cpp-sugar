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

TEST(tests_json, test_json_decode) {
    std::string json = R"({"foo":"bar"})";
    Json::Value rest = json_decode(json);
    ASSERT_EQ("bar", rest["foo"].asString());
}
