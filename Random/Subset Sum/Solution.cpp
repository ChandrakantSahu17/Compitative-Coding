#include<bits/stdc++.h>
using namespace std;

class SubsetSum{

public:

    bool SubsetSumExistanceChecker( int sum, vector<int>& items, int i ){
        if( i < 0 || sum < 0 )
            return false;
        if( sum == 0 )
            return true;
        return SubsetSumExistanceChecker( sum-items[i], items, i-1) || SubsetSumExistanceChecker( sum, items, i-1);
    }


    bool SubsetSumExistanceCheckerDP( int sum, vector<int>& items){
        int n = items.size();
        vector<vector<bool>> t( n+1, vector<bool> (sum+1, false));
        for( int i=0; i<=n ; i++ )
            t[i][0] = true;

        for( int i=1 ; i<=n ; i++ ){
            for( int j=1; j<=sum ; j++ ){
                if( t[i-1][j-1] || t[i-1][j] )
                    t[i][j] = true;
            }
        }
        return t[n][sum];
    }


    int nosOfSolExists( int sum, vector<int>& items ){
        int n = items.size();
        vector<vector<int>> arr( n+1, vector<int> (sum+1, 0));

        for( int i=0; i<=n ; i++ )
            arr[i][0] = 1;

        for( int i=1; i<=n; i++ ){
            for( int j=1; j<=sum; ++ ){
                if( arr[i-1][j-1] || arr[i][j-])
            }
        }
    }

};


int main(){

    SubsetSum obj;
    vector<int> v = { 1, 1, 2, 3, 4};
    int sum = 11;
    cout<< obj.SubsetSumExistanceCheckerDP( sum, v);
    cout<< obj.SubsetSumExistanceChecker( sum, v, 4);

    return 0;
    
}