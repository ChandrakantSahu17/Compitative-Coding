#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> arr;
    int rob( int i, vector<int>& nums, bool& flag ){
        if( i<flag )
            return 0;
        if( arr[i] != -1 )
            return arr[i];
        int x = rob( i-2, nums, flag)+nums[i];
        int y = rob( i-1, nums, flag);
        return arr[i] = max( x , y  );
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        arr.resize( n, -1);
        bool flag = true;
        int x = rob( n-1, nums, flag);
        arr.clear();
        arr.resize( n, -1);
        int y = rob( n-2, nums, flag = false);
        return max( x , y );
    }
};

int main(){
    vector<int> nums = { 200, 3, 140, 20, 10};
    Solution sol;
    cout<< sol.rob(nums);
    return 0;
}