#include "fastboot_protocol.h"
#include <cassert>
#include <string>

int main() {
  using namespace ps4fb;
  auto cmd = make_command("getvar:product");
  assert(std::string(cmd.begin(), cmd.end()) == "getvar:product");
  assert(make_command("").empty());
  assert(make_command(std::string(65, 'x')).empty());

  const uint8_t okay[] = {'O','K','A','Y','o','k'};
  auto r = parse_response(okay, sizeof(okay));
  assert(r.kind == Response::Kind::Okay);
  assert(r.payload == "ok");

  const uint8_t fail[] = {'F','A','I','L','b','a','d'};
  r = parse_response(fail, sizeof(fail));
  assert(r.kind == Response::Kind::Fail);
  assert(r.payload == "bad");
  return 0;
}
