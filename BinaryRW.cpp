#include "BinaryRW.h"

/******************** BINARY WRITER ********************/

BinaryWriter::BinaryWriter() {

}

void BinaryWriter::setBuffer(std::vector<unsigned char> &buffer) {
    _buffer = buffer;
}
std::vector<unsigned char> &BinaryWriter::getBuffer() {
    return _buffer;
}
void BinaryWriter::clearBuffer() {
    _buffer.clear();
}

template <class T>
void BinaryWriter::writeBytes(T &val, const bool &LE) {
    unsigned const char *array = reinterpret_cast<unsigned const char *>(&val);

    if (LE == true) {
        for (unsigned char i = 0; i < sizeof(val); ++i)
            _buffer.push_back(array[i]);
    } else {
        for (char i = sizeof(val) - 1; i >= 0; --i)
            _buffer.push_back(array[i]);
    }
}

//========== Endianless ==========//

void BinaryWriter::writeStr(const std::string &str) {
    for (const auto &s : str) writeBytes<const char>(s, false);
}
void BinaryWriter::writeStr(const char* str) {
    for (unsigned int i = 0; i < std::strlen(str); ++i)
        writeBytes<const char>(str[i], false);
}
void BinaryWriter::writeBool(const bool &val) {
    writeBytes<const bool>(val, true);
}

//========== Little Endian ==========//

void BinaryWriter::writeInt8_LE(const char &val) {
    writeBytes<const char>(val, true);
}
void BinaryWriter::writeInt16_LE(const short &val) {
    writeBytes<const short>(val, true);
}
void BinaryWriter::writeInt32_LE(const int &val) {
    writeBytes<const int>(val, true);
}
void BinaryWriter::writeInt64_LE(const long long &val) {
    writeBytes<const long long>(val, true);
}
void BinaryWriter::writeUInt8_LE(const unsigned char &val) {
    writeBytes<const unsigned char>(val, true);
}
void BinaryWriter::writeUInt16_LE(const unsigned short &val) {
    writeBytes<const unsigned short>(val, true);
}
void BinaryWriter::writeUInt32_LE(const unsigned int &val) {
    writeBytes<const unsigned int>(val, true);
}
void BinaryWriter::writeUInt64_LE(const unsigned long long &val) {
    writeBytes<const unsigned long long>(val, true);
}
void BinaryWriter::writeFloat_LE(const float &val) {
    union { float fnum; unsigned int inum; } u;
    u.fnum = val;
    writeUInt32_LE(u.inum);
}
void BinaryWriter::writeDouble_LE(const double &val) {
    union { double fnum; unsigned long long inum; } u;
    u.fnum = val;
    writeUInt64_LE(u.inum);
}

//========== Big Endian ==========//

void BinaryWriter::writeInt8_BE(const char &val) {
    writeBytes<const char>(val, false);
}
void BinaryWriter::writeInt16_BE(const short &val) {
    writeBytes<const short>(val, false);
}
void BinaryWriter::writeInt32_BE(const int &val) {
    writeBytes<const int>(val, false);
}
void BinaryWriter::writeInt64_BE(const long long &val) {
    writeBytes<const long long>(val, false);
}
void BinaryWriter::writeUInt8_BE(const unsigned char &val) {
    writeBytes<const unsigned char>(val, false);
}
void BinaryWriter::writeUInt16_BE(const unsigned short &val) {
    writeBytes<const unsigned short>(val, false);
}
void BinaryWriter::writeUInt32_BE(const unsigned int &val) {
    writeBytes<const unsigned int>(val, false);
}
void BinaryWriter::writeUInt64_BE(const unsigned long long &val) {
    writeBytes<const unsigned long long>(val, false);
}
void BinaryWriter::writeFloat_BE(const float &val) {
    union { float fnum; unsigned int inum; } u;
    u.fnum = val;
    writeUInt32_BE(u.inum);
}
void BinaryWriter::writeDouble_BE(const double &val) {
    union { double fnum; unsigned long long inum; } u;
    u.fnum = val;
    writeUInt64_BE(u.inum);
}

