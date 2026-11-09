#include "fastboot_protocol.h"
#include <algorithm>

namespace ps4fb {
std::vector<uint8_t> make_command(const std::string& command) {
  // Fastboot command tokens are limited to 64 bytes.
  if (command.empty() || command.size() > 64) return {};
  if (command.find_first_of("\r\n") != std::string::npos) return {};
  return {command.begin(), command.end()};
}

Response parse_response(const uint8_t* data, size_t size) {
  if (!data || size < 4) return {};
  Response r;
  const std::string prefix(reinterpret_cast<const char*>(data), 4);
  r.payload.assign(reinterpret_cast<const char*>(data + 4), size - 4);
  if (prefix == "INFO") r.kind = Response::Kind::Info;
  else if (prefix == "OKAY") r.kind = Response::Kind::Okay;
  else if (prefix == "FAIL") r.kind = Response::Kind::Fail;
  else if (prefix == "DATA") r.kind = Response::Kind::Data;
  return r;
}
} // namespace ps4fb
