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
        int array[5];
        arr.contents = array;
    } else {
        arr.capacity = 2 * arr.capacity;
        int * val = arr.contents;
        int array[arr.capacity];
        arr.contents = array;
        for (int i = 0; i < arr.capacity / 2; ++i) {
            arr.contents[i] = val[i];
        }
        delete val;
    }
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

IntArray *readIntArray() {
    IntArray *arr{0, 0, new int[0]};
    addToIntArray(arr);
    return arr;
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

