#include <iostream>
#include <json/json.h>

using namespace std;

Json::Value json_decode(const string &str) {
    const auto len = static_cast<int>(str.length());
    JSONCPP_STRING err;
    Json::Value root;

    Json::CharReaderBuilder builder;
    const unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(str.c_str(), str.c_str() + len, &root, &err)) {
        string error_info = "json_decode error : " + err;
        throw error_info.c_str();
    }
    return root;
}