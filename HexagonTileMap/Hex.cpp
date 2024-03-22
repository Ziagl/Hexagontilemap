#include "Hex.h"

// initialize static const class variables
const std::vector<Hex> Hex::hexDirections = {
    Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
    Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};
