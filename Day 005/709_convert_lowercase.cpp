// lowercase conversion
#include <iostream>
#include <string>
using namespace std;
string convertToLowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
int main() {
    string s = "HeLLo WoRLD";
    cout << convertToLowercase(s) << endl;
    return 0;
}

//uppercase conversion
// string convertToUppercase(string s) {
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] >= 'a' && s[i] <= 'z') {
//             s[i] = s[i] - 'a' + 'A';
//         }
//     }
//     return s;
// }
