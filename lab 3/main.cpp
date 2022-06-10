#include "algorithms.h"
#include <vector>


int main() {

    vector <double> v = { 1,2,3,5,4};
//    if (all_of(v.begin(), v.end(), bigger_then_two<int>)) {
//        cout << "True\n";
//    }
//    else {
//        cout << "False\n";
//    }
//
//
//    if (any_of(v.begin(), v.end(), bigger_then_two<int>)) {
//        cout << "True\n";
//    }
//    else {
//        cout << "False\n";
//    }
//
//    if (none_of(v.begin(), v.end(), bigger_then_two<int>)) {
//        cout << "True\n";
//    }
//    else {
//        cout << "False\n";
//    }
//
//    if (one_of(v.begin(), v.end(), bigger_then_two<int>)) {
//        cout << "True\n";
//    }
//    else {
//        cout << "False\n";
//    }
//
//    if (is_sorted(v.begin(), v.end(), compare<int>)) {
//        cout << "True\n";
//    }
//    else {
//        cout << "False\n";
//    }

    auto is_even = [](int i){ return i % 2 == 0; };

    if (is_partitioned(v.begin(), v.end(), is_even)) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }

    return 0;


}
