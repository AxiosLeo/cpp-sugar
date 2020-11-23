#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <csugar.h>
#include <ctime>

std::string csugar::utc_datetime(const time_t &time) {
  char buf[80];
  std::strftime(buf, sizeof buf, "%Y-%m-%dT%H:%M:%SZ", gmtime(&time));
  return buf;
}

time_t csugar::utc_strtotime(const std::string &utc_datetime) {
  struct tm tm {};
  strptime(utc_datetime.c_str(), "%Y-%m-%dT%H:%M:%SZ", &tm);
  time_t t = timegm(&tm);
  return boost::lexical_cast<long long>(t);
}

long csugar::timestamp() {
  return static_cast<long int>(time(nullptr));
}

std::string csugar::datetime(const std::string &format, long timestamp) {
  time_t t = timestamp;
  ctime(&t);
  char buf[80];
  std::strftime(buf, sizeof buf, format.c_str(), gmtime(&t));
  return buf;
}