#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace ps4fb {
struct Response {
  enum class Kind { Info, Okay, Fail, Data, Unknown };
  Kind kind{Kind::Unknown};
  std::string payload;
};

std::vector<uint8_t> make_command(const std::string& command);
Response parse_response(const uint8_t* data, size_t size);
} // namespace ps4fb
