#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0,i=0,j=0;
        map<char,bool> m;
        while(s[i]){
            if(m.find(s[i])==m.end() || !m[s[i]]){
                m[s[i++]]=true;
            }    
            else{
                m.erase(s[j++]);
            }
            max = max>(i-j)?max:(i-j);
        }
        return max;
    }
};