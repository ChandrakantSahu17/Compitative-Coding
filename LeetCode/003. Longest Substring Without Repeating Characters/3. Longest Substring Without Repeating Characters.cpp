/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
 

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/


#include<bits/stdc++.h>
using namespace std;


//We are testing below function
    int lengthOfLongestSubstring(string s) {
        //Write your code here
        int max=0,i=0,j=0;
        map<char,bool> m;
        while(s[i]){
            if(m.find(s[i])==m.end()){
                m[s[i++]]=true;
            }    
            else{
                m.erase(s[j++]);
            }
            max = max>(i-j)?max:(i-j);
        }
        return max;
    }




// A C++ Program to generate test cases for
// random number
#include<bits/stdc++.h>
using namespace std;
 
// Define the number of runs for the test data
// generated
#define RUN 5000
 
// Define the range of the test data generated
#define MAX 128
 
int main()
{
    
    freopen("input.txt","w",stdout);
 
    // For random values every time
    srand(time(NULL));
    int str_len = rand() % RUN;

    //we are going to test 20 diff randomly genrated test cases
    int TestCases = 20;
    while(TestCases-->0){
        cout<<"\"";
        for (int i=1; i<=str_len; i++){
            printf("%c", rand() % MAX);
        }
        cout<<"\"\n";
    }
    
    fclose(stdout);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    TestCases = 20;
    while(TestCases-->0){
        string s;
        cin>>s;
        int ans = lengthOfLongestSubstring(s);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);

    return(0);
}