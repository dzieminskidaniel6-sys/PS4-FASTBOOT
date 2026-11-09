// PS4 USB backend intentionally not implemented yet.
//
// Target notes (user-confirmed):
// - PS4 firmware 13.52
// - GoldHEN beta line; v2.4b18.13 is the latest surfaced release
//
// Before implementing this file, verify the exact SDK and its USB host API
// against the actual PS4 environment. GoldHEN does not automatically imply
// arbitrary USB host enumeration / bulk-transfer APIs are available.
// Do not guess libusb symbols or invent a transport implementation.
// First milestone: enumerate a connected USB device and read descriptors only.
// No Fastboot write/erase commands belong in this early backend.
#include "transport.h"

namespace ps4fb {
// Research placeholder only. This is not a functional USB transport.
}
