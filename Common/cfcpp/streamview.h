#pragma once

#include <iostream>
#include <list>
#include "sector.h"
#include "slist.h"
#include "svector.h"

namespace CFCPP
{
class StreamView : public IStream
{
public:
    StreamView(const SVector<Sector> &sectorChain, int sectorSize, Stream stream);
    StreamView(const SVector<Sector> &sectorChain, int sectorSize, std::streamsize length,
               SList<Sector> &availableSectors, Stream stream, bool isFatStream = false);

    std::streamsize tell() override;
    std::streamsize seek(std::streamsize offset, std::ios_base::seekdir mode = std::ios::beg) override;
    std::streamsize read(char *buffer, std::streamsize count) override;
    void write(const char *buffer, std::streamsize count) override;
    void flush() override {}
    void close() override;

    void SetLength(std::streamsize value);
    std::streamsize getLength() const;
    inline SVector<Sector>& BaseSectorChain() {return sectorChain;}

    int ReadInt32();
    void WriteInt32(int val);

private:
    void adjustLength(std::streamsize value);
    void adjustLength(std::streamsize value, SList<Sector> &availableSectors);
private:
    int sectorSize;
    std::streamsize length;

    SVector<Sector> sectorChain;
    bool isFatStream = false;
    int buf = 0;

public:
    Stream stream;
    SList<Sector> freeSectors;
    std::streamsize position = 0;
};
}
