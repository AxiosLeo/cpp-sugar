#include <csugar.h>
#include <iostream>
#include <json/json.h>
#include <memory>

using namespace std;

Json::Value csugar::json_decode(const string &str) {
  const auto len = static_cast<int>(str.length());
  JSONCPP_STRING err;
  Json::Value root;

  Json::CharReaderBuilder builder;
  const unique_ptr<Json::CharReader> reader(builder.newCharReader());
  if (!reader->parse(str.c_str(), str.c_str() + len, &root, &err)) {
    string error_info = "json_decode error : " + err;
    throw error_info;
  }
  return root;
}

boost::any csugar::json_decode(boost::property_tree::ptree pt) {
  if (pt.empty()) {
    if (pt.data() == "true") {
      return boost::any(true);
    } else if (pt.data() == "false") {
      return boost::any(false);
    }
    return boost::any(pt.data());
  }
  vector<boost::any> vec;
  map<string, boost::any> m;
  for (const auto &it : pt) {
    if (!it.first.empty()) {
      m[it.first] = json_decode(it.second);
    } else {
      vec.push_back(json_decode(it.second));
    }
  }
  return vec.empty() ? boost::any(m) : boost::any(vec);
}

string csugar::json_encode(const Json::Value &root) {
  Json::StreamWriterBuilder w;
  w["commentStyle"] = "None";
  w["indentation"] = "";
  std::string document = Json::writeString(w, root);
  return document;
}
