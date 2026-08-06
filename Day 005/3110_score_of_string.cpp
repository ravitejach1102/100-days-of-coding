#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int scoreofString(string s){
    int score = 0;
    for(int i=0;i<s.length()-1;i++){
        int result = abs(s[i]-s[i+1]);
        score += result;
    }
    return score;
}
int main(){
    string s = "hello";
    int score = scoreofString(s);
    cout << score << endl;
    return 0;
}