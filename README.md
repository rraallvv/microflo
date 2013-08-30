MicroFlo: flow-based programming for microcontrollers
========================================================

Implementation of Flow-based programming. http://en.wikipedia.org/wiki/Flow-based_programming
Inspired by and designed for integration with NoFlo. http://noflojs.org/
First hardware target will be Arduino-compatible boards. http://arduino.cc

Different from most other physical computing involving Node/JavaScript in that it
aims to allow build standalone microcontroller applications, that can also be reconfigured in real-time.

Status
-------
Proof-of-concept still in progress. Nothing is stable or usable.
Currently does not even run on a microcontroller, only x86 host.

Milestone 0.0.2, "Hello World": Can run a .fbp graph which echoes back on serial
Milestone 0.1.0, "Minimally useful": Can implement a fridge flow
Milestone 0.2.0, "Generally useful": Implements Firmata protocol, most of Arduino tutorials works

License
-------
GNU LGPL v2.1+, for now

Rationale
----------
1. People should not need to understand text-based, C style programming to be able to program microcontrollers. But those that do know it should be able to use that knowledge, and be able to mix-and-match it with higher-level paradims within a single program.
2. It should be possible to verify correctness of a microcontroller program in an automated way, and ideally in a hardware-independent manner.
3. It should be possible to visually debug microcontroller programs.
4. Microcontroller functionality should be reprogrammable on the fly.
5. Microcontrollers should easily integrate into and with higher-level systems: other microcontrollers, host computers, and the Internet.
6. Microcontroller programs should be portable between different uC models and uC architectures.

Design
------
* Run on 8bit+ uCs with 32kB+ program memory and 1kB+ RAM
  * Primarily as bare-metal, but embedded Linux also possible in future
  * For initial component implementations, wrap Arduino/LUFA/etc
  * Components that are not tied to a particular I/O system shall have host-equivalents possible
* Take .fbp/.json flow definition files used by NoFlo as the canonical end-user input
  * Use NoFlo code to convert this to a more compact and easy-to-parse binary format, architecture-independent flow representation
  * Flows in binary format can be baked into the firmware image.
* Allow to introspect and manipulate graphs at runtime from a host over serial/USB/Ethernet.
  * Use a binary protocol derived from the binary graph representation for this.
* Allow a flow network to be embedded into an existing C/C++ application, provide API for manipulating
* Port and I/O configuration is stored in a central place, to easily change according to device/board deployed to.

Authors
-------
Jon Nordby <jononor@gmail.com>


Related
---------
https://github.com/rwaldron/johnny-five
https://github.com/jgautier/firmata
http://breakoutjs.com/
