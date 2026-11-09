# PS4 Fastboot Flasher

Experimental homebrew research project for testing whether a jailbroken PS4 can communicate with an Android device in Fastboot mode over USB.

**Status: prototype / research scaffold. No PS4 PKG is produced yet.**

## Safety
- The current build is a protocol and transport scaffold only.
- It does **not** write to Android partitions.
- Do not connect a device and expect flashing to work.
- A future write implementation must verify device identity, product, partition size, image size, slot, and bootloader state, and require an explicit confirmation.
- Never guess between `boot`, `boot_a`, `boot_b`, `init_boot`, or `vendor_boot`.

## Project layout
- `src/fastboot_protocol.*`: Fastboot packet framing and response parsing.
- `src/transport.h`: transport abstraction.
- `src/ps4_usb_transport.cpp`: placeholder for a PS4 USB-host backend; actual API support must be verified against the target SDK and firmware.
- `tests/`: host-side protocol tests.
- `.github/workflows/ci.yml`: portable host build and tests.

## Current target
- Console: PS4, firmware 13.02, GoldHEN (user-reported; compatibility not yet verified)
- Android device: Motorola Moto G15 Power (XT2521-5 / lamu)
- Android OS: LineageOS 24

## Build host tests
```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

A real PS4 PKG requires a compatible PS4 homebrew SDK/toolchain and a verified USB host API. GitHub Actions currently runs portable tests only.
