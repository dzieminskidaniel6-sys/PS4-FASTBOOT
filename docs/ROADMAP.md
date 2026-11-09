# Roadmap

## Target environment

- PS4 firmware: 13.52 (user clarification).
- GoldHEN: latest surfaced beta as of 2026-11-09 is v2.4b18.13. The changelog history attributes 13.52 support to v2.4b18.11, 13.02/13.04/13.50 to v2.4b18.12, and 14.00 to v2.4b18.13. Verify the exact installed payload on-console.
- Target Android: Motorola Moto G15 Power (XT2521-5 / lamu), LineageOS 24 / Android 16.

## Milestones

1. [x] Record target hardware and corrected PS4 firmware 13.52.
2. [x] Record the latest surfaced GoldHEN beta line.
3. [ ] Select and document a PS4 homebrew SDK/toolchain compatible with firmware 13.52.
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

GoldHEN being active does not by itself prove that a PS4 homebrew SDK exposes USB host APIs needed for Android Fastboot. Do not add guessed libusb calls or claim the console can flash until this is demonstrated on hardware.
