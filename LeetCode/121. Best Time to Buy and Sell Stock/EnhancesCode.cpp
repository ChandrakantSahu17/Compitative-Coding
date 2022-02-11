#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buyAt = prices[0];
        for( int i = 1; i<n; i++){
            maxProfit = max( maxProfit, prices[i]-buyAt );
            buyAt = min( buyAt, prices[i] );
        }
        return maxProfit;
    }
};