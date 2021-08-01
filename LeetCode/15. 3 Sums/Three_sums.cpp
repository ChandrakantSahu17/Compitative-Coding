

#include<bits/stdc++.h>
using namespace std;
 

// function to be tested
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n>2){
            sort(nums.begin(),nums.end());
            vector<int> temp{0,0,0};
            for(int i=0;i<n-2 && nums[i]<0;i++){
                int j=i+1,k=n-1;
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(!sum){
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[k];
                        result.push_back(temp);
                        while(j<k && nums[j++]==nums[j]);
                        while(j<k && nums[k--]==nums[k]);
                    }
                    else if(sum>0)k--;
                    else j++;
                }
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