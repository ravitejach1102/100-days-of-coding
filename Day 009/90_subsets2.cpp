#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
void getallsubsets(vector<int>& nums, vector<int>& ans, int i,vector<vector<int>>& allsubsets) {
    if (i == nums.size()) {
        allsubsets.push_back(ans);
        return;
    }
    // Include
    ans.push_back(nums[i]);
    getallsubsets(nums, ans, i + 1, allsubsets);
    // Backtrack
    ans.pop_back();
    int idx=i+1;
    while(idx<nums.size()&&nums[idx]==nums[idx-1]){
        idx++;
    }
     // Exclude
    getallsubsets(nums, ans, idx, allsubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> allsubsets;
    vector<int> ans;
    getallsubsets(nums, ans, 0, allsubsets);
    return allsubsets;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsets(nums);
    for (vector<int> subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}