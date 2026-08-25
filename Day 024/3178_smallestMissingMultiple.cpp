#include<iostream>
#include<set>
#include<vector>
using namespace std;

int missingMultiple(vector<int>& nums, int k) {
    set<int> s;

    for(int x : nums){
        s.insert(x);
    }

    int i = 1;

    while(true){
        if(s.find(k * i) == s.end()){
            return k * i;
        }
        i++;
    }
}

int main(){
    vector<int> nums = {8, 2, 3, 4, 6};
    int k = 2;

    cout << missingMultiple(nums, k) << endl;
}