#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getSecondLargest(vector<int> &arr) {
    int mx = INT_MIN;
        int smx = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > mx) {
                smx = mx;
                mx = arr[i];
            }
            else if (arr[i] > smx && arr[i] != mx) {
                smx = arr[i];
            }
        }

        if (smx == INT_MIN) {
            return -1;
        }

        return smx;
    }

int main() {
    vector<int> arr = {10, 5, 8, 20, 15};

    cout << getSecondLargest(arr);

    return 0;
}