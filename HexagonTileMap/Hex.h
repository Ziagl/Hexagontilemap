#pragma once

#include <vector>

enum HexDirection
{
    EAST = 0,
    NORTHEAST = 1,
    NORTHWEST = 2,
    WEST = 3,
    SOUTHWEST = 4,
    SOUTHEAST = 5
};

struct Hex
{
    static const std::vector<Hex> hexDirections;

    // stored coordinates as vector for fast vec3 computation on the GPU
    const int v[3];
  
    Hex(int q, int r, int s) : v{ q, r, s }
    {
        if (q + r + s != 0)
        {
            throw "q + r + s must be 0";
        }
    }
    
    // getter
    inline int q() { return v[0]; }
    inline int r() { return v[1]; }
    inline int s() { return v[2]; }

    // computation
    inline int length()
    {
        return int((abs(q()) + abs(r()) + abs(s())) / 2);
    }

    inline int distance(Hex other)
    {
        return Hex(q() - other.q(), r() - other.r(), s() - other.s()).length();
    }

    inline Hex neighbor(HexDirection hexDirection)
    {
        auto other = hexDirections[hexDirection];
        return Hex(q() + other.q(), r() + other.r(), s() + other.s());
    }

    // comparison operators
    bool operator == (Hex other)
    {
        return q() == other.q() && r() == other.r() && s() == other.s();
    }

    bool operator != (Hex other)
    {
        return q() != other.q() || r() != other.r() || s() != other.s();
    }

    // arithmetic operators
    Hex operator + (Hex other)
    {
        return Hex(q() + other.q(), r() + other.r(), s() + other.s());
    }

    Hex operator - (Hex other)
    {
        return Hex(q() - other.q(), r() - other.r(), s() - other.s());
    }

    Hex operator * (int k)
    {
        return Hex(q() * k, r() * k, s() * k);
    }
};
