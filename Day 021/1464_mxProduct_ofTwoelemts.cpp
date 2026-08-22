#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {

    int mx = INT_MIN;
    int smx = INT_MIN;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] > mx) {
            smx = mx;
            mx = nums[i];
        }
        else if(nums[i] > smx) {
            smx = nums[i];
        }
    }

    return (mx - 1) * (smx - 1);
}
int main(){
    vector<int> nums={3,4,5,2};
    cout<<maxProduct(nums);
}