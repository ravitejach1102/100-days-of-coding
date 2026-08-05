#include<iostream>
using namespace std;
bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int num=x;
    long long reverse=0;
    while(x>0){
        reverse=reverse*10+x%10;
        x=x/10;
    }
    return num == reverse;
}
int main(){
    int x;
    cin >> x;
    if(isPalindrome(x)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}