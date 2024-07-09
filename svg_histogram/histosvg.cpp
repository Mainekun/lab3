#include "histogram_svg.hpp"
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    size_t num_count, bin_count, step, min_num, max_num;
    input_main_values(num_count, bin_count, step);
    if (!valid_step(step))
        return 1;
    const auto nums = input_numbers(num_count);
    find_min_max(nums, max_num, min_num);
    const auto bins = make_histogram(nums, min_num, max_num, bin_count);
    
    svgBegin(bin_count);

    show_svg_histogram(bins, step, max_num);

    svgEnd();
}