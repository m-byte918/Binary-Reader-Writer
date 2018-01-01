#pragma once
#include <vector>   // buffers
#include <string>   // writeStr(), readStr()
#include <cstring>  // writeStr(const char *)
#include <iostream> // printBytes()
#include <iomanip>  // printBytes()

class BinaryWriter {
    private:
        std::vector<unsigned char> _buffer;

    public:
        BinaryWriter();

        void setBuffer(std::vector<unsigned char> &buffer);
        std::vector<unsigned char> &getBuffer();
        void clearBuffer();

        void writeBytes(const auto &val, const bool &LE);

        // Endianless
        void writeStr(const std::string &str);
        void writeStr(const char *str);
        void writeBool(const bool &val);

        // Little Endian
        void writeInt8_LE(const char &val);
        void writeInt16_LE(const short &val);
        void writeInt32_LE(const int &val);
        void writeInt64_LE(const long long &val);

        void writeUInt8_LE(const unsigned char &val);
        void writeUInt16_LE(const unsigned short &val);
        void writeUInt32_LE(const unsigned int &val);
        void writeUInt64_LE(const unsigned long long &val);

        void writeFloat_LE(const float &val);
        void writeDouble_LE(const double &val);

        // Big Endian
        void writeInt8_BE(const char &val);
        void writeInt16_BE(const short &val);
        void writeInt32_BE(const int &val);
        void writeInt64_BE(const long long &val);

        void writeUInt8_BE(const unsigned char &val);
        void writeUInt16_BE(const unsigned short &val);
        void writeUInt32_BE(const unsigned int &val);
        void writeUInt64_BE(const unsigned long long &val);

        void writeFloat_BE(const float &val);
        void writeDouble_BE(const double &val);

        ~BinaryWriter();
};

class BinaryReader {
    private:
        std::vector<unsigned char> _buffer;
        unsigned long long _offset = 0;

    public:
        BinaryReader(std::vector<unsigned char> &buffer);

        void setBuffer(std::vector<unsigned char> &buffer);
        void reset();

        template <typename T>
        T readBytes(const unsigned char &endianness);
        void skipBytes(const unsigned long long &len);
        void printBytes();

        // Endianless
        std::string readStr(const unsigned long long &len);
        std::string readStr();
        bool readBool();

        // Little Endian
        char               readInt8_LE();
        short              readInt16_LE();
        int                readInt32_LE();
        long long          readInt64_LE();

        unsigned char      readUInt8_LE();
        unsigned short     readUInt16_LE();
        unsigned int       readUInt32_LE();
        unsigned long long readUInt64_LE();

        float              readFloat_LE();
        double             readDouble_LE();

        // Big Endian
        char               readInt8_BE();
        short              readInt16_BE();
        int                readInt32_BE();
        long long          readInt64_BE();

        unsigned char      readUInt8_BE();
        unsigned short     readUInt16_BE();
        unsigned int       readUInt32_BE();
        unsigned long long readUInt64_BE();

        float              readFloat_BE();
        double             readDouble_BE();

        ~BinaryReader();
};
