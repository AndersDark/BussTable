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
L Display_Character:RC1602A LCD1
U 1 1 61644224
P 4100 4300
F 0 "LCD1" V 4054 5044 50  0000 L CNN
F 1 "RC1602A" V 4145 5044 50  0001 L CNN
F 2 "Display:WC1602A" H 4200 3500 50  0001 C CNN
F 3 "http://www.raystar-optronics.com/down.php?ProID=18" H 4200 4200 50  0001 C CNN
	1    4100 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R GND1
U 1 1 6164578F
P 4200 4950
F 0 "GND1" H 4270 4996 50  0000 L CNN
F 1 "?" H 4270 4905 50  0001 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4130 4950 50  0001 C CNN
F 3 "~" H 4200 4950 50  0001 C CNN
	1    4200 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R VDD1
U 1 1 61645FE6
P 4400 5100
F 0 "VDD1" H 4470 5146 50  0000 L CNN
F 1 "?" H 4470 5055 50  0001 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4330 5100 50  0001 C CNN
F 3 "~" H 4400 5100 50  0001 C CNN
	1    4400 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R_btn1
U 1 1 61646194
P 5550 3500
F 0 "R_btn1" H 5620 3546 50  0000 L CNN
F 1 "?" H 5620 3455 50  0001 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5480 3500 50  0001 C CNN
F 3 "~" H 5550 3500 50  0001 C CNN
	1    5550 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM DIM1
U 1 1 616516AF
P 5850 2950
F 0 "DIM1" V 5735 2950 50  0000 C CNN
F 1 "R_POT_TRIM" V 5644 2950 50  0001 C CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 5850 2950 50  0001 C CNN
F 3 "~" H 5850 2950 50  0001 C CNN
	1    5850 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5550 3850 5550 3700
Wire Wire Line
	5550 3850 5700 3850
Wire Wire Line
	5850 2800 6500 2800
Wire Wire Line
	4200 4800 4300 4800
Wire Wire Line
	4300 4800 4300 4700
Wire Wire Line
	4400 4800 4300 4800
Connection ~ 4300 4800
Wire Wire Line
	3150 5650 3900 5650
Wire Wire Line
	3150 4300 3400 4300
Wire Wire Line
	3800 5400 6500 5400
Wire Wire Line
	3800 4700 3800 5400
Wire Wire Line
	3150 4300 3150 5650
Wire Wire Line
	4200 5100 4200 5650
Wire Wire Line
	4400 4800 4400 4950
Wire Wire Line
	4200 5650 5350 5650
Wire Wire Line
	5350 5650 5350 3200
Wire Wire Line
	5350 2950 5700 2950
Connection ~ 4200 5650
Wire Wire Line
	5550 3350 5550 3200
Wire Wire Line
	5550 3200 5350 3200
Connection ~ 5350 3200
Wire Wire Line
	5350 3200 5350 2950
Wire Wire Line
	3900 4700 3900 5650
Connection ~ 3900 5650
Wire Wire Line
	3900 5650 4200 5650
Wire Wire Line
	5350 3200 4500 3200
Wire Wire Line
	4500 3200 4500 3900
Wire Wire Line
	6750 5950 4400 5950
Wire Wire Line
	4400 5950 4400 5250
Wire Wire Line
	6500 2800 6500 5400
Wire Wire Line
	6750 3850 6100 3850
Wire Wire Line
	6750 3850 6750 4300
Connection ~ 6750 3850
Wire Wire Line
	6750 2950 6000 2950
Wire Wire Line
	6750 2950 6750 3850
Connection ~ 6750 2950
Wire Wire Line
	2200 1950 2200 900 
Wire Wire Line
	2200 900  6750 900 
Wire Wire Line
	6750 900  6750 2950
Wire Wire Line
	4800 4300 6750 4300
Connection ~ 6750 4300
Wire Wire Line
	6750 4300 6750 5950
Wire Wire Line
	2300 1950 2300 1700
Wire Wire Line
	2300 1700 1300 1700
Wire Wire Line
	1300 1700 1300 5650
Wire Wire Line
	1300 5650 3150 5650
Connection ~ 3150 5650
Wire Wire Line
	2700 1950 2700 1550
Wire Wire Line
	2700 1550 3800 1550
Wire Wire Line
	3800 1550 3800 3900
Wire Wire Line
	2600 1950 2600 1450
Wire Wire Line
	2600 1450 3700 1450
Wire Wire Line
	3700 1450 3700 3900
Wire Wire Line
	2500 1950 2500 1650
Wire Wire Line
	2500 1650 3600 1650
Wire Wire Line
	3600 1650 3600 3900
Wire Wire Line
	2600 2950 2600 3300
Wire Wire Line
	2600 3300 3900 3300
Wire Wire Line
	3900 3300 3900 3900
Wire Wire Line
	2500 2950 2500 3350
Wire Wire Line
	2500 3350 4400 3350
Wire Wire Line
	4400 3350 4400 3900
Wire Wire Line
	2400 2950 2400 3550
Wire Wire Line
	2400 3550 4600 3550
Wire Wire Line
	4600 3550 4600 3900
Wire Wire Line
	5550 3700 2300 3700
Wire Wire Line
	2300 3700 2300 2950
Connection ~ 5550 3700
Wire Wire Line
	5550 3700 5550 3650
$Comp
L Switch:SW_Push_Open btn1
U 1 1 616B840E
P 5900 3850
F 0 "btn1" H 5900 3974 50  0000 C CNN
F 1 "SW_Push_Open" H 5900 3974 50  0001 C CNN
F 2 "Switch_Keyboard_Cherry_MX:SW_Cherry_MX_PCB_1.00u" H 5900 4050 50  0001 C CNN
F 3 "~" H 5900 4050 50  0001 C CNN
	1    5900 3850
	1    0    0    -1  
$EndComp
$Comp
L wemos_mini:WeMos_mini esp8266
U 1 1 61660B12
P 2550 2450
F 0 "esp8266" V 2497 1872 60  0000 R CNN
F 1 "WeMos_mini" V 2603 1872 60  0001 R CNN
F 2 "Module:D1_mini_board" H 3100 1750 60  0001 C CNN
F 3 "" H 2550 2981 60  0000 C CNN
	1    2550 2450
	0    -1   1    0   
$EndComp
$EndSCHEMATC
