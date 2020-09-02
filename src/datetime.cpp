#include <boost/date_time/posix_time/posix_time.hpp>
#include <csugar.h>
#include <ctime>

std::string csugar::utc_datetime(time_t time) {
  char buf[80];
  std::strftime(buf, sizeof buf, "%FT%TZ", gmtime(&time));
  return buf;
}

time_t csugar::strtotime(const std::string &gmt_datetime) {
  std::string datetime = gmt_datetime.substr(0, gmt_datetime.size() - 1);
  boost::posix_time::ptime pt(
      boost::posix_time::from_iso_extended_string(datetime));
  const boost::posix_time::ptime epoch = boost::posix_time::from_time_t(0);
  boost::posix_time::time_duration duration = pt - epoch;
  time_t t = duration.total_seconds();
  return t;
}