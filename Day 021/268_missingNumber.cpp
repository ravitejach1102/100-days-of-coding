#include <iostream>
#include <vector>
#include <set>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int expected = n*(n + 1)/2;
    int actual=0;
    for(int i=0; i<nums.size();i++) {
        actual=actual+nums[i];
    }

    return expected-actual;
}

int main() {
    vector<int> nums = {0,1};
     cout<<missingNumber(nums)<<endl;
    return 0;
}