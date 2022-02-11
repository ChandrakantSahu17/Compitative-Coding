#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n < 2 ) return 0;
        
        vector< vector<int> > minmax( 2, vector<int> (--n) );
        
        // now n = n-1;
        minmax[0][0] = prices[0]; // vector 0 : min
        minmax[1][n-1] = prices[n];// vector 1 : max
        
        for( int i = 1; i<n ; i++){
            minmax[0][i] = minmax[0][i-1] < prices[i] ? minmax[0][i-1] : prices[i];
            minmax[1][n-i-1] = minmax[0][n-i] > prices[n-i] ? minmax[0][n-i] : prices[n-i];
        }
        
        int profit = 0;
        for( int i=0; i<n ; i++){
            profit = max( profit, minmax[1][i] - minmax[0][i] );
        }
        
        return profit;
    }
};