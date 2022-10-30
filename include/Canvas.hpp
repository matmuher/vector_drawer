#pragma once

#include <ConcreteVector.hpp>
#include <Point.hpp>
#include <Rectangle.hpp>
#include <VectorService.hpp>
#include <LaPintura.hpp>

class Canvas
{
    Point m_center{}; // In windows coords
    Point m_prop_coefs{1, 1}; // Proportion coefs for x&y axes

    edge_type m_edges{};
    float m_width{};
    float m_height{};

    edge_type set_edges(Point &center, Point &pixel_size);

public:

    Canvas(Point &center);
    Canvas(Point center, Point real_size, Point pixel_size);
    Canvas();

    Point get_center() const;
    Point get_prop_coefs() const;
    edge_type get_edges() const;
    float get_width() const;
    float get_height() const;

    void set_center(const Point& new_center);
};

Point to_window_coords(Canvas cnvs, Point pnt);
ConcreteVector to_window_coords(Canvas cnvs, ConcreteVector cvec);
LaPintura to_window_coords(const Canvas& cnvs, const LaPintura& pintura);
// I set const type& as I am not intendet to chane object
// neigher I want to copy it. It's like passing const pointer
Rectangle to_window_coords(const Canvas& cnvs, const Rectangle& rect);
Point to_canvas_coords(Canvas cnvs, Point pnt);