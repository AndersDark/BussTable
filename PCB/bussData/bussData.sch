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
F 1 "RC1602A" V 4145 5044 50  0000 L CNN
F 2 "Display:RC1602A" H 4200 3500 50  0001 C CNN
F 3 "http://www.raystar-optronics.com/down.php?ProID=18" H 4200 4200 50  0001 C CNN
	1    4100 4300
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push_Open toggle_btn1
U 1 1 6164529D
P 5900 3850
F 0 "toggle_btn1" H 5900 4065 50  0000 C CNN
F 1 "SW_Push_Open" H 5900 3974 50  0000 C CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x02_P2.00mm_Vertical" H 5900 4050 50  0001 C CNN
F 3 "~" H 5900 4050 50  0001 C CNN
	1    5900 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R_LCD_GND1
U 1 1 6164578F
P 4200 4950
F 0 "R_LCD_GND1" H 4270 4996 50  0000 L CNN
F 1 "?" H 4270 4905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4130 4950 50  0001 C CNN
F 3 "~" H 4200 4950 50  0001 C CNN
	1    4200 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R__LCD_VDD1
U 1 1 61645FE6
P 4400 5100
F 0 "R__LCD_VDD1" H 4470 5146 50  0000 L CNN
F 1 "?" H 4470 5055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4330 5100 50  0001 C CNN
F 3 "~" H 4400 5100 50  0001 C CNN
	1    4400 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 61646194
P 5550 3500
F 0 "R3" H 5620 3546 50  0000 L CNN
F 1 "?" H 5620 3455 50  0000 L CNN
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
F 1 "R_POT_TRIM" V 5644 2950 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 5850 2950 50  0001 C CNN
F 3 "~" H 5850 2950 50  0001 C CNN
	1    5850 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 2850 3800 3900
Wire Wire Line
	2900 2950 3700 2950
Wire Wire Line
	3700 2950 3700 3900
Wire Wire Line
	3600 3050 3600 3900
Wire Wire Line
	3900 3250 3900 3900
Wire Wire Line
	2900 3350 4400 3350
Wire Wire Line
	4400 3350 4400 3900
Wire Wire Line
	2900 3450 4600 3450
Wire Wire Line
	4600 3450 4600 3900
Wire Wire Line
	5250 3550 5250 3850
Wire Wire Line
	5250 3850 5550 3850
Wire Wire Line
	5550 3850 5550 3650
Connection ~ 5550 3850
Wire Wire Line
	5550 3850 5700 3850
Wire Wire Line
	2900 2850 3800 2850
Wire Wire Line
	2900 3050 3600 3050
Wire Wire Line
	2900 3250 3900 3250
Wire Wire Line
	2900 3550 5250 3550
$Comp
L MCU_Module:WeMos_D1_mini ESP8266
U 1 1 61642F99
P 2500 3150
F 0 "ESP8266" H 2500 2261 50  0000 C CNN
F 1 "WeMos_D1_mini" H 2500 2170 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 2500 2000 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 650 2000 50  0001 C CNN
	1    2500 3150
	1    0    0    -1  
$EndComp
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
	2500 3950 2500 4300
Wire Wire Line
	2500 4300 3150 4300
Wire Wire Line
	3150 5650 3900 5650
Connection ~ 3150 4300
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
	2400 2350 2400 2200
Wire Wire Line
	2400 2200 4800 2200
Wire Wire Line
	4800 2200 4800 4300
Wire Wire Line
	4800 2200 6750 2200
Wire Wire Line
	6750 5950 4400 5950
Wire Wire Line
	4400 5950 4400 5250
Connection ~ 4800 2200
Wire Wire Line
	6500 2800 6500 5400
Wire Wire Line
	6750 3850 6100 3850
Wire Wire Line
	6750 3850 6750 5950
Connection ~ 6750 3850
Wire Wire Line
	6750 2950 6000 2950
Wire Wire Line
	6750 2200 6750 2950
Wire Wire Line
	6750 2950 6750 3850
Connection ~ 6750 2950
$EndSCHEMATC
