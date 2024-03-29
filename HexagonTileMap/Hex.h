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

class Hex
{
private:
    // stored coordinates as vector for fast vec3 computation on the GPU
    const int v[3];
  
public:
    Hex(int q, int r, int s) : v{ q, r, s }
    {
        if (q + r + s != 0)
        {
            throw "q + r + s must be 0";
        }
    }
    
    // getter
    inline const int q() const { return v[0]; }
    inline const int r() const { return v[1]; }
    inline const int s() const { return v[2]; }

    // computation
    inline int length() const
    {
        return int((abs(v[0]) + abs(v[1]) + abs(v[2])) / 2);
    }

    inline int distance(const Hex& other) const
    {
        return Hex(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]).length();
    }

    inline Hex neighbor(const HexDirection hexDirection) const
    {
        auto other = getHexDirection(hexDirection);
        return Hex(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
    }

    // comparison operators
    bool operator == (const Hex& other) const
    {
        return v[0] == other.v[0] && v[1] == other.v[1] && v[2] == other.v[2];
    }

    bool operator != (const Hex& other) const
    {
        return v[0] != other.v[0] || v[1] != other.v[1] || v[2] != other.v[2];
    }

    // arithmetic operators
    Hex operator + (const Hex& other) const
    {
        return Hex(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
    }

    Hex operator - (const Hex& other) const
    {
        return Hex(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
    }

    Hex operator * (const int k) const
    {
        return Hex(v[0] * k, v[1] * k, v[2] * k);
    }

    static const Hex getHexDirection(HexDirection hexDirection)
    {
        static const std::vector<Hex> hexDirections = {
            Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
            Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
        };
        return hexDirections[hexDirection];
    }
};
