#include "Orientation.h"

// initialize static const class variables
const Orientation Orientation::layoutPointy = Orientation(
    sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0,
    sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0, 0.5);

const Orientation Orientation::layoutFlat = Orientation(
    3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0),
    2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0, 0.0);
