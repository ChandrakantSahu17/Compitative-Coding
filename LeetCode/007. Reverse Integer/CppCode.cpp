/*
Quse:-
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit
integer range [-231, 231 - 1], then return 0.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool sign = x<0 ? true : false;
        x = abs(x);
        long y = 0;
        while(x){
            y *= 10;
            y += x%10;
            x /= 10;
        }
        if( y<INT_MIN || INT_MAX<y)
            return 0;
        return sign? int(-y) : int(y);
            
    }
};