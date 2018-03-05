#ifndef CPR_LOW_SPEED_H
#define CPR_LOW_SPEED_H

#include <cstdint>

namespace cpr {

class LowSpeed {
  public:
    LowSpeed(const std::int32_t the_limit, const std::int32_t the_time) : limit(the_limit), time(the_time) {}

    std::int32_t limit;
    std::int32_t time;
};

} // namespace cpr

#endif
