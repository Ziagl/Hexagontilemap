#pragma once
#include <math.h>

class FractionalHex
{
private:
    const double v[3];

public:
    FractionalHex(double q, double r, double s) : v{ q, r, s }
    {
        if (round(q + r + s) != 0)
        {
            throw "q + r + s must be 0";
        }
    }

    // getter
    inline const double q() const { return v[0]; }
    inline const double r() const { return v[1]; }
    inline const double s() const { return v[2]; }

    Hex hexRound() const
    {
        int _q = int(round(v[0]));
        int _r = int(round(v[1]));
        int _s = int(round(v[2]));
        double q_diff = abs(_q - v[0]);
        double r_diff = abs(_r - v[1]);
        double s_diff = abs(_s - v[2]);
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