BinaryWriter::~BinaryWriter() {
    clearBuffer();
}


/******************** BINARY READER ********************/

BinaryReader::BinaryReader(std::vector<unsigned char> &buffer) : _buffer(buffer) {
}

void BinaryReader::setBuffer(std::vector<unsigned char> &buffer) {
    _buffer.clear();
    _buffer = buffer;
}
void BinaryReader::reset() {
    _offset = 0;
}

template <typename T>
T BinaryReader::readBytes(const unsigned char &endianness) {
    T result = 0;
    unsigned int size = sizeof(T);

    // Do not overflow
    if (_offset + size > _buffer.size())
        return result; 

    char *dst = (char *)&result;
    char *src = (char *)&(_buffer[_offset]);

    for (unsigned int i = 0; i < size; ++i) {
        // Little Endian
        if (endianness == 0)
            dst[i] = src[i];

        // Big Endian
        else if (endianness == 1)
            dst[i] = src[(size-i-1)];

        // Middle Endian
        else if (endianness == 2)
            dst[i] = src[(i%2==0?(i+1):(i-1))];

        // Test
        else if (endianness == 3)
            dst[i] = src[(i%2==0?(size-i-2):(size-i))];
    }
    _offset += size;
    return result;
}
void BinaryReader::skipBytes(const unsigned long long &len) {
    _offset += len;
}
void BinaryReader::printBytes() {
    std::cout << "{ " << std::hex << std::setfill('0');
    for (const auto &byte : _buffer) {
        std::cout << std::setw(2) << (unsigned short)byte << " ";
    }
    std::cout << "}\n" << std::dec;
}

//========== Endianless ==========//

std::string BinaryReader::readStr(const unsigned long long &len) {
    std::string result(_buffer.begin() + _offset, _buffer.begin() + _offset + len);
    _offset += len;
    return result;
}
std::string BinaryReader::readStr() {
    return readStr(_buffer.size() - _offset);
}
bool BinaryReader::readBool() {
    return readBytes<bool>(0);
}

//========== Little Endian ==========//

char BinaryReader::readInt8_LE() {
    return readBytes<char>(0);
}
short BinaryReader::readInt16_LE() {
    return readBytes<short>(0);
}
int BinaryReader::readInt32_LE() {
    return readBytes<int>(0);
}
long long BinaryReader::readInt64_LE() {
    return readBytes<long long>(0);
}
unsigned char BinaryReader::readUInt8_LE() {
    return readBytes<unsigned char>(0);
}
unsigned short BinaryReader::readUInt16_LE() {
    return readBytes<unsigned short>(0);
}
unsigned int BinaryReader::readUInt32_LE() {
    return readBytes<unsigned int>(0);
}
unsigned long long BinaryReader::readUInt64_LE() {
    return readBytes<unsigned long long>(0);
}
float BinaryReader::readFloat_LE() {
    return readBytes<float>(0);
}
double BinaryReader::readDouble_LE() {
    return readBytes<double>(0);
}

//========== Big Endian ==========//

char BinaryReader::readInt8_BE() {
    return readBytes<char>(1);
}
short BinaryReader::readInt16_BE() {
    return readBytes<short>(1);
}
int BinaryReader::readInt32_BE() {
    return readBytes<int>(1);
}
long long BinaryReader::readInt64_BE() {
    return readBytes<long long>(1);
}
unsigned char BinaryReader::readUInt8_BE() {
    return readBytes<unsigned char>(1);
}
unsigned short BinaryReader::readUInt16_BE() {
    return readBytes<unsigned short>(1);
}
unsigned int BinaryReader::readUInt32_BE() {
    return readBytes<unsigned int>(1);
}
unsigned long long BinaryReader::readUInt64_BE() {
    return readBytes<unsigned long long>(1);
}
float BinaryReader::readFloat_BE() {
    return readBytes<float>(1);
}
double BinaryReader::readDouble_BE() {
    return readBytes<double>(1);
}

BinaryReader::~BinaryReader() {
    _buffer.clear();
}
