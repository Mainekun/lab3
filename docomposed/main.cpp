#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const size_t WIDTH = 80;
const size_t MAX_ASTERICS = WIDTH - 4;

vector<size_t> input_numbers(size_t count) {
    vector<size_t> nums(count);
    for (size_t i = 0; i < count; i++) 
        cin >> nums[i];
    return nums; 
}

void find_min_max(const vector<size_t> nums, size_t& max_num, size_t& min_num) {
    max_num = *max_element(nums.begin(), nums.end());
    min_num = *min_element(nums.begin(), nums.end());
}

vector<size_t> make_histogram
(const vector<size_t> nums, const size_t min_num, const size_t max_num, const size_t bin_count) {
    double step = static_cast<double>(max_num - min_num) / bin_count;
    vector<size_t> bins(bin_count);
    for (auto num : nums) 
        for (size_t i = 0; i < bin_count; i++)
            if ((num >= min_num + step * i && num < min_num + step * (i + 1)) ||
                i == bin_count) {
                    bins[i]++;
                    break;
                }

    return bins;
}

void print_histogram(vector<size_t> bins, size_t step, size_t max_num) {
    size_t max_count = *max_element(bins.begin(), bins.end());
    for (auto bin : bins) {
        if (bin < 100) cout << ' ';
        if (bin < 10) cout << ' ';
        cout << bin << '|';

        size_t asterics;
        if (max_count > MAX_ASTERICS)
            asterics = MAX_ASTERICS * (static_cast<double>(bin) / max_count);
        else asterics = bin;
        for (size_t i = 0 ; i < asterics; i++) 
            cout << '*';
        cout << '\n';
    }

    cout << "   |";
    size_t floor = max(max_count, MAX_ASTERICS);
    size_t steps_count = ceil(static_cast<double>(floor) / step);
    if (steps_count == 1) steps_count++;

    for (size_t i = 0; (i < steps_count) && (i * step < floor); i++)
        for (size_t j = 1; j < step; j++) 
            cout << '-';
        cout << '|';
    cout << '\n';
    cout << "   0";

    double point = max_num > MAX_ASTERICS
        ? static_cast<double>(max_num) / MAX_ASTERICS
        : 1;
    for (size_t i = 0; i < steps_count * step - 1 || i < 2 * step - 1; i++) {
        if (i == step - 1) { 
            size_t second_num = round(point * step);
            cout << second_num;
            if (second_num > 10) i++;
            if (second_num > 100) i++;
            continue;
        }

        cout << ' ';
    }
    cout << round(point * max_count);
}

int main() 
{
    size_t num_count, bin_count, step, min_num, max_num;
    cerr << "Enter number count: ";
    cin >> num_count; 
    cerr << "Enter bin count: ";
    cin >> bin_count; 
    cerr << "Enter step (4 <= x <= 9): ";
    cin >> step;
    if (step < 4 || step > 9) {
        cout << "ERROR";
        return 1;
    }
    const auto nums = input_numbers(num_count);
    find_min_max(nums, max_num, min_num);
    const auto bins = make_histogram(nums, min_num, max_num, bin_count);
    print_histogram(bins, step, max_num);
}