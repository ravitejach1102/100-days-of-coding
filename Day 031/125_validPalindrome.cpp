#include<bits/stdc++.h>
using namespace std;
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            if(!isalnum(s[i])) {
                i++;
            }
            else if(!isalnum(s[j])) {
                j--;
            }
            else {
                if(tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }

        return true;
    }
int main(){
    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome){
        cout<<"Palindrome\n";
    }else{
        cout<<"Not Palindrome\n";
    }

    return 0;
}