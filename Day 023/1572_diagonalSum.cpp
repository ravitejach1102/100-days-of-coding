#include<iostream>
#include<vector>
using namespace std;
int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int lsum=0;
        int rsum=0;
        for(int i=0;i<n;i++){
            rsum=rsum+mat[i][i];
            lsum=lsum+mat[i][n-i-1];
        }
        int total=rsum+lsum;
        if(n%2==0){
            return total;
        }else{
            return total-mat[n/2][n/2];
        }
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << diagonalSum(mat);
    return 0;
}