//This code is writen by some one else
//I copied this code to analyse


#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> ans(1000, vector<int>(3));

int _M[300001];
int* M = _M + 100000;

static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>>&& threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        ans.clear();
        
        int *b = &nums[0];
        int *e = &nums[nums.size()];
        for(; b < e; ++b) {
            M[*b] += 1;
        }

        sort(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));
        const int n = nums.size();
        
        if (M[0] >= 3) ans.push_back({0, 0, 0});

        b = &nums[0];
        e = b + n;
        int *b2;
        int *e2 = e - 1;
        for (; b < e; ++b) {
            const int x = *b;
            if (x == 0) continue;
            if ((x & 1) == 0) {
                int y = -x / 2;
                if (M[y] >= 2)
                    ans.push_back({x, y, y});
            }
            int *b2 = b + 1;
            int *e2 = e - 1;
            int *L = b2;
            while (L < e2) {
                typedef unsigned long long ull;
                int* M = L + ((e2 - L) >> 1);
                int y = *M;
                int z = -(x + y);
                if (z > y) L = M + 1;
                else e2 = M;
            }
            for (b2 = b + 1; b2 < e2; ++b2) {
                const int y = *b2;
                const int z = -(x + y);
                if (M[z])
                    ans.push_back({x, y, z});
            }
        }
        
        b = &nums[0];
        for (; b < e; ++b)
            M[*b] = 0;
        
        return move(ans);
    }
};