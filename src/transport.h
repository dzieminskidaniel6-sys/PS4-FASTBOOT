#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace ps4fb {
struct UsbDeviceInfo {
  uint16_t vendor_id{};
  uint16_t product_id{};
  std::string manufacturer;
  std::string product;
  std::string serial;
};

class ITransport {
public:
  virtual ~ITransport() = default;
  virtual bool is_available() const = 0;
  virtual bool open(const UsbDeviceInfo& device) = 0;
  virtual bool write(const uint8_t* data, size_t size) = 0;
  virtual bool read(std::vector<uint8_t>& out, size_t max_size) = 0;
  virtual void close() = 0;
};
} // namespace ps4fb
