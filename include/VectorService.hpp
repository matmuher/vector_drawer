#pragma once

#include <Point.hpp>

// in RGBA

typedef unsigned pixel_color;

enum class Colors : pixel_color
{
    RED   = 0xFF0000FF,
    GREEN = 0x00FF00FF,
    BLUE  = 0x0000FFFF,
    WHITE = 0xFFFFFFFF,
    BLACK = 0x000000FF
};

typedef char color_component;
class ParsedColor
{
public:
    color_component r, g, b, a;

    ParsedColor(Colors color)
    {
        color_component* color_ptr = (color_component*) &color;
        a = color_ptr[0];
        b = color_ptr[1];
        g = color_ptr[2];
        r = color_ptr[3];
    }

    ParsedColor() : ParsedColor(Colors::BLUE) {};
};

// Implements transforamtion from user's coord system to window's

struct edge_type // How to incapsulate it in class?
    {
    Point   left_up, 
            left_down, 
            right_up, 
            right_down;
    }; 