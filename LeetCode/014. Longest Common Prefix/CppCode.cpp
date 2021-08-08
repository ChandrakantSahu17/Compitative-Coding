#include<bits/stdc++.h>
using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int i=0,j=1;
        for( ; strs[0][i] ; i++){
            for( j=1 ; j<strs.size() && strs[0][i]==strs[j][i] ; j++);
            if(j != strs.size())
                break;
        }
        return strs[0].substr(0,i);
    }


int main(){
    vector<string> v = {"flower","flow","flight"};
    string s = longestCommonPrefix(v);
    cout<< s;
}