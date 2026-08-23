#include <iostream>
#include <vector>
using namespace std;
  void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp;
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            temp.push_back(nums[i]);
        }
        nums=temp;
    }
int main(){
    vector<int> nums={1,2,3,4,5};
    int k=2;
    rotate(nums,k);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}