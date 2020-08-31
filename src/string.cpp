#include <csugar.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstdlib>
#include <iomanip>

using namespace std;

string csugar::lowercase(string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    return str;
}

string csugar::uppercase(string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
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

    for (char c: str) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << nouppercase;
    }

    return escaped.str();
}