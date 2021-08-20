#include<bits/stdc++.h>
using namespace std;


    string longestPalindrome(string s) 
    {
        int n=s.size();
        if(n<2)
            return s;
        
        int maxlen=0,start=0,i=0;
        
        while(i<n)
        {
            int rptr=i;
            int lptr=i;
            while(rptr<n-1 && s[rptr]==s[rptr+1])
                rptr++;
            
            i=rptr+1;
            
            while(lptr>0 && rptr<n-1 && s[rptr+1]==s[lptr-1])
            {
                rptr++;
                lptr--;
            }
            
            int nlen=rptr-lptr+1;
            if(nlen>maxlen)
            {
                start=lptr;
                maxlen=nlen;
            }
        }
        
        return s.substr(start,maxlen);
    }


int main(){
    string s = "babad";
    s = longestPalindrome(s);
    cout<<s;
    
}