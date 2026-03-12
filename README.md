# CrillinOS

A hobby operating system built from scratch in C, designed to be fundamentally different from Linux while sharing its open spirit.
What I mean by this is that I want it to embrace free and open source software while most of the funtionality is fundamentally different down to the terminal language even (a modified JS fork that has bash-like properties and options but uses javascript keywords instead)

---

## Vision

CrillinOS aims to be a daily-driveable operating system with:

- A clean UEFI bootloader with a minimal text-based interface
- A custom kernel built from scratch
- A choice of two desktop experiences:
  - Classic stacking window management (familiar, Windows-style, similar to cinnamon DE on linux)
  - Lightweight tiling window management (similar to i3 on linux, no GPU effects, hyprland keybinds [super+w for close, super+space for my version of rofi])
- A closed-source compositor and desktop environment
- **Toilet** — a minimal init system focused on one job: process management

No bloat. No telemetry. No forced age attestation.

---

## Current Status

> Early development. Kernel not yet started. Contributions welcome.

| Component         | Status        |
|-------------------|---------------|
| Boot config parser| ✅ Working   |
| Bootloader        | 🔧 Planned    |
| Kernel            | 🔧 Planned    |
| Toilet (init)     | 🔧 Planned    |
| Compositor        | 🔧 Planned    |
| DE                | 🔧 Planned  |

---

## Repository Structure

```
CrillinOS/
├── bootloader/
│   ├── parser.c       # boot config parser
│   └── crillin.conf   # example boot config
├── kernel/            # coming soon
├── init/              # Toilet init system (coming soon)
└── README.md
```

---

## Building

### Boot Config Parser

Requirements: `gcc`, any Linux or WSL environment

```bash
cd bootloader
gcc parser.c -o parser
./parser crillin.conf
```

Expected output:
```
=== CrillinOS Boot Config ===
Key: TIMEOUT | Value: 5
Key: DEFAULT | Value: CrillinOS
Key: KERNEL  | Value: /boot/crillin.elf
Key: LOGLEVEL| Value: debug
Key: MAXMEM  | Value: 4096
```

---

## Config Format

The boot config uses simple `KEY=VALUE` syntax:

```
# this is a comment
; this is also a comment

TIMEOUT=5
DEFAULT=CrillinOS
KERNEL=/boot/crillin.elf
LOGLEVEL=debug
MAXMEM=4096
```

---

## License

The kernel and bootloader are licensed under **GPL v2**.

The compositor and desktop environment are closed source.

---

## Contributing

This project is in its earliest stages. All contributors welcome — kernel developers, driver porters, testers, and documentation writers.

If you want to contribute:
1. Fork the repository
2. Open an issue describing what you want to work on
3. Submit a pull request

No contribution is too small.

---

## Philosophy

> Built by someone who got tired of operating systems that don't respect the user.
> Started on day 2 of learning C. No, really.
