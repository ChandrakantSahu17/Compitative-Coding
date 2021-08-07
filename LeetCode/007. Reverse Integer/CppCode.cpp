/*
Ques:-

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit
integer range [-2^31, 2^31 - 1], then return 0.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long x_copy = x,y=0;
        while(x){
            y *= 10;
            y += x%10;
            x /= 10;
        }
        if(x_copy == y)
            return true;
        return false;
        
    }
};