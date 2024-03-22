#include "Layout.h"
#include "Globals.h"

Point Layout::hexToPixel(Hex h)
{
    const Orientation& M = this->orientation;
    double x = (M.f0 * h.q() + M.f1 * h.r()) * this->size.x;
    double y = (M.f2 * h.q() + M.f3 * h.r()) * this->size.y;
    return Point(x + this->origin.x, y + this->origin.y);
}

FractionalHex Layout::pixelToHex(Point p)
{
    const Orientation& M = this->orientation;
    Point pt = Point((p.x - this->origin.x) / this->size.x, (p.y - this->origin.y) / this->size.y);
    double q = M.b0 * pt.x + M.b1 * pt.y;
    double r = M.b2 * pt.x + M.b3 * pt.y;
    return FractionalHex(q, r, -q - r);
}

Point Layout::hexCornerOffset(int corner)
{
    Point size = this->size;
    double angle = 2.0 * M_PI * (this->orientation.start_angle + corner) / 6;
    return Point(size.x * cos(angle), size.y * sin(angle));
}

std::vector<Point> Layout::polygonCorners(Layout layout, Hex h)
{
    std::vector<Point> corners = {};
    Point center = this->hexToPixel(h);
    for (int i = 0; i < 6; i++) {
        Point offset = this->hexCornerOffset(i);
        corners.push_back(Point(center.x + offset.x, center.y + offset.y));
    }
    return corners;
}