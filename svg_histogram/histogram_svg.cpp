#include "histogram_svg.hpp"
using namespace std;

void svgEnd() {
    printf("</svg>\n");
}

void svgBegin(size_t bin_count) {
    size_t height = MIN_HEIGHT_BOX + 50 * bin_count;
    printf("<?xml version='1.0' encoding='UTF-8' ?>\n");
    printf("<svg width='%d' height='%d' viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n", 
    WIDTH_BOX, height, WIDTH_BOX, height);
}

string rand_colour() {
    return COLOURS_XML[rand() % 12];
}

void svg_rect(size_t x, size_t y, size_t height, size_t width) {
    printf("\t<rect x='%d' y='%d' width='%d' height='%d' fill='%s'/>\n",
    x, y, width, height, rand_colour().c_str());
}

void svg_b_rect(size_t x, size_t y, size_t height, size_t width) {
    printf("\t<rect x='%d' y='%d' width='%d' height='%d' fill='black'/>\n",
    x, y, width, height);
}

void svg_text(size_t x, size_t y, std::string text) {
    printf("\t<text x='%d' y='%d'>%s</text>\n", x, y, text.c_str());
}

void show_svg_histogram(vector<size_t> bins, size_t step, size_t max_n) {
    size_t max_count = *max_element(bins.begin(), bins.end());
    #define bin bins[i]
    for (size_t i = 0; i < bins.size(); i++) {
        size_t text_alignment;
        if (bin < 10) text_alignment = 40;
        else if (bin < 100) text_alignment = 32;
        else text_alignment = 24;
        svg_text( text_alignment, ROW_HEIGHT * (i + 1) - 5, to_string(bin));
        size_t rect_length;
        if (max_count * BOX_POINT  > WIDTH_BOX - 50)
            rect_length = RECT_BOX * (static_cast<double>(bin) / max_count);
        else rect_length = bin * 5;
        svg_rect(50, ROW_HEIGHT * i, ROW_HEIGHT, rect_length);
    }
    #undef bin

    size_t scale_length = min(max_count * BOX_POINT, RECT_BOX);
    size_t steps_count = ceil(static_cast<double>(scale_length / BOX_POINT) / step);
    if (steps_count == 1) steps_count++;

    svg_b_rect(NUM_BOX, ROW_HEIGHT * bins.size() + 12, 1, steps_count * step * 5);
    svg_b_rect(NUM_BOX, ROW_HEIGHT * bins.size(), ROW_HEIGHT, 1);

    for (size_t i = 1; i <= steps_count; i++) 
        svg_b_rect(NUM_BOX + step * BOX_POINT * i, ROW_HEIGHT * bins.size(), ROW_HEIGHT, 1);
    
    double point = max_count * 5 > RECT_BOX
        ? static_cast<double>(max_count) / RECT_BOX * 5 
        : 1;
    size_t text_row_y = ROW_HEIGHT * (bins.size() + 1) + 15;
    svg_text(NUM_BOX - 5, text_row_y, "0");
    svg_text(NUM_BOX - 5 + step * BOX_POINT, text_row_y, 
             to_string(static_cast<size_t>(round(point * step))));
    svg_text(NUM_BOX - 5 + step * steps_count * BOX_POINT, text_row_y, 
             to_string(static_cast<size_t>(point * steps_count * step)));
}