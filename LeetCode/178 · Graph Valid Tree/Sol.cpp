#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS( int node, int parent, vector<bool>& visited, vector<vector<int>>& AdjList, int& vertexCovered){
        if( visited[node] )
            return;
        visited[node] = true;
        vertexCovered++;
        for( int adj : AdjList[node] ){
            if( adj == parent )
                continue;
            DFS( adj, node, visited, AdjList, vertexCovered);
        }
    }
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        
        if( !n )
            return true;

        if( edges.size() != n-1 )
            return false;
        
        vector<bool> visited( n, false);
        vector<vector<int>> AdjList( n, vector<int> (0) );
        int vertexCovered = 0;

        for( vector<int> e : edges ){
                AdjList[ e[1] ].push_back( e[0]);
                AdjList[ e[0] ].push_back( e[1]);
        }

        DFS( 0, -1, visited, AdjList, vertexCovered );
        return vertexCovered == n;
    }
};

int main(){
    Solution obj;
    int n = 5;
    vector<vector<int>> edges{ {0,1}, {0,2}, {0,3}, {1,4} };
    cout<<obj.validTree( n, edges);
    return 0;
}