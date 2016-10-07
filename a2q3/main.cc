#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
 int spaces = 0;
 string line;
 string character;
 bool semicolon = false;
 while (cin) {
  getline(cin, line);
  istringstream iss(line);
  while (iss >> character) {
   if (character == "//") {
    semicolon = false;
    string s1;
    getline(iss, s1);
    cout << s1;
   }else if (semicolon) {
    cout << endl;
    for (int i = 0; i < spaces; ++i) {
     cout << " ";
    }
    cout << character;
    semicolon = false;
   } else if (character == ";") {
    cout << " " << character;
    semicolon = true;
   } else if (character == "{") {
    spaces += 1;
    cout << " " << character << endl;
   } else if (character == "}") {
    if (spaces > 0) {
     spaces -= 1;
    }
    cout << " " << character << endl;
   } else {
    cout << " " << character;
   }
  }
 }
}
