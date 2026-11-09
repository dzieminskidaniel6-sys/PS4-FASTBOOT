#include "fastboot_protocol.h"

namespace ps4fb {
std::vector<uint8_t> make_command(const std::string& command) {
  // Android Fastboot command payloads are limited to 64 bytes.
  if (command.empty() || command.size() > 64) return {};
  // Commands are byte strings; reject line breaks and embedded NULs so callers
  // cannot accidentally truncate or inject framing at a lower layer.
  if (command.find_first_of("\r\n\0", 0, 3) != std::string::npos) return {};
  return {command.begin(), command.end()};
}

Response parse_response(const uint8_t* data, size_t size) {
  if (!data || size < 4) return {};

  Response response;
  const std::string prefix(reinterpret_cast<const char*>(data), 4);
  response.payload.assign(reinterpret_cast<const char*>(data + 4), size - 4);

  if (prefix == "INFO") response.kind = Response::Kind::Info;
  else if (prefix == "OKAY") response.kind = Response::Kind::Okay;
  else if (prefix == "FAIL") response.kind = Response::Kind::Fail;
  else if (prefix == "DATA") response.kind = Response::Kind::Data;
  else response.kind = Response::Kind::Unknown;

  return response;
}
} // namespace ps4fb
