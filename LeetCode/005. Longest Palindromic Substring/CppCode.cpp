#include<bits/stdc++.h>
using namespace std;


    vector<vector<int>> Table;
    string s;
    void TableFilling(int i,int j){

        if(Table[i][j]) return;

        if(s[i]==s[j]){
            if(i+1 == j){
                Table[i][j]=1;
                return;
            }
            TableFilling(i+1,j-1);
            if(Table[i+1][j-1]){
                Table[i][j]=1;
                return;
            }
            
        }
        Table[i][j]=-1;
        TableFilling(i,j-1);
        if(Table[i][j-1] != 1)
            TableFilling(i+1,j);
    }

    string longestPalindrome(string input) {
        int n = input.length();

        if(n==1) return input;
        
        int i,j,k;
        s = input;

        for(i=0;i<n;i++){
            vector<int> v(n-i-1,0);
            v.push_back(1);
            Table.insert(Table.begin(), v);
        }
        
        TableFilling(0,n-1);

        for(i=n-1;i>=0;i--){
            for(k=i,j=0; k<n ; j++,k++){
                cout<<k<<" "<<j<<endl;
                if(Table[j][k]==1)
                    return s.substr(j,k-j+1);
            }
        }
        return "Just to Remove Warning";
    }


int main(){
    string s = "babad";
    s = longestPalindrome(s);
    cout<<s;
    
}