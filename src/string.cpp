#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstdlib>
#include <csugar.h>
#include <iomanip>

using namespace std;

string csugar::lowercase(string str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return str;
}

string csugar::uppercase(string str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return str;
}

string csugar::uuid() {
  boost::uuids::uuid uid = boost::uuids::random_generator()();
  return boost::uuids::to_string(uid);
}

string csugar::url_encode(const std::string &str) {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << hex;

  for (char c : str) {
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
      escaped << c;
      continue;
    }
    escaped << std::uppercase;
    escaped << '%' << std::setw(2) << int((unsigned char)c);
    escaped << nouppercase;
  }

  return escaped.str();
}

char from_hex(char ch) {
  return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

string csugar::url_decode(const std::string &str) {
  char h;
  ostringstream escaped;
  escaped.fill('0');

  for (auto i = str.begin(), n = str.end(); i != n; ++i) {
    string::value_type c = (*i);

    if (c == '%') {
      if (i[1] && i[2]) {
        h = from_hex(i[1]) << 4 | from_hex(i[2]);
        escaped << h;
        i += 2;
      }
    } else if (c == '+') {
      escaped << ' ';
    } else {
      escaped << c;
    }
  }

  return escaped.str();
}

std::vector<std::string> csugar::explode(const std::string &str,
                                         const std::string &delimiter) {
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

std::string csugar::implode(const std::vector<std::string> &vec,
                            const std::string &glue) {
  string res;
  int n = 0;
  for (const auto &str : vec) {
    if (n == 0) {
      res = str;
    } else {
      res += glue + str;
    }
    n++;
  }
  return res;
}

std::string
csugar::build_http_query(const std::map<std::string, std::string> &query) {
  vector<string> v;
  for (const auto &it : query) {
    string i(it.first + "=" + url_encode(it.second));
    v.push_back(i);
  }
  return implode(v, "&");
}