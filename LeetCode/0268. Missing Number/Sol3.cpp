// Approch : XOR 0...N and element of array 
// Eg :     3 0 1
//      xor 0 1 2 3 
//       =  2 
//      other then 2 will be eleminated.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = nums.size();
        int result = i;
        while( i-- ){
            result ^= nums[i];
            result ^= i;
        }
        return result;
    }
};
