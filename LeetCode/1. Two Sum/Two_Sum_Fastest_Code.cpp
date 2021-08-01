//This code is writen by some one else
//This code is just for my analysis

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> cpy(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        vector<int> res;
        while (i < j) {
            int s = nums[i]+nums[j];
            if (s == target) {
                res = {nums[i], nums[j]};
                cout << nums[i] << nums[j] << endl;
                break;
            }
            if (s < target) i++;
            else j--;
        }
        for (int i = 0; i < cpy.size(); i++) {
            if (res[0] == cpy[i]) {
                res[0] = i;
                break;
            }
        }
        for (int i = 0; i < cpy.size(); i++) {
            if (i != res[0] && res[1] == cpy[i]) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};