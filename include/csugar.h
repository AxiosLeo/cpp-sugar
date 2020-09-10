#ifndef CPP_SUGAR_CSUGAR_H
#define CPP_SUGAR_CSUGAR_H

#include <iostream>
#include <json/json.h>
#include <iterator>
#include <vector>
#include <boost/any.hpp>

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

std::string build_http_query(const std::map<std::string, std::string> &query);

std::string bytes_to_string(uint8_t *bytes);

uint8_t *string_to_bytes(std::string str);

/************************** json **************************/
Json::Value json_decode(const std::string &str);

std::string json_encode(const Json::Value &root);

std::string json_encode(const boost::any &val);

/************************** datetime **************************/
std::string utc_datetime(const time_t &time = 0); // 2020-08-08T08:08:08Z

time_t utc_strtotime(const std::string &utc_datetime);

long timestamp();

std::string datetime(const std::string &format, long timestamp = 0);

/************************** crypt **************************/
std::string hmacsha1(const std::string &content, const std::string &key);

std::string hmacsha256(std::string content, std::string key);
}

#endif //CPP_SUGAR_CSUGAR_H
