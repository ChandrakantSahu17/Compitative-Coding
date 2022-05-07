vector<int> Solution::solve(vector<int> &nums) {
    
    // Binary search for 1st +ve number
    int p = lower_bound( nums.begin(), nums.end(), 0 ) - nums.begin();
  
    // i for -ve nums and j for +ve nums
    int i = p-1, j = p;

  
    int n = nums.size();
    vector<int> ans;
    ans.reserve(n);

    // when we have numbers on both side 
    // compare sqar of both num and minimum one to ans
    while( i >= 0 && j<n ){
        int i2 = nums[i]*nums[i];
        int j2 = nums[j]*nums[j];
        if( i2 < j2 ){
            ans.push_back( i2 );
            i--;
        }
        else{
            ans.push_back( j2 );
            j++;
        }
    }

    // when you are left with only -ve nums
    while( i >= 0 ){
        ans.push_back( nums[i]*nums[i] );
        i--;
    }

    // when you are left with only +ve nums
    while( j<n ){
        ans.push_back( nums[j]*nums[j] );
        j++;
    }

    return ans;
}
