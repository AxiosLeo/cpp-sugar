#ifndef CPP_SUGAR_CSUGAR_H
#define CPP_SUGAR_CSUGAR_H

#include <iostream>
#include <json/json.h>
#include <iterator>
#include <vector>

namespace csugar {
    /************************** string **************************/
    std::string lowercase(std::string str);

    std::string uppercase(std::string str);

    std::string lower_first_case(std::string str);

    std::string upper_first_case(std::string str);

    std::string url_encode(const std::string &str);

    std::string url_decode(const std::string &str);

    std::string uuid();

    std::vector<std::string> explode(const std::string &str, const std::string &delimiter = "");

    std::string implode(const std::vector<std::string> &vec, const std::string &glue = "");

    /************************** json **************************/
    Json::Value json_decode(const std::string &str);

    std::string json_encode(const Json::Value &root);

    /************************** datetime **************************/
    std::string utc_datetime(time_t time = NULL); // 2020-08-08T08:08:08Z

    time_t strtotime(const std::string &gmt_datetime);

    /************************** crypt **************************/
    std::string hmacsha1(std::string content, std::string key);

    std::string hmacsha256(std::string content, std::string key);
}

#endif //CPP_SUGAR_CSUGAR_H
