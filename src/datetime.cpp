#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <csugar.h>
#include <ctime>

std::string csugar::utc_datetime(const time_t &time) {
  char buf[80];
  std::strftime(buf, sizeof buf, "%FT%TZ", gmtime(&time));
  return buf;
}

time_t csugar::utc_strtotime(const std::string &utc_datetime) {
  std::string datetime = utc_datetime.substr(0, utc_datetime.size() - 1);
  boost::posix_time::ptime pt(
      boost::posix_time::from_iso_extended_string(datetime));
  const boost::posix_time::ptime epoch = boost::posix_time::from_time_t(0);
  boost::posix_time::time_duration duration = pt - epoch;
  time_t t = duration.total_seconds();
  return t;
}

long csugar::timestamp() {
  boost::posix_time::ptime pt;
  boost::posix_time::time_duration du = boost::posix_time::second_clock::universal_time() - pt;
  return du.total_seconds();
}

std::string csugar::datetime(long timestamp, std::string format) {
  time_t t = timestamp;
  ctime(&t);
  char buf[80];
  std::strftime(buf, sizeof buf, format.c_str(), gmtime(&t));
  return buf;
}