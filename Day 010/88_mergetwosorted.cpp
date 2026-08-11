#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx=m+n-1,i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[idx]=nums1[i];
                idx--;
                i--;
            }else{
                nums1[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(j>=0){
            nums1[idx]=nums2[j];
            idx--;
            j--;
        }
    }
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}

// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     vector<int> temp;
//     int i = 0;
//     int j = 0;
//     while (i < m && j < n) {
//         if (nums1[i] <= nums2[j]) {
//             temp.push_back(nums1[i]);
//             i++;
//         } else {
//             temp.push_back(nums2[j]);
//             j++;
//         }
//     }
//     while (i < m) {
//         temp.push_back(nums1[i]);
//         i++;
//     }
//     while (j < n) {
//         temp.push_back(nums2[j]);
//         j++;
//     }
//     for (int k = 0; k < m + n; k++) {
//         nums1[k] = temp[k];
//     }
// }  
