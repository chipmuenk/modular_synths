[Back to main](../README.md)

---

# Analog Circuits

## Operational Amplifiers (Opamps)

Most analog synth and audio circuits are built around opamps as they simplify analog design tremendously. The number of different opamps on the market is absolutely overwhelming, especially for newbies. I will try to recommend some popular devices and explain the most important parameters. 

Opamps are used to amplify and process DC voltages and currents precisely which is needed e.g. to scale synthesizer control voltages. Due to their very high DC gains, linearity is hardly ever an issue as long as they are operated with feedback. Here, the gain is "programmed" by resistance ratios, hence resistor tolerances usually are the main error source. However, offset voltages and currents contribute random errors, limiting the accuracy.

For AC applications like oscillators, filters, amplifiers etc. DC precision is not an issue but distortions and reduced gain at higher frequencies can raise problems.

In both cases the maximum input and output voltage ranges can be a limiting factor, though usually not for modular synths (supply voltage +/-12 V or +/-15 V) and a maximum signal / audio voltages of +/-10 V. Problems may appear when interfacing to microcontrollers or codecs running with supply voltages of 5V or lower.

A general concern is the package: Many modern OPAmps are not available in breadboard-friendly DIL packages but only as tiny SMDs. 

OPA     | Manufacturer | &Delta; V_in | &Delta; V_out | V_offset [mV]| GBW [MHz]| SR [V/&mu;s] | Comment
--------|--------------|--------------|---------------|--------------|----------|--------------|----
OP741   | many         |  |  |  |  |  |  obsolete
TL07x   | many         |  |  |  |  |  |  universal
NE5532  | many         |  |  |  |  |  |  dual, low-noise, fast
OP97    | ADI          |  |  |  |  |  |  precision
OPAx377 | TI           |  |  |  |  |  |  precision, low-voltage

<hr>

[Back to main](../README.md)
