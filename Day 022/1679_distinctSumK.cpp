#include<iostream>
#include<vector>
#include<map>
using namespace std;
int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int ans=k-nums[i];
            if(m[ans]>0){
                count++;
                m[ans]--;
            }else{
                m[nums[i]]++;
            }
        }
        return count;
    }
int main(){
    vector<int> nums={1,3,2,5,3,3};
    int k=6;
    cout<<maxOperations(nums,k)<<endl;
    return 0;
}