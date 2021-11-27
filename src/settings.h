#pragma once

// Network SSID
#define NETWORK_NAME "DarkNet-2G"
#define NETWORK_PASSWORD "SanctusOmega100"

// pc network
// #define NETWORK_NAME "DarkNett"
// #define NETWORK_PASSWORD "11223344"

#define HOST "https://api.entur.io/journey-planner/v2/graphql"

// HTTPS fingerprint
// NB!!! can expire
#define FINGERPRINT "8f38836d359a28e11521129f144c0ef0c2c9df95" 

#define QUERY "{\"query\":\"{quay(id:\\\"NSR:Quay:74954\\\"){estimatedCalls{destinationDisplay{frontText} expectedArrivalTime}}}\"}"
// "NSR:Quay:74954" er busstoppet for berg studentby mot byen.
// Det er mulig å finne andre busstopp eller "quay" på https://api.entur.io/journey-planner/v2/ide/

String busses[] = {"Hallset via sentrum","Havstad via Lerkendal","Tempe"};
// Må være det som står på bussen