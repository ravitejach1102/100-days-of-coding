#include<iostream>
using namespace std;
bool checkDivisibility(int n){
    int copy=n;
    int prod=1;
    int sum=0;
    while(n!=0){
        int digit=n%10;
        prod=prod*digit;
        sum=sum+digit;
        n=n/10;

    }
    int tot=prod+sum;
    if(copy==tot){
        return true;
    }
    return false;
}
int main(){
    int n=99;
    if(checkDivisibility(n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}