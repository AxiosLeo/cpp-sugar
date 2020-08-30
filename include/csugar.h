#ifndef CPP_SUGAR_CSUGAR_H
#define CPP_SUGAR_CSUGAR_H

#include <iostream>
#include <json/json.h>

namespace csugar {
    /************************** string **************************/
    std::string lowercase(std::string str);

    std::string uppercase(std::string str);

    std::string lower_first_case(std::string str);

    std::string upper_first_case(std::string str);

    std::string url_encode(std::string str);

    std::string url_decode(std::string str);

    template<typename T>
    std::string build_http_query(std::map<std::string, T> query);

    std::string uuid();

    /************************** json **************************/
    Json::Value json_decode(const std::string &str);

    std::string json_encode(const Json::Value &root);

    template<typename T>
    std::string json_encode_list(std::vector<T> data);

    /************************** datetime **************************/
    std::string gmt_datetime(time_t time = NULL); // 2020-08-08T08:08:08Z

    /************************** crypt **************************/
    std::string hmacsha1(std::string content, std::string key);

    std::string hmacsha256(std::string content, std::string key);
}

#endif //CPP_SUGAR_CSUGAR_H
