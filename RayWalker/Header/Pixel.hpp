#ifndef _PIXEL_HPP
#define _PIXEL_HPP

#include <iosfwd>

#include <color.hpp>

class Pixel {
public :
  Pixel(std::size_t = 0, std::size_t = 0);
  std::size_t x;
  std::size_t y;
  Color       color;
};

#endif // BUW_PIXEL_HPP
