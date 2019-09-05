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
- BRD4161A\
  target: `brd4162a-mb`
- BRD4304A\
  target: `brd4304a-mb`

# Thunderboard Sense and Thunderboard Sense 2

target: `thunderboard`
target: `thunderboard2`

SiLabs Thunderboard Sense support TODO.

# Thinnect TestSystemBoard tsb

target: `tsb`

The TestSystemBoard is a custom PCB with an EFR32MG12P432F1024GM48 MCU,
an ft2232d based jtag programmer, 64Mbit JEDEC dataflash, a button and 3 LEDs.
The board has an SMA connector.
