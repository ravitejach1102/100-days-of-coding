#include<iostream>
using namespace std;
bool powerOfTwo(int n){
    if(n==0){
        return true;
    }
    if(n>0 && (n&(n-1))==0){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    if(powerOfTwo(n)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}