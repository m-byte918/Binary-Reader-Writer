# Binary-Reader-Writer
C++ binary reader &amp; writer implementation for reading + writing binary data

Usage:
```cpp
#include <iostream>
#include "Buffer.hpp"

int main() {
    Buffer buf;

    /** Writing to buffer **/

    buf.writeBool(true);
    buf.writeStr("Hello!");
    buf.writeInt8(64);
    buf.writeUInt8(228);

    buf.writeInt16_LE(-32768);
    buf.writeInt16_BE(-32768);
    buf.writeUInt16_LE(65535);
    buf.writeUInt16_BE(65535);

    buf.writeInt32_LE(-2147483648);
    buf.writeInt32_BE(-2147483648);
    buf.writeUInt32_LE(4294967295);
    buf.writeUInt32_BE(4294967295);

    buf.writeInt64_LE(-9223372036854775808ll);
    buf.writeInt64_BE(-9223372036854775808ll);
    buf.writeUInt64_LE(18446744073709551615ll);
    buf.writeUInt64_BE(18446744073709551615ll);

    buf.writeFloat_LE(3.4e+38f);
    buf.writeFloat_BE(3.4e-38f);
    buf.writeDouble_LE(1.7e+308);
    buf.writeDouble_BE(1.7e-308);

    /** Reading from buffer **/

    bool               x  = buf.readBool();
    std::string        x1 = buf.readStr(6);
    char               x2 = buf.readInt8();
    unsigned char      x3 = buf.readUInt8();

    short              x4 = buf.readInt16_LE();
    short              x5 = buf.readInt16_BE();
    unsigned short     x6 = buf.readUInt16_LE();
    unsigned short     x7 = buf.readUInt16_BE();

    int                x8  = buf.readInt32_LE();
    int                x9  = buf.readInt32_BE();
    unsigned int       x10 = buf.readUInt32_LE();
    unsigned int       x11 = buf.readUInt32_BE();

    long long          x12 = buf.readInt64_LE();
    long long          x13 = buf.readInt64_BE();
    unsigned long long x14 = buf.readUInt64_LE();
    unsigned long long x15 = buf.readInt64_BE();

    float              x16 = buf.readFloat_LE();
    float              x17 = buf.readFloat_BE();
    double             x18 = buf.readDouble_LE();
    double             x19 = buf.readDouble_BE();

    std::cout << "x:  "  << x   << "\n"
              << "x1: "  << x1  << "\n"
              << "x2: "  << x2  << "\n"
              << "x3: "  << x3  << "\n"
              << "x4: "  << x4  << "\n"
              << "x5: "  << x5  << "\n"
              << "x6: "  << x6  << "\n"
              << "x7: "  << x7  << "\n"
              << "x8: "  << x8  << "\n"
              << "x9: "  << x9  << "\n"
              << "x10: " << x10 << "\n"
              << "x11: " << x11 << "\n"
              << "x12: " << x12 << "\n"
              << "x13: " << x13 << "\n"
              << "x14: " << x14 << "\n"
              << "x15: " << x15 << "\n"
              << "x16: " << x16 << "\n"
              << "x17: " << x17 << "\n"
              << "x18: " << x18 << "\n"
              << "x19: " << x19 << "\n\n"
              << "<Buffer " << buf.byteStr() << ">";

    buf.clearBuffer(); // clear buffer contents
}
```
Results:
```
x:  1
x1: Hello!
x2: @
x3: Σ
x4: -32768
x5: -32768
x6: 65535
x7: 65535
x8: -2147483648
x9: -2147483648
x10: 4294967295
x11: 4294967295
x12: -9223372036854775808
x13: -9223372036854775808
x14: 18446744073709551615
x15: 18446744073709551615
x16: 3.4e+38
x17: 3.4e-38
x18: 1.7e+308
x19: 1.7e-308

<Buffer 01 48 65 6c 6c 6f 21 40 e4 00 80 80 00 ff ff ff ff 00 00 00 80 80 00 00 00 ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 80 80 00 00 00 00 00 00 00 ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff 9e c9 7f 7f 01 39 1d 15 76 3b 77 30 d1 42 ee 7f 00 0c 39 6c 98 f8 d8 99 >
```
