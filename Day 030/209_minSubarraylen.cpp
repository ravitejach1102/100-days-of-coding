#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=n+1;
        int si=0,sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            while(sum>=target){
                ans=min(ans,i-si+1);
                sum=sum-nums[si];
                si++;
            }
        }
        if(ans>n){
            ans=0;
        }
        return ans;
        
    }
int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;

    minSubArrayLen(target,nums);

    return 0;
}