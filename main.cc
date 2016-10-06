#include <stdio>
#using namespace std;

int * set(char *arg[], int len) {
 int *res[len];
 for (int i = 0; i < len; ++i) {
  res[i] = (int) arg[i];
 }
 return res;
}

void sort(char *arg[]) {
 for (int i = 1; i < *arg.length(); ++i) {
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

int main(int argc, char *argv[]) {
 int remainder = argv[argc - 2];
 int quotient;
 for (int i = 0; i < argc - 2; ++i) {
  quotient = val / argv[i];
  remainder = val % argv[i];
  if (quotient != 0) {
   cout << quotient << " x " << argv[i] << endl;
  }
  if (remainder == 0) {
   return 0;
  }
 }
}
 
