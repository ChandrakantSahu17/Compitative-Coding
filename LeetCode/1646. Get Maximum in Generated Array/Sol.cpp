// TC = O(n)
// SC = O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if( n<2 )
            return n;
        
        vector<int> table( n+1 );
        table[0] = 0;
        table[1] = 1;
        int genratedmax = 1;
        
        for( int i = 2; i <= n; i++){
            int temp = i>>1;
            table[i] = table[temp];
            if( i&1 ) table[i] += table[temp+1];
            if( genratedmax < table[i]) genratedmax = table[i];
        }
        
        return genratedmax;
    }
};