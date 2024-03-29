#pragma once

#include "Hex.h"

#include <unordered_map>

template <> struct std::hash<Hex> 
{
    size_t operator()(const Hex& h) const
    {
        std::hash<int> int_hash;
        size_t hq = int_hash(h.q());
        size_t hr = int_hash(h.r());
        return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
    }
};

struct Map
{
    std::unordered_map<Hex, float> heights;

    void Add(Hex coordinate, float element)
    {
        heights.insert({ coordinate, element });
    }

    float Get(Hex coordinate)
    {
        return heights.at(coordinate);
    }
};