#include<bits/stdc++.h>
using namespace std;
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(), nums1.end());

        if(min % 2 != 0)
            return true;

        for(int x : nums1) {
            if(x % 2 != 0)
                return false;
        }

        return true;
    }
int main(){
    vector<int> nums1={1,4,7};
    if(uniformArray(nums1)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}