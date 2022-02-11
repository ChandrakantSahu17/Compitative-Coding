#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    int n;
    
    int sell( int i, int profit, vector<int>& prices){
        if( i == n ) return profit;
        return max( sell( i+1, profit, prices),//skip
                    profit + prices[i] //sell
                  );
    }
    
    int buy( int i, int profit, vector<int>& prices){
        if( i == n) return profit;
        return max( sell( i+1, profit - prices[i], prices ),//buy
                    buy( i+1, profit, prices) //skip
                  );
    }
    
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        return buy( 0, 0, prices);
    }
};

// TC O(n^2);