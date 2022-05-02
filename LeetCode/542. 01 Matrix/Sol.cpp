class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue< pair<int,int> > Q;
        int m = mat.size();
        int n = mat[0].size();
        
        for( int i=0; i<m ; i++ ){
            for( int j=0; j<n; j++ ){
                if( mat[i][j] )
                    mat[i][j] = -1;// -1 not visited, -2 visited but distance not updated.
                else{
                    Q.push( make_pair( i, j) );
                }
            }
        }
        
        int lvl = 0;
        while( ! Q.empty() ){
            int lvlSize = Q.size();
            
            while( lvlSize-- ){
                
                pair<int,int> p = Q.front();
                Q.pop();
                int i = p.first;
                int j = p.second;
                mat[i][j] = lvl;
                
                if( i > 0 && mat[i-1][j] == -1 ){
                    mat[i-1][j] = -2;
                    Q.push( make_pair( i-1, j ) );
                }
                if( j > 0 && mat[i][j-1] == -1 ){
                    mat[i][j-1] = -2;
                    Q.push( make_pair( i, j-1 ) );
                }
                if( i+1 < m && mat[i+1][j] == -1 ){
                    mat[i+1][j] = -2;
                    Q.push( make_pair( i+1, j ) );
                }
                if( j+1 < n && mat[i][j+1] == -1 ){
                    mat[i][j+1] = -2;
                    Q.push( make_pair( i, j+1 ) );
                }
                
            }
            
            lvl++;
        }
        
        return mat;
    }
};
