#include <iostream>
#include "segment_tree.h"

using namespace std;

int main(void) {
    vector<int> arr;

    arr.push_back(10);
    arr.push_back(38);
    arr.push_back(24);
    arr.push_back(50);
    arr.push_back(5);
    arr.push_back(100);
    arr.push_back(70);

    RMQ minimum(arr, [](int a, int b) -> int { return a < b ? a : b; }, 1E9);
    RMQ maximum(arr, [](int a, int b) -> int { return a < b ? b : a; }, -1E9);

    printf("minimum: %d, maximum: %d\n", minimum.query(1, 4), maximum.query(1, 4));

    return 0;
}