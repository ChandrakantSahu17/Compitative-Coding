//This code is writen by some one else
//This code is just for my analysis


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


int main()
{
    //Input file and output file opening
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //we have to pass an array to the fuction which we are going to test
    //therefor create a vector
    std::vector<int> v;

    //input in vector
    int x;
    while(cin>>x)
        v.push_back(x);

    //function callingstore result in below array
    std::vector<vector<int>> result= threeSum(v);

    //print result
    for(int i=0; i<result.size();i++){
        for(int j=0; j<result[i].size();j++){
            cout<<result[i][j]<<"   ";
        }
        cout<<endl;
    }

    //closing file
    fclose(stdin);
    fclose(stdout);
    
    return(0);
}