#include "cpr/multipart.h"

namespace cpr {

Multipart::Multipart(const std::initializer_list<Part>& the_parts) : parts{the_parts} {}

} // namespace cpr
