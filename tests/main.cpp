#include "gtest/gtest.h"
#include <csugar.h>

using namespace csugar;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(string, lowercase) {
    ASSERT_EQ("test", lowercase("TEST"));
}

TEST(string, uppercase) {
    ASSERT_EQ("TEST", lowercase("test"));
}

TEST(json, json_decode) {
    std::string json = R"({"foo":"bar"})";
    Json::Value rest = json_decode(json);
    ASSERT_EQ("bar", rest["foo"].asCString());
}
