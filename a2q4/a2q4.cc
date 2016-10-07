#include <iostream>

using namespace std;

struct IntArray{
    int size;
    int capacity;
    int *contents;
};

void updateSize(IntArray &arr) {
    if (arr.size == 0) {
        arr.capacity = 5;
        arr.contents = int[5];
    } else {
        arr.capacity = 2 * arr.capacity;
        int * val = arr.contents;
        arr.contents = int[arr.capacity];
        for (int i = 0; i < arr.capacity / 2; ++i) {
            arr.contents[i] = val[i];
        }
        delete val;
    }
}

IntArray *readIntArray() {
    IntArray *arr{0, 0, nullptr};
    addToIntArray(arr);
    return arr;
}

void addToIntArray(IntArray &arr) {
    int n;
    while (cin >> n) {
        if (arr.size == arr.capacity)
            updateSize(arr);
        arr.contents[arr.size] = n;
        arr.size += 1;
    }
}

void printIntArray(IntArray &arr) {
    for (int i = 0; i < arr.size; ++i) {
        cout << n;
        if (i != arr.size - 1) {
            cout <<" ";
        }
    }
    cout << endl;
}

