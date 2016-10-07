#include <iostream>
#include <fstream>

using namespace std;

bool validWord(string word) {
    if (word.length() != 5) {
        return false;
    } else {
        for (int i = 0; i < word.length(); ++i) {
            const char c = word.at(i);
            if (i != 4 && -1 != word.find(c, i + 1)) {
                return false;
            }
        }
        return true;
    }
}

int guess(string secret, string word) {
    if(secret == word) {
        return secret.length();
    } else if (validWord(word)) {
        int c = 0;
        for (int i = 0; i < secret.length(); ++i) {
            if (secret.at(i) == word.at(i)) {
                ++c;
            }
        }
        return c;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    string secret;
    if (argc == 2) {
        ifstream file{argv[1]};
        if (!(file >> secret)) {
            cerr << "file cannot be opened" << endl;
            return 1;
        }
    } else {
        cerr << "usage wordguess [filename]" << endl;
        return 1;
    }
    if (!validWord(secret)) {
        cerr << "the secret word is invalid";
        return 1;
    }
    string word;
    int correctLetters = 0;
    while (cin >> word) {
        correctLetters = guess(secret, word);
        if (correctLetters == secret.length()) {
            cout << "you guessed correctly!" << endl;
            return 0;
        } else if (correctLetters != -1) {
            cout << correctLetters << " letters match" << endl;
        } else {
            cout << "invalid guess" << endl;
        }
    }
    return 0;
}

