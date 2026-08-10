#include <iostream>
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
    // Exclude
    getallsubsets(nums, ans, i + 1, allsubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allsubsets;
    vector<int> ans;
    getallsubsets(nums, ans, 0, allsubsets);
    return allsubsets;
}

int main() {
    vector<int> nums = {1, 2, 3};
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



// #include<iostream>
// #include<string>
// using namespace std;
// void printSubsets(string str,string subset){
//     if(str.size()==0){
//         cout<<subset<<"\n";
//         return;
//     }
//     char ch=str[0];
//     //yes choice
//     printSubsets(str.substr(1,str.size()-1),subset+ch);

//     //no choice
//     printSubsets(str.substr(1,str.size()-1),subset);
// }
// int main(){
//     string str="abc";
//     string subset="";
//     printSubsets(str,subset);
//     return 0;
// }

