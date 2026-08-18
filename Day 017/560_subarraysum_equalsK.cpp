#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int countsum = 0;

    for(int start = 0; start < n; start++) {
        int currSum = 0;

        for(int end = start; end < n; end++) {
            currSum = currSum + nums[end];

            if(currSum == k) {
                countsum = countsum + 1;
            }
        }
    }

    return countsum;
}

int main(){
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k) << endl;
    return 0;
}