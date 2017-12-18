# Binary-Reader-Writer
C++ binary reader &amp; writer implementation for reading + writing binary data

Usage:
```cpp
#include <iostream>
#include "BinaryRW.h"

int main() {
    /** Writing to buffer **/
    
    BinaryWriter writer;

    writer.writeStr("test");
    writer.writeBool(true);
    writer.writeInt8_LE(64);
    writer.writeInt16_LE(32767);
    writer.writeInt32_LE(2147483647);
    writer.writeInt64_LE(9223372036854775807ll);
    writer.writeFloat_LE(12.34f);
    writer.writeDouble_LE(56.789f);

    std::vector<unsigned char> buffer = writer.getBuffer();

    /** Reading from buffer **/

    BinaryReader reader(buffer);

    std::string x = reader.readStr(4);
    bool       x1 = reader.readBool();
    char       x2 = reader.readInt8_LE();
    short      x3 = reader.readInt16_LE();
    int        x4 = reader.readInt32_LE();
    long long  x5 = reader.readInt64_LE();
    float      x6 = reader.readFloat_LE();
    double     x7 = reader.readDouble_LE();

    std::cout << "x:  " <<  x << "\n";
    std::cout << "x1: " << x1 << "\n";
    std::cout << "x2: " << x2 << "\n";
    std::cout << "x3: " << x3 << "\n";
    std::cout << "x4: " << x4 << "\n";
    std::cout << "x5: " << x5 << "\n";
    std::cout << "x6: " << x6 << "\n";
    std::cout << "x7: " << x7 << "\n";

    writer.clearBuffer();
}
```
