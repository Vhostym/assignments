#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
 int spaces = 0;
 string line;
 bool semicolon = false;
 bool comment = false;
 while (cin) {
  getline(cin, line);
  istringstream iss(line);
  while (iss >> line) {
   if (comment && line != "\n") {
    cout << " " << line;
    continue;
   } else if (comment) {
    comment = false;
    semicolon = true;
    continue;
   } else if (semicolon && line == "//") {
    comment = true;
    semicolon = false;
    cout << line;
    continue;
   } else if (semicolon) {
    cout << endl;
    for (int i = 0; i < spaces; ++i) {
     cout << " ";
    }
    cout << line;
    semicolon = false;
    continue;
   } else if (line == ";") {
    cout << " " << line;
    semicolon = true;
   } else if (line == "{") {
    spaces += 1;
    cout << " " << line << endl;
   } else if (line == "}") {
    if (spaces > 0) {
     spaces -= 1;
    }
    cout << " " << line << endl;
   } else if (line == "//") {
    cout << " " << line;
    comment = true;
   } else {
    cout << " " << line;
   }
  }
 }
}
