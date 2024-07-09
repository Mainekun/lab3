#ifndef HISTO_SVG_LIB
#define HISTO_SVG_LIB

#include <cstdlib>
#include "histogram.hpp"

const size_t WIDTH_BOX = 500;
const size_t NUM_BOX = 50;
const size_t RECT_BOX = WIDTH_BOX - NUM_BOX;
const size_t MIN_HEIGHT_BOX = 100;
const size_t ROW_HEIGHT = 25;
const size_t BOX_POINT = 5;
const size_t COLOURS_COUNT = 12;
const std::string COLOURS_XML[COLOURS_COUNT] = {"red", "blue", "green", "yellow", 
                         "blueviolet", "lawngreen", "crimson", "cyan",
                         "deepskyblue", "darkorange", "magenta", "tomato"};

void svgBegin(size_t bin_count);
void svgEnd();
std::string rand_colour();
void svg_rect(size_t x, size_t y, size_t height, size_t width);
void svg_text(size_t x, size_t y, std::string text);
void show_svg_histogram(std::vector<size_t> bins, size_t step, size_t max_n);

#endif