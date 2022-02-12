// Conclusion : Another method I was trying is found wrong because the output of both ways are different.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int arr[101] = { 0, 1};
public:
    int getMaximumGenerated1(int n) {
        
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
            cout<<genratedmax;
        }
        
        return genratedmax;
    }
    int getMaximumGenerated2(int n){
        if( n < 2 )
            return n;
        if( arr[n] )
            return arr[n];
        if( n&1 )
            return arr[n] = ( getMaximumGenerated2(n>>2)+ getMaximumGenerated2(n>>2 + 1) );
        return arr[n] = getMaximumGenerated2(n>>2);
    }
};

int main(){
    Solution obj;
    int n = 100;

    obj.getMaximumGenerated1(100);

    cout<<endl;
    for( int i=1; i<=100 ; i++){
        cout<<max( obj.getMaximumGenerated2(i), obj.getMaximumGenerated2(i-1));
    }
    
    return 0;
}

