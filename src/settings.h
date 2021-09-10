#pragma once

// Network SSID
// #define NETWORK_NAME "Get-2G-3510F1"
// #define NETWORK_PASSWORD "HRX448U44B"

// pc network
#define NETWORK_NAME "DarkNett"
#define NETWORK_PASSWORD "11223344"

// HTTPS fingerprint
// NB!!! can expire
#define FINGERPRINT "8f38836d359a28e11521129f144c0ef0c2c9df95" 

#define QUERY "{\"query\": \"{quay(id:\\\"NSR:Quay:74954\\\"){name estimatedCalls{expectedArrivalTime destinationDisplay{frontText}}}}\"}"
// "NSR:Quay:74954" er busstoppet for berg studentby mot byen.
// Det er mulig å finne andre busstopp eller "quay" på https://api.entur.io/journey-planner/v2/ide/

#define NTP_SERVER "no.pool.ntp.org" //to get time
#define TZ_INFO "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00" //Norwegian timezone