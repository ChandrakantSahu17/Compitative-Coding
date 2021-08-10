// Ques :- https://leetcode.com/problems/remove-element/
//Its very easy problem
//No explanation needed
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=-1,j=0,n=nums.size();
        if(!n) return 0;
        while(j<n){
            if(nums[j]!=val)
                nums[++i] = nums[j++];
            else j++;
        }
        return i+1;
    }
};