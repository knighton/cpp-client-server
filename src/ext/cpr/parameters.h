#ifndef CPR_PARAMETERS_H
#define CPR_PARAMETERS_H

#include <initializer_list>
#include <memory>
#include <string>

#include "cpr/defines.h"

namespace cpr {

struct Parameter {
    template <typename KeyType, typename ValueType>
    Parameter(KeyType&& the_key, ValueType&& the_value)
            : key{CPR_FWD(the_key)}, value{CPR_FWD(the_value)} {}

    std::string key;
    std::string value;
};

class Parameters {
  public:
    Parameters() = default;
    Parameters(const std::initializer_list<Parameter>& parameters);

    void AddParameter(const Parameter& parameter);

    std::string content;
};

} // namespace cpr

#endif
