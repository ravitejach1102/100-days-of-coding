#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr;

    for(int x : nums1) {
        arr.push_back(x);
    }

    for(int x : nums2) {
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();

    if(n % 2 == 1) {
        return arr[n / 2];
    }
    else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}
int main(){
    vector<int> nums1={1,2};
    vector<int> nums2={3,4};

    cout<<findMedianSortedArrays(nums1,nums2)<<endl;

    return 0;
}