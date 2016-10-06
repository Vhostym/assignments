# include <iostream>
# include <string>
#include <sstream>
using namespace std;

void set(char *arg[], int len, int res[]);
void sort(char *arg[], int len);

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

 
void set(char *arg[], int len, int res[]) {
 for (int i = 0; i < len; ++i) {
  res[i] = (int) *arg[i];
 }
}

void sort(int *arg, int len) {
 for (int i = 1; i < len; ++i) {
  if (arg[i] < arg[i - 1]) {
   for (int k = 0; k < i; ++k) {
    if (arg[k] >= arg[i]) {
     int temp = arg[i];
     arg[i] = arg[i - 1];
     arg[i - 1] = arg[k];
     arg[k] = temp;
     break;
    }
   }
  }
 }
}
