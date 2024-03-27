#pragma once
#include <math.h>

struct FractionalHex
{
    const double v[3];

    FractionalHex(double q, double r, double s) : v{ q, r, s }
    {
        if (round(q + r + s) != 0)
        {
            throw "q + r + s must be 0";
        }
    }

    // getter
    inline double q() { return v[0]; }
    inline double r() { return v[1]; }
    inline double s() { return v[2]; }

    Hex hexRound(FractionalHex h) {
        int q = int(round(h.q()));
        int r = int(round(h.r()));
        int s = int(round(h.s()));
        double q_diff = abs(q - h.q());
        double r_diff = abs(r - h.r());
        double s_diff = abs(s - h.s());
        if (q_diff > r_diff && q_diff > s_diff) {
            q = -r - s;
        }
        else if (r_diff > s_diff) {
            r = -q - s;
        }
        else {
            s = -q - r;
        }
        return Hex(q, r, s);
    }
};