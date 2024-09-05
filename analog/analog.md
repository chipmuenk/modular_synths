[Back to main](../README.md)

---

# Analog Circuits

## Operational Amplifiers (Opamps)

Most analog synth and audio circuits are built around opamps as they simplify analog design tremendously. The number of different opamps on the market is absolutely overwhelming, especially for newbies. I will try to recommend some popular devices and explain the most important parameters. 

Opamps are used to amplify and process DC voltages and currents precisely which is needed e.g. to scale synthesizer control voltages. Due to their very high DC gains, linearity is hardly ever an issue as long as they are operated with feedback. Here, the gain is "programmed" by resistance ratios, hence resistor tolerances usually are the main error source. However, offset voltages and currents contribute random errors, limiting the accuracy.

For AC applications like oscillators, filters, amplifiers etc. DC precision is not an issue but distortions and reduced gain at higher frequencies can raise problems.

In both cases the maximum input and output voltage ranges can be a limiting factor, though usually not for modular synths (supply voltage +/-12 V or +/-15 V) and a maximum signal / audio voltages of +/-10 V. Problems may appear when interfacing to microcontrollers or codecs running with supply voltages of 5V or lower.

A general concern is the package: Many modern OPAmps are not available in breadboard-friendly DIL packages but only as tiny SMDs. 

OPA     | Manuf. | #     | V_S [V]   | V_in [V]     | V_out [V]     | V_off [mV]| GBW [MHz]| SR [V/&mu;s] | Comment
--------|--------|:-----:|-----------|--------------|---------------|-----------|----------|--------------|----
OP741   | many   | 1     | 10 ... 36 |  |  |  |  |  | obsolete
TL07x   | many   | 1/2/4 |           |  |  |  |  |  | universal
NE5532/4| many   | 2/4   |           |  |  |  |  |  |  |  dual, low-noise, fast
OP97    | ADI    |       |           |  |  |  |  |  |   precision
TLC2272/4 | TI   | 2/4   | 4.4 ... 16| RR | RR | 1 | 2 |  3.6 |
OPAx377 | TI     | 1/2/4 |           |  |  |  |  |  |  precision, low-voltage
TLV246x | TI | 1/2/4 | 2.7 ... 6 | RR|RR| 2 |6.4|1.6| low-voltage, low-cost
TLV278x | TI | 2 / 4 | 1.8 ... 3.6 | RR|RR| 3 |8|5| low-voltage
LM6142/4 |TI|2/4|1.8 ... 24|RR|RR|1|17|25|
AD8031/2 |ADI|1/2|2.7 ... 12|RR|RR|6|80|30

- Manuf.: Manufacturer. Successful opamps often are produced by different manufacturers with identical (or very similar) specifications and the same number
- #: number of device per package (often, variations of the opamp are available like TL071/72/74 with different number of opamps per package)
- V_S: Min. / max. supply voltage
- V_in / V_out: Min. / max. input/output voltage, given as the difference to the supply voltages (RR = rail-to-rail)
- V_off: Max. offset voltage at 25°C
- GBW: Typ. gain-bandwidth product
- SR: Typ. Slew-rate

---

[Back to main](../README.md)
