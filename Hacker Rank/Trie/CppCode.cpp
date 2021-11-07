#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

struct TrieNode{
    struct TrieNode *children[26] = {NULL};
    int count[26] = { 0 };
};
 
typedef struct TrieNode Trie;
 
Trie *getNode(void){
    Trie *pointer =  new TrieNode;
    return pointer;
}

    void add(Trie *root, string s){
        int i = -1;
        while(s[++i]){
            int loc = s[i] - 'a';
            if( root->children[loc] == NULL)
                root->children[loc] = getNode();
            root->count[loc] += 1;
            root = root->children[loc];
        }
    }
    
    int find(Trie *root, string s){
        int i = -1;
        int c = 0;
        while(s[++i]){
            int loc = s[i] - 'a';
            if(root->children[loc] == NULL)
                return 0;
            c = root->count[loc];
            root = root->children[loc];
        }
        return c;
    }

vector<int> contacts(vector<vector<string>> queries){
    vector<int> v;
    Trie * root = getNode();
    for(int i=0; i < queries.size(); i++){
        if(queries[i][0][0]=='a')
            add( root, queries[i][1]);
        else
            v.push_back( find(root, queries[i][1]) );
    }
    return v;
}

int main()
{

    vector<vector<string>> queries = {{"add","hack"},{"add","hackerrank"},{"find","hac"},{"find","hak"}};

    vector<int> result = contacts(queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}

