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

enum RectangleType
{
    POINTYTOP = 0,
    FLATTOP = 1
};

template <typename T>
struct Map
{
private:
    std::unordered_map<Hex, T> map;

public:
    void add(Hex coordinate, T element)
    {
        map.insert({ coordinate, element });
    }

    T get(Hex coordinate)
    {
        return map.at(coordinate);
    }

    void generateHexagonMap(int size);
    void generateRectangleMap(RectangleType type, int left, int right, int top, int bottom);
};
