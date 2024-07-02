#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

const size_t WIDTH = 80;
const size_t MAX_ASTERICS = WIDTH - 4;

int main() {
    //-------------
    //Ввод значений
    //-------------
    size_t num_count, step;
    cerr << "Enter number count: ";
    cin >> num_count;

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;

    cerr << "Enter step from 4 to 9: ";
    cin >> step;
    if (step < 4 || step > 9) {
        cout << "ERROR";
        return 1;
    }

    vector<size_t> nums(num_count);
    for (size_t i = 0; i < num_count; i++)
        cin >> nums[i];


    //------------------
    //Обработка значений
    //------------------
    size_t max_n = nums[0];
    size_t min_n = nums[0];
    for (auto i = ++nums.begin(); i != nums.end(); i++) {
        max_n = *i > max_n ? *i : max_n;
        min_n = *i < min_n ? *i : min_n;
    }

    double step_bin = static_cast<double>(max_n - min_n) / bin_count;
    vector<size_t> bins(bin_count, 0);
    for (auto i : nums) {
        for (size_t j = 0; j < bin_count; j++) {
            if ((i >= min_n + step_bin * j && i < min_n + step_bin * (j + 1)) || j == bin_count - 1) {
                bins[j]++;
                break;
            }
        }
    }



    //--------------
    //Вывод значений
    //--------------
    for (auto bin_val : bins) {
        if (bin_val < 100) cout << " ";
        if (bin_val < 10) cout << " ";
        cout << bin_val;
        cout << "|";

        int astericses;
        if (max_n > MAX_ASTERICS)
            astericses = MAX_ASTERICS * (static_cast<double>(bin_val) / max_n);
        else astericses = bin_val;
        for (size_t i = 0; i < astericses || i == 0; i++) {
            cout << '*';
        }
        cout << '\n';
    }


    //  +-------+  //
    //  |Подписи|  //
    //  +-------+  //
    //шкала
    cout << "   |";

    for (size_t i = 0; i < MAX_ASTERICS; i += step) {
        for (size_t j = 1; (j < step); j++) {
            if (i + j >= MAX_ASTERICS) break;
            cout << "-";
        }
        cout << "|";
    }
    cout << "\n";

    cout << "   0";

    //подписи
    double point = max_n > MAX_ASTERICS
        ? static_cast<double>(max_n)
        / MAX_ASTERICS : 1;
    for (size_t i = 0; i < MAX_ASTERICS - 1; i++) {
        if (i == step - 1) {
            size_t second_num = round(point * step);
            cout << second_num;
            if (second_num > 10) i++;
            if (second_num > 100) i++;
            continue;
        }

        cout << " ";
    }
    cout << round(point * MAX_ASTERICS);
}