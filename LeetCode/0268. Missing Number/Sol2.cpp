// TC : O(N)
// SC : O(1)
// Approch : sum of serise 1...N - sum of array element;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int array_sum = 0;
        array_sum = accumulate( nums.begin(), nums.end(), array_sum );
        int n = nums.size();
        int total_sum = n * (n+1) / 2;
        return total_sum - array_sum;
    }
};
