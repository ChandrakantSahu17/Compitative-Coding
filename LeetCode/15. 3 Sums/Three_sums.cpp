//Quse:-
/*

Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []
 

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

#include<bits/stdc++.h>
using namespace std;
 

// function to be tested
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        //check for atleast 3 element
        if(n>2){
            //Sort and then pick elements one bye one
            sort(nums.begin(),nums.end());
            //variable for storing triplet
            vector<int> temp{0,0,0};
            //run loop until last 3rd element 
            //or until end of last -ve element
            //bcz we have to run minimum no. of time
            //we are going to use AND not OR
            for(int i=0;i<n-2 && nums[i]<=0;i++){
                int j=i+1,k=n-1;//j & k pointing to first and last of array
                //below logic reduce TC n^3 to n^2
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    //if sum==0 store in result
                    if(!sum){
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[k];
                        result.push_back(temp);
                        //below line is to avoid duplicate element in -ve values
                        while(j<k && nums[j++]==nums[j]);
                        //below line is to avoid duplicate element in +ve values
                        while(j<k && nums[k--]==nums[k]);
                    }
                    //if sum > 0 means sum is +ve. We need to dec(k)
                    else if(sum>0)k--;
                    //if sum > 0 means sum is -ve. We need to inc(j)
                    else j++;
                }
                //below line is to avoid duplicate element pickup for evaluation
                while(i<n-2 && nums[i]==nums[i+1])i++;
            }
        }
        return result;  
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