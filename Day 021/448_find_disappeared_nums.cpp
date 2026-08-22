#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    set<int> s;
    // Put all array numbers into the set
    for(int i=0;i<nums.size();i++) {
        s.insert(nums[i]);
    }
    // Check numbers from 1 to n
    for(int i=1;i<=nums.size();i++) {
        if(s.find(i)==s.end()) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = findDisappearedNumbers(nums);
    for(int x : result) {
        cout << x << " ";
    }
    return 0;
}