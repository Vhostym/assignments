#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void set(char *arg[], int len, int res[]) {
 for (int i = 0; i < len; ++i) {
  res[i] = (int) *arg[i];
 }
}

int findmin(int arg[], int len) {
  int min = arg[0];
  int index = 0;
  for (int i = 0; i < len; ++i) {
    if (arg[i] <= min && arg[i] != -1) {
      min = arg[i];
      index = i;
    }
  }
  if (index == -1) {
    return -1;
  } else {
    arg[index] = -1;
    return min;
  }
}

void sort(int arg[], int len) {
  int array[len - 1];
  for (int i = 1; i < len; ++i) {
    array[i] = findmin(arg, len);
  }
  arg = array;
}


int main(int argc, char *argv[]) {
 stringstream str = (basic_stringstream<char>) argv[argc - 1];
 int val;
 str >> val;
 int remainder = (int) val;
 cout << "val " << val << endl;
 int arr[argc - 1];
 set(argv, argc - 1, arr);
 sort(arr, argc - 2);

 for (int i = 0; i < arr.length(); ++i) {
  cout << " " << arr[i];
 }

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
