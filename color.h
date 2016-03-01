#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    float R, G, B, A;

    Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);

    Color operator +(const Color &c) const;
    Color operator -(const Color &c) const;
    Color operator *(float f) const;
    Color operator +(float f) const;
};

#endif // COLOR_H
