EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny4-TS U1
U 1 1 6220225A
P 1750 1775
F 0 "U1" H 1220 1821 50  0000 R CNN
F 1 "ATtiny4-TS" H 1220 1730 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 1750 1775 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8127-AVR-8-bit-Microcontroller-ATtiny4-ATtiny5-ATtiny9-ATtiny10_Datasheet.pdf" H 1750 1775 50  0001 C CNN
	1    1750 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 1075 1750 1175
Wire Wire Line
	1750 2375 1750 2475
Wire Wire Line
	1750 2475 3150 2475
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 6220353C
P 3750 1475
F 0 "J2" H 3830 1517 50  0000 L CNN
F 1 "Conn_VDG" H 3830 1426 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3750 1475 50  0001 C CNN
F 3 "~" H 3750 1475 50  0001 C CNN
	1    3750 1475
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1375 3150 1375
Wire Wire Line
	3150 1575 3550 1575
Wire Wire Line
	3550 1475 2350 1475
Wire Wire Line
	3150 1375 3150 1075
Wire Wire Line
	3150 1575 3150 2475
Wire Wire Line
	3150 1575 2350 1575
Connection ~ 3150 1575
Text Label 2450 1475 0    50   ~ 0
BJT_B
Text Label 2450 1575 0    50   ~ 0
BJT_E
Text Label 2450 1075 0    50   ~ 0
BJT_C
Wire Wire Line
	1750 1075 3150 1075
Text Notes 1775 3000 0    50   ~ 0
Pins 2+3 are tied together so that,\nin addition to turning the ATtiny\ninto a sound chip, this PCB can \nturn a SOT-3 transistor into an\nequivalent TO-92 transistor with a\nnormal TO-92 transistor pinout.
$EndSCHEMATC
