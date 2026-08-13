#include<iostream>
using namespace std;
    int addDigits(int num) {
        if(num==0){
            return 0;
        }
        return 1+(num-1)%9;
    }

int main(){
        cout<<addDigits(38);
        return 0;
    }

    // int addDigits(int num) {
    //     int sum = 0;

    //     while (num != 0) {
    //         int digit = num % 10;
    //         sum = sum + digit;
    //         num = num / 10;
    //     }

    //     while (sum > 9) {
    //         num = sum;
    //         sum = 0;

    //         while (num != 0) {
    //             int digit = num % 10;
    //             sum = sum + digit;
    //             num = num / 10;
    //         }
    //     }

    //     return sum;
    // }
    
