#include <iostream>
#include <map>
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

    cerr << "Enter step from 4 to 9: ";
    cin >> step;
    if (step < 4 || step > 9) {
        cout << "ERROR";
        return 1;
    }

    map<size_t,size_t> bin_values;
    for (size_t i = 0; i < num_count; i++) {
        int temp; 
        cin >> temp;
        if (bin_values.find(temp) == bin_values.end())
            bin_values[temp] = 1;
        else
            bin_values[temp]++;
    }

    

    //------------------
    //Обработка значений
    //------------------
    size_t max_count = (bin_values.begin())->second;
    size_t max_num = (bin_values.begin())->first;
    for (auto i = ++bin_values.begin(); i != bin_values.end(); i++) {
        max_count = i->second > max_count ? i->second : max_count;
        max_num = i->first > max_num ? i->first : max_num;
    }


    
    //--------------
    //Вывод значений
    //--------------
    #define bin_num bin.second
    for (auto bin : bin_values) {
        if (max_count >= 10 && max_count < 100) {
            if (bin_num < 10) cout << " ";
        } 
        else if (max_count >= 100) {
            if (bin_num < 10) cout << "  ";
            else if (bin_num < 100) cout << " ";
        }
        cout << bin_num; 
        cout << "|";

        int astericses;
        if (max_count > MAX_ASTERICS) 
            astericses = MAX_ASTERICS * (static_cast<double>(bin.second) / max_count);
        else astericses = bin.second; 
        for (size_t i = 0; i < astericses || i == 0; i++) {
            cout << '*';
        }
        cout << '\n';
    }

      
    //  +-------+  //
    //  |Подписи|  //
    //  +-------+  //
    //шкала
    if (max_count > 100) cout << "   |";
    else if (max_count > 10) cout << "  |";
    else cout << " |";

    for (size_t i = 0; i < MAX_ASTERICS; i += step) {
        for (size_t j = 1; (j < step) ; j++) {
            if (i + j >= MAX_ASTERICS) break;
            cout << "-";
        }
        cout << "|";
    }
    cout << "\n";

    if (max_count > 100) cout << "   0";
    else if (max_count > 10) cout << "  0";
    else cout << " 0";

    //подписи
    double point = max_count > MAX_ASTERICS
                   ? static_cast<double>(max_count) 
                   / MAX_ASTERICS : 1;
    for (size_t i = 0; i < MAX_ASTERICS-1; i++) {
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