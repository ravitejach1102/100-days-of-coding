#include<iostream>
#include<vector>
using namespace std;
void getPermutations(vector<int>& nums,int idx,vector<vector<int>>& ans){
    if(idx==nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        getPermutations(nums,idx+1,ans);

        swap(nums[idx],nums[i]);
    }
}
vector<vector<int>> permutations(vector<int>& nums){
    vector<vector<int>> ans;
    getPermutations(nums,0,ans);
    return ans;

}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permutations(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}


