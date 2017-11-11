#ifndef RBDL_H_
#define RBDL_H_

#include <stdint.h>

typedef struct rbdl_header_t_ {
    uint8_t magic[4]; // 'R', 'B', 'D', 'L'
    uint8_t version;
    uint8_t channels;
} __attribute__((packed)) rbdl_header_t;

typedef struct rbdl_channel_header_t_ {
    uint8_t channel;
} __attribute__((packed)) rbdl_channel_header_t;

typedef struct rbdl_row_header_t_ {
    uint32_t millis;
} __attribute__((packed)) rbdl_row_header_t;

#define RBDL_VERSION_0 0

#define RBDL_CHANNEL_POSITION 0x00
#define RBDL_CHANNEL_TIME 0x01
#define RBDL_CHANNEL_ACCELEROMETER 0x02

typedef struct rbdl_position_t_ {
    double latitude;
    double longitude;
} __attribute__((packed)) rbdl_position_t;

typedef struct rbdl_time_t_ {
    uint16_t year : 12;
    uint8_t month : 4;
    uint8_t day : 5;
    uint8_t hour : 5;
    uint8_t minute : 6;
    uint8_t second : 6;
    uint16_t millis : 10; 
} __attribute__((packed)) rbdl_time_t;

typedef struct rbdl_accelerometer_t_ {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} __attribute__((packed)) rbdl_accelerometer_t;

#define RBDL_CHANNEL_OBD_RPM 0x10
#define RBDL_CHANNEL_OBD_VEHICLE_SPEED 0x11
#define RBDL_CHANNEL_OBD_THROTTLE_POSITION 0x12
#define RBDL_CHANNEL_OBD_ENGINE_COOLANT_TEMPERATURE 0x13
#define RBDL_CHANNEL_OBD_INTAKE_AIR_TEMPERATURE 0x14

#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_LEFT_OUTER 0x20
#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_LEFT_CENTER 0x21
#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_LEFT_INNER 0x22
#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_RIGHT_OUTER 0x23
#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_RIGHT_CENTER 0x24
#define RBDL_CHANNEL_TYRE_TEMPERATURE_FRONT_RIGHT_INNER 0x25
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_LEFT_OUTER 0x26
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_LEFT_CENTER 0x27
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_LEFT_INNER 0x28
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_RIGHT_OUTER 0x29
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_RIGHT_CENTER 0x2A
#define RBDL_CHANNEL_TYRE_TEMPERATURE_REAR_RIGHT_INNER 0x2B

#endif
