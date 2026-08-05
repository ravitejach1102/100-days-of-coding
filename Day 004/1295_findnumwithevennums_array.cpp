//using vectors
#include <iostream>
#include <vector>
using namespace std;
int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int digits=0;
            while(num>0){
                num=num/10;
                digits++;
            }
            if(digits%2==0){
                count ++;
            }
        }
        return count;
    }
int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};
    int result = findNumbers(nums);
    cout << result << endl;
    return 0;
}

//using arrays
// int evenNumdigits(int arr[], int n) {
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         int num = arr[i];
//         int digits = 0;
//         while(num > 0) {
//             num=num / 10;
//             digits++;
//         }
//         if(digits % 2 == 0) {
//             count++;
//         }
//     }
//     return count;
// }
// int main() {
//     int arr[] = {12, 345, 2, 6, 7896};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int result = evenNumdigits(arr, n);
//     cout << result << endl;
//     return 0;
// }