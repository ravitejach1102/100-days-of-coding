#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockSpan(vector<int>& stock,vector<int>& span){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<stock.size();i++){
        int currPrice=stock[i];
        while(!s.empty() && stock[s.top()]<=currPrice){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }else{
            int prevHigh=s.top();
            span[i]=i-prevHigh;
        }
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    vector<int> span={0,0,0,0,0,0,0};

    stockSpan(stock,span);
    return 0;
}


// class StockSpanner {
// public:
//     stack<pair<int,int>> s;

//     StockSpanner() {
        
//     }

//     int next(int price) {
//         int span = 1;

//         while(!s.empty() && s.top().first <= price) {
//             span += s.top().second;
//             s.pop();
//         }

//         s.push({price, span});

//         return span;
//     }
// };