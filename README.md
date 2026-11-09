# PS4 Fastboot Flasher

Experimental PS4 homebrew research project to test whether a jailbroken PS4 can communicate with an Android device in Fastboot mode over USB.

**Status: research scaffold only. No installable PKG and no working PS4 USB backend yet.**

## Target setup

- Console: PS4, firmware 13.52 (user clarification).
- Homebrew: GoldHEN v2.4b18.13 is the latest surfaced beta as of 2026-11-09. The beta changelog line introduced 13.52 support in v2.4b18.11 and later added 13.02/13.04/13.50 in v2.4b18.12; v2.4b18.13 adds 14.00. Confirm the actual payload version on-console.
- Android device: Motorola Moto G15 Power, XT2521-5 (lamu).
- Android OS: LineageOS 24 / Android 16 (user-reported).

## What exists

- Fastboot command validation and response parsing.
- A transport abstraction.
- Host-side protocol tests and GitHub Actions CI.
- A placeholder PS4 USB transport file.

## What does NOT exist yet

- PS4 USB host enumeration or bulk-transfer implementation.
- A PS4-targeted build.
- An installable .pkg.
- Any ability to read or write Android partitions from the PS4.

## Development plan

1. Confirm the exact PS4 firmware and GoldHEN payload version on-device.
2. Identify a PS4 SDK/toolchain that supports firmware 13.52.
3. Prove USB host enumeration and bulk endpoints independently of Fastboot.
4. Add read-only Fastboot handshake and getvar requests.
5. Test with the Moto G15 Power without issuing write/erase commands.
6. Consider flashing only after device identity, partition map, slot, image size and recovery paths are independently verified.

## Safety

This project must remain read-only until USB communication and device identification are proven. Never guess whether the correct target is boot, boot_a, boot_b, init_boot, or vendor_boot. A future write feature must verify the connected product, exact partition capacity, image integrity and active slot, and require a separate explicit confirmation.

## Build host tests

    cmake -S . -B build
    cmake --build build
    ctest --test-dir build --output-on-failure

These commands build portable protocol tests on a normal development host. They do not create a PS4 PKG. A real PS4 package requires a compatible PS4 homebrew SDK/toolchain and a verified USB host API.
