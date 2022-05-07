int Solution::solve(vector<int> &nums, int B) {
    int n = nums.size();

    int ans = 0;
    for( int i=0; i<B ; i++ )
        ans += nums[i];

    int i = B, j = n-1;
    int sum = ans;
    while( i-- ){
        sum -= nums[i];
        sum += nums[j--];
        ans = max( sum, ans );
    }

    return ans;
}
