#include<bits/stdc++.h>
using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
    int l = INT_MIN;

    for(int i = 0; i < nums.size(); i++) {
        l = max(l, nums[i]);

        int s = INT_MAX;

        for(int j = i; j < nums.size(); j++) {
            s = min(s, nums[j]);
        }

        if((l - s) <= k) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;

    cout << firstStableIndex(nums, k) << endl;

    return 0;
}