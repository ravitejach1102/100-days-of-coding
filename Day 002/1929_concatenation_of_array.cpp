#include<iostream>
#include<vector>
using namespace std;
vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<nums.size();j++){
            ans.push_back(nums[j]);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<int> result = getConcatenation(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}