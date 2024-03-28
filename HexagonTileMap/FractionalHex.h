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

    Hex hexRound()
    {
        int _q = int(round(q()));
        int _r = int(round(r()));
        int _s = int(round(s()));
        double q_diff = abs(_q - q());
        double r_diff = abs(_r - r());
        double s_diff = abs(_s - s());
        if (q_diff > r_diff && q_diff > s_diff) {
            _q = -_r - _s;
        }
        else if (r_diff > s_diff) {
            _r = -_q - _s;
        }
        else {
            _s = -_q - _r;
        }
        return Hex(_q, _r, _s);
    }
};