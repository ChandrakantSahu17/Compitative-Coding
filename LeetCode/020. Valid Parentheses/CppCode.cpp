#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()%2) return false;
        
        stack<char> stack;
        
        for(int i=0; s[i]; i++){
            if( s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                stack.push(s[i]);
                continue;
            }  
            if(!stack.empty() && (s[i]==')' && stack.top()=='(' || s[i]=='}' && stack.top()=='{' || s[i]==']' && stack.top()=='[' )){
                stack.pop();
                continue;
            }
            else return false;
        }
        if(stack.empty()) return true;
        return false;
    }
};