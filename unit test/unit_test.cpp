#include <cassert>
#include "histogram.hpp"

using namespace std;

void test_three_num() {
    size_t min_n = 0, max_n = 0;
    find_min_max({1,2,3}, max_n, min_n);
    assert(min_n == 1);
    assert(max_n == 3);
}

void test_one_num() {
    size_t min_n = 0, max_n = 0;
    find_min_max({1}, max_n, min_n);
    assert(min_n == 1);
    assert(max_n == 1);
}

void test_three_similar() {
    size_t min_n = 0, max_n = 0;
    find_min_max({1, 1, 1}, max_n, min_n);
    assert(min_n == 1);
    assert(max_n == 1);
}

void test_zero_num() {
    size_t min_n = 0, max_n = 0;
    find_min_max({}, max_n, min_n);
    assert(min_n == 0);
    assert(max_n == 0);
}

int main() {
    //find_min_max(vec, &max, &min)
    test_three_num();
    test_one_num();
    test_three_similar();
    test_zero_num();
}

