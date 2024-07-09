#ifndef HISTOGRAM_LIB
#define HISTOGRAM_LIB

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const size_t WIDTH = 80;
const size_t MAX_ASTERICS = WIDTH - 4;

void input_main_values(size_t& num_count, size_t& bin_count, size_t& step);
bool valid_step(size_t step);
std::vector<size_t> input_numbers(size_t count);

void find_min_max(const std::vector<size_t> nums, size_t& max_num, size_t& min_num);

std::vector<size_t> make_histogram
(const std::vector<size_t> nums, const size_t min_num, 
const size_t max_num, const size_t bin_count);

void print_histogram(std::vector<size_t> bins, size_t step, size_t max_num);

#endif