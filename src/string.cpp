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
