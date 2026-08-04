//brute force approach - O(n^2) time complexity and O(1) space complexity
// int majorityElement(vector<int>& nums) {
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         int count = 0;
//         for(int j = 0; j < n; j++){
//             if(nums[i] == nums[j]){
//                 count++;
//             }
//         }
//         if(count > n/2){
//             return nums[i];
//         }
//     }
//     return -1;
// }

//optimal approach - O(n log n) time complexity and O(1) space complexity
// int majorityElement(vector<int>& nums) {
//     int n= nums.size();
//     sort(nums.begin(), nums.end());
//     int count = 1,ans = nums[0];
//     for(int i = 1; i < n; i++){
//         if(nums[i] == nums[i-1]){
//             count++;
//         }
//         else{
//             count = 1;
//             ans = nums[i];
//         }
//         if(count > n/2){
//             return ans;
//         }
//     }
//     return ans;
// }

//moore's voting algorithm - O(n) time complexity and O(1) space complexity
#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    int count = 0, ans = 0;
    for(int i = 0; i < nums.size(); i++){
        if(count == 0){
            ans = nums[i];
        }
        if(nums[i] == ans){
            count++;
        }
        else{
            count--;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {3,2,3};
    cout << majorityElement(nums) << endl;
    return 0;
}
