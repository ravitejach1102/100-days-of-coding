//using recursive approach
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int si, int ei, int target) {
    if(si > ei) {
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    if(nums[si] <= nums[mid]) {//L1
        if(nums[si] <= target && target <= nums[mid]) {
            return search(nums, si, mid - 1, target);//search in left
        } else {
            return search(nums, mid + 1, ei, target);//search in right
        }
    } else {//L2
        if(nums[mid] <= target && target <= nums[ei]) {
            return search(nums, mid + 1, ei, target);//search in right
        } else {
            return search(nums, si, mid - 1, target);//search in left
        }
    }
    return -1;
}
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, 0, nums.size()-1, target);
    cout << result << endl;
    return 0;
}

//using iterative approach
// int search(vector<int>& nums, int target) {
//     int si=0;
//     int ei=nums.size()-1;
//     while(si <= ei) {
//         int mid = si + (ei - si) / 2;
//         if(nums[mid] == target) {
//             return mid;
//         }
//         if(nums[si] <= nums[mid]) {//L1
//             if(nums[si] <= target && target <= nums[mid]) {
//                 ei = mid - 1;//search in left
//             } else {
//                 si = mid + 1;//search in right
//             }
//         } else {//L2
//             if(nums[mid] <= target && target <= nums[ei]) {
//                 si = mid + 1;//search in right
//             } else {
//                 ei = mid - 1;//search in left
//             }
//         }
//     }
//     return -1;
// }  
// tc: O(log n)