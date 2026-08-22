#include <iostream>
#include <vector>
#include <set>
using namespace std;
int distinctPrimeFactors(vector<int>& nums) {
    set<int> factors;
    for(int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        for(int j = 2; j * j <= n; j++) {
            if(n % j == 0) {
                factors.insert(j);
                while(n % j == 0) {
                    n = n / j;
                }
            }
        }
        if(n > 1) {
            factors.insert(n);
        }
    }
    return factors.size();
}
int main(){
    vector<int> nums={2,4,3,7,10,6};
    cout<<distinctPrimeFactors(nums)<<endl;
}