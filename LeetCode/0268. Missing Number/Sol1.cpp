// Question Link : https://leetcode.com/problems/missing-number/
// Time : O(N)
// Space : O(1)
// Approch : place all the element to their respective postion
// 	  internally we are using counting sort


class Solution {
    inline void swap( int& i, int& j){
        i = i^j;
        j = i^j;
        i = i^j;
    }
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, k = nums.size();
        nums.push_back( -1 );
        
        while( i < nums.size() ){
            if( nums[i] == -1 || nums[i] == i )
                i++;
            else{
                swap( nums[i], nums[nums[i]] );
                k = nums[i] < 0 ? i : k;
            }
                
        }
        
        return k;
    }
};
