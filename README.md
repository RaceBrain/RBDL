# RBDL File Format

The RBDL (RaceBrain Data Logger) file format is a binary file format used by the RaceBrain Cortex to log different data channels sequentially.

## Structure

The structure of an RBDL file is as follows:

| Section |
| --- |
| File Header |
| Channel Headers |
| Rows |

## File Header

The file header is a 6 byte header that provides the information required to parse the rest of the file. It has the following structure:

| Field | Byte Width |
| --- | --- |
| Magic Identifier | 4 |
| Version Number | 1 |
| Number of Channels | 1 |

### Magic Identifier

The Magic Identifier is used to identify and confirm that the file being parsed is an RBDL file. If the four bytes do not match the ascii character values 'R', 'B', 'D', 'L' (0x52, 0x42, 0x44, 0x4C) then the file has been corrupted or is not an RBDL file.

### Version Number

The current RBDL version is 0. If the version number is higher than this, the file may contain features that are not described by this document.

### Number of Channels

This is the number of data channels that will be logged in this file. The file header is followed by the channel headers, and this field tells a parser how many to expect before the rows begin.

## Channel Headers

| Field | Byte Width |
| --- | --- |
| Channel Identifier | 1 |
| Channel Byte Width | 1 |

Each channel header contains two bytes. The first is a channel identifier that describes uniquely a data channel that can be logged.

The second byte describes how many bytes this channel will log to each row. Once all of the channel headers have been read, the parser can sum the byte widths of each channel to calculate the size for each row.

The following channel identifiers are currently defined by the specification.

| Channel | Identifier | Byte Width | Data Type |
| --- | --- | --- | --- |
| Position | 0x00 | 16 | RBDL Position |
| Time | 0x01 | 6 | RBDL Time |
| Accelerometer | 0x02 | 6 | RBDL Accelerometer |
| OBD-II RPM | 0x10 | 4 | IEEE-754 Float |
| OBD-II Vehicle Speed | 0x11 | 4 | IEEE-754 Float |
| OBD-II Throttle Position | 0x12 | 4 | IEEE-754 Float |
| OBD-II Engine Coolant Temperature | 0x13 | 4 | IEEE-754 Float |
| OBD-II Intake Air Temperature | 0x14 | 4 | IEEE-754 Float |
| Tyre Temperature Front Left Outer | 0x20 | 4 | IEEE-754 Float |
| Tyre Temperature Front Left Center | 0x21 | 4 | IEEE-754 Float |
| Tyre Temperature Front Left Inner | 0x22 | 4 | IEEE-754 Float |
| Tyre Temperature Front Right Outer | 0x23 | 4 | IEEE-754 Float |
| Tyre Temperature Front Right Center | 0x24 | 4 | IEEE-754 Float |
| Tyre Temperature Front Right Inner | 0x25 | 4 | IEEE-754 Float |
| Tyre Temperature Rear Left Outer | 0x26 | 4 | IEEE-754 Float |
| Tyre Temperature Rear Left Center | 0x27 | 4 | IEEE-754 Float |
| Tyre Temperature Rear Left Inner | 0x28 | 4 | IEEE-754 Float |
| Tyre Temperature Rear Right Outer | 0x29 | 4 | IEEE-754 Float |
| Tyre Temperature Rear Right Center | 0x2A | 4 | IEEE-754 Float |
| Tyre Temperature Rear Right Inner | 0x2B | 4 | IEEE-754 Float |
