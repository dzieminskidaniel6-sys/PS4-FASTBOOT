// PS4 USB backend intentionally not implemented yet.
//
// Target notes (user-reported):
// - PS4 firmware 13.02
// - GoldHEN, with v2.4b18.13 identified as the latest surfaced beta line
//
// Before implementing this file, verify the exact SDK and its USB host API
// against the actual PS4 environment. GoldHEN does not automatically imply
// that arbitrary USB host enumeration / bulk-transfer APIs are available.
//
// Do not guess libusb symbols or invent a transport implementation.
// First milestone: enumerate a connected USB device and read descriptors only.
// No Fastboot write/erase commands belong in this early backend.
#include "transport.h"

namespace ps4fb {
// Research placeholder only. This is not a functional USB transport.
}
