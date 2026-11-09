# Roadmap

1. Verify the exact GoldHEN release and PS4 homebrew SDK/toolchain available for firmware 13.02.
2. Verify whether the SDK exposes USB host enumeration, bulk endpoints, and interface claiming on this firmware.
3. Implement read-only USB discovery and display VID/PID/product strings.
4. Implement Fastboot handshake and read-only `getvar:product`, `getvar:version`, and `getvar:current-slot`.
5. Add image metadata checks and partition-size checks.
6. Only after device-specific validation, consider a guarded flashing implementation.

## Explicitly out of scope for early prototypes
- Writing any partition.
- Unlocking/relocking bootloader.
- Erasing userdata or metadata.
- Automatically choosing an A/B slot.
