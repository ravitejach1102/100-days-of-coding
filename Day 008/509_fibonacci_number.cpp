#include<iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}

//print fibonacci series using recursion
// int fibonacci(int n){
//     if(n<=1){
//         return n;
//     }
//     return fibonacci(n-1)+fibonacci(n-2);
// }
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cout<<fibonacci(i)<<" ";
//     }
//     return 0;
// }