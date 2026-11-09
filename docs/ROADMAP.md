# Roadmap

## Target environment

- PS4 firmware: 13.02 (user-reported).
- GoldHEN: use the newest compatible release available for the console. As of 2026-11-09, the surfaced latest beta is v2.4b18.13; v2.4b18.12 added 13.02/13.04/13.50 support, and v2.4b18.13 adds 14.00 while retaining earlier targets. Verify the actual version in GoldHEN settings before testing.
- Target Android: Motorola Moto G15 Power (XT2521-5 / lamu), LineageOS 24.

## Milestones

1. [x] Record target hardware and firmware from user-provided context.
2. [x] Correct the GoldHEN target notes to the current beta line.
3. [ ] Select and document a PS4 homebrew SDK/toolchain compatible with the target firmware.
4. [ ] Verify USB host enumeration, interface claiming and bulk endpoint transfers on the actual PS4.
5. [ ] Implement read-only USB discovery (VID/PID and descriptors).
6. [ ] Implement Fastboot handshake and read-only getvar:product, getvar:version, and getvar:current-slot.
7. [ ] Test the read-only path with the Moto G15 Power.
8. [ ] Only after independent review, consider a guarded write design.

## Explicitly out of scope for early prototypes

- Writing or erasing any Android partition.
- Unlocking or relocking the Android bootloader.
- Automatically selecting an A/B slot.
- Guessing a partition name or flashing an unverified image.

## Blocking unknown

GoldHEN being active does not by itself prove that the PS4 homebrew SDK exposes the USB host APIs needed for an Android Fastboot connection. Do not add guessed libusb calls or claim the console can flash until this is demonstrated on hardware.
