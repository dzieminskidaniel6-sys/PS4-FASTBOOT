#include "fastboot_protocol.h"

#include <cstdint>
#include <string>
#include <vector>

namespace {
bool check(bool condition, const char* message) {
  if (!condition) {
    // Keep tests effective even when the build defines NDEBUG.
    (void)message;
    return false;
  }
  return true;
}
}

int main() {
  using namespace ps4fb;

  const auto command = make_command("getvar:product");
  if (!check(std::string(command.begin(), command.end()) == "getvar:product",
             "valid command")) return 1;
  if (!check(make_command("").empty(), "reject empty command")) return 1;
  if (!check(make_command(std::string(65, 'x')).empty(),
             "reject command over 64 bytes")) return 1;
  if (!check(make_command("getvar:product\n").empty(),
             "reject newline")) return 1;
  if (!check(make_command(std::string("getvar:x\0y", 10)).empty(),
             "reject embedded NUL")) return 1;

  const uint8_t okay[] = {'O','K','A','Y','o','k'};
  auto response = parse_response(okay, sizeof(okay));
  if (!check(response.kind == Response::Kind::Okay, "parse OKAY")) return 1;
  if (!check(response.payload == "ok", "OKAY payload")) return 1;

  const uint8_t info[] = {'I','N','F','O','v','e','r','b','o','s','e'};
  response = parse_response(info, sizeof(info));
  if (!check(response.kind == Response::Kind::Info, "parse INFO")) return 1;
  if (!check(response.payload == "verbose", "INFO payload")) return 1;

  const uint8_t fail[] = {'F','A','I','L','b','a','d'};
  response = parse_response(fail, sizeof(fail));
  if (!check(response.kind == Response::Kind::Fail, "parse FAIL")) return 1;
  if (!check(response.payload == "bad", "FAIL payload")) return 1;

  const uint8_t data[] = {'D','A','T','A','0','0','1','0'};
  response = parse_response(data, sizeof(data));
  if (!check(response.kind == Response::Kind::Data, "parse DATA")) return 1;
  if (!check(response.payload == "0010", "DATA payload")) return 1;

  const uint8_t unknown[] = {'N','O','P','E'};
  response = parse_response(unknown, sizeof(unknown));
  if (!check(response.kind == Response::Kind::Unknown, "unknown prefix")) return 1;
  if (!check(parse_response(nullptr, 4).kind == Response::Kind::Unknown,
             "null input")) return 1;
  if (!check(parse_response(okay, 3).kind == Response::Kind::Unknown,
             "short input")) return 1;

  return 0;
}
