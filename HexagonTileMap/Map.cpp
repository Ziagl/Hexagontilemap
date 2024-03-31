#include "Map.h"

template <typename T>
void Map<T>::generateHexagonMap(int size)
{
    int n = size / 2;
    for (int q = -n; q <= n; q++) {
        int r1 = std::max(-n, -q - n);
        int r2 = std::min(n, -q + n);
        for (int r = r1; r <= r2; r++) {
            add(Hex(q, r, -q - r), T());
        }
    }
}

template <typename T>
void Map<T>::generateRectangleMap(RectangleType type, int left, int right, int top, int bottom)
{
    switch (type)
    {
        case RectangleType::POINTYTOP:
            for (int r = top; r <= bottom; r++) { // pointy top
                int r_offset = floor(r / 2.0); // or r>>1
                for (int q = left - r_offset; q <= right - r_offset; q++) {
                    add(Hex(q, r, -q - r), T());
                }
            }
            break;
        case RectangleType::FLATTOP:
            for (int q = left; q <= right; q++) { // flat top
                int q_offset = floor(q / 2.0); // or q>>1
                for (int r = top - q_offset; r <= bottom - q_offset; r++) {
                    add(Hex(q, r, -q - r), T());
                }
            }
    }
}