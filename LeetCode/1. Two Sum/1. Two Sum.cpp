//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                result.push_back(mp[target-nums[i]]);
                result.push_back(i);
                break;
            }
            
        }
        return result;
    }
};
