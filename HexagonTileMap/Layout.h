#pragma once
#include "Orientation.h"
#include "Point.h"
#include "Hex.h"
#include "FractionalHex.h"

#include <vector>

struct Layout
{
    const Orientation orientation;
    const Point size;
    const Point origin;

    Layout(Orientation orientation_, Point size_, Point origin_)
        : orientation(orientation_), size(size_), origin(origin_) {}

    Point hexToPixel(Hex h);
    FractionalHex pixelToHex(Point p);

    Point hexCornerOffset(int corner);
    std::vector<Point> polygonCorners(Layout layout, Hex h);
};