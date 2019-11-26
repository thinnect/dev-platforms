# dev-platforms
Platform definitions and code for development platforms. For integration
with the [node-platform](https://github.com/thinnect/node-platform/)
and [node-buildsystem](https://github.com/thinnect/node-buildsystem).

See [node-apps](https://github.com/thinnect/node-apps) for some example applications.

# SiLabs BRD4001A and Radio Modules

The Wireless Mainboard BRD4001A is the main development board from SiLabs. It
may be coupled with very many different Radio Boards. Most of the
Flex/Blue/Mighty Gecko variants can be made to work by replicating one of the
tested board .target and .board files with most likely minimal changes.

Tested boards:
- BRD4161A\
  target: `brd4161a-mb`
- BRD4162A\
  target: `brd4162a-mb`
- BRD4304A\
  target: `brd4304a-mb`

# Thunderboard Sense and Thunderboard Sense 2

SiLabs SLTB001A Development kit, BRD4160A. (EOL by SiLabs)\
  target: `thunderboard`

SiLabs SLTB004A Develompment kit, BRD4166A.\
  target: `thunderboard2`

# Thinnect TestSystemBoards tsb0, tsb1, tsb2

target: `tsb0`

target: `tsb1`

target: `tsb2`

The TestSystemBoards are a series of custom PCBs with Silabs EFR32 MCUs.
The TSB0 and TSB1 have EFR32MG12P432F1024GM48 MCUs,
the TSB2 has an EFR32BG21A020F1024IM32 MCU. They all have an ft2232d based jtag
programmer built in, a 64Mbit JEDEC dataflash, a button and 3 LEDs.
The boards have an SMA connector for the antenna.

The TSB0 does not have a 32.768kHz Crystal Oscillator, the TSB1 fixes this
shortcoming.
