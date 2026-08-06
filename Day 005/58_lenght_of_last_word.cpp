#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
    int length = 0;
    int i = s.length() - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    return length;
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int length = lengthOfLastWord(s);
    cout << "Length of the last word: " << length << endl;
    return 0;
}