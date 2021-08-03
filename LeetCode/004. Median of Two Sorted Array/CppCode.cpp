/*
Ques:-
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/



#include<bits/stdc++.h>
#include<limits>
using namespace std;

    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int TotalLen = A.size()+B.size();

        if(!TotalLen) return 0;

        int mx = numeric_limits<int>::max();
        int mn = numeric_limits<int>::min();

        A.insert(A.begin(),mn);
        A.insert(A.end(),mx);
        B.insert(B.begin(),mn);
        B.insert(B.end(),mx);
        TotalLen+=4;
        
        if(A.size()>B.size()){
            auto T = A;
            A = B;
            B = T;
        }
        
        double median;
        int start=0, end=A.size()-1;
        int mid, partitionYat;
        while(true){
            mid = (start+end)/2;
            partitionYat =  (TotalLen+1)/2 - mid -2;
            if(A[mid]>B[partitionYat+1])
                end = mid;
            else if(A[mid+1]<B[partitionYat])
                start = mid;
            else{
                if(TotalLen%2)
                    return max(A[mid],B[partitionYat]);
                median = max(A[mid],B[partitionYat])+min(A[mid+1],B[partitionYat+1]);
                median /= 2;
                return median;
            }
        }
        
    }


int main(){
    vector<int> n1={1,2};
    vector<int> n2={3,4};
    double median = findMedianSortedArrays(n1,n2);
    cout<<median;
}
