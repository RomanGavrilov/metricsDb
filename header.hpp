#pragma once

#include <cstdint>
#include <cstddef>

struct Header
{
    uint32_t magic;
    uint32_t version;
    size_t offset;

    Header(uint32_t magic, uint32_t version, size_t offset)
        : magic(magic), version(version), offset(offset)
    {
    }

    Header() = default;
};