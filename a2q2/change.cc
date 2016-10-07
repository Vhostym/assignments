#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

const int imax = std::numeric_limits<int>::max();

void set(char *arg[], int len, int res[]) {
 for (int i = 0; i < len; ++i) {
  res[i] = (int) *arg[i];
 }
}

int findmin(int arg[], int len) {
  int min = imax;
  int index = -1;
  for (int i = 0; i < len; ++i) {
    if (arg[i] <= imax) {
      min = arg[i];
      index = i;
    }
  }
  if (index == -1) {
    return -1;
  } else {
    arg[index] = imax;
    return min;
  }
}

void sort(int arg[], int len) {
  int array[len];
  for (int i = 0; i < len; ++i) {
    array[i] = findmin(arg, len);
  }
  arg = array;
}


int main(int argc, char *argv[]) {
 stringstream str = (basic_stringstream<char>) argv[argc - 2];
 int val;
 str >> val;
 int remainder = (int) val;
 int arr[argc - 1];
 set(argv, argc - 1, arr);
 int quotient;
 for (int i = 0; i < argc - 2; ++i) {
  quotient = val / arr[i];
  remainder = val % arr[i];
  if (quotient != 0) {
   cout << quotient << " x " << arr[i] << endl;
  }
  if (remainder == 0) {
   return 0;
  }
 }
}
