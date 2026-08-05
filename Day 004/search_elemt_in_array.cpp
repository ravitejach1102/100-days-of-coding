#include<iostream>
#include<vector>
using namespace std;
string searchElement(vector<int> arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            return "YES";
        }
    }
    return "NO";
}
int main() {
    vector<int> arr;
    int N,target;
    cin >> N >> target;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << searchElement(arr, target) << endl;
    return 0;
}