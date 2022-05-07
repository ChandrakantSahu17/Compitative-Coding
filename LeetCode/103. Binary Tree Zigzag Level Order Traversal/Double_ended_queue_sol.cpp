// TC : O( #nodes )
// SC : O( 2 * #nodes in a level ) 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if( !root )
            return {};
        
        deque< TreeNode* > DQ;
        DQ.push_back( root );
        vector< vector<int> > ans;
        
        while( ! DQ.empty() ){
            
            // left to right 
            int s = DQ.size();
            vector<int> v;
            while( s-- ){
                TreeNode* t = DQ.front();
                v.push_back( t->val );
                DQ.pop_front();
                if( t->left ) DQ.push_back( t->left );
                if( t->right ) DQ.push_back( t->right );
            }
            ans.push_back( v );
            
            if( DQ.empty() )
                return ans;
            
            // right to left 
            s = DQ.size();
            v.clear();
            while( s-- ){
                TreeNode* t = DQ.back();
                v.push_back( t->val );
                DQ.pop_back();
                if( t->right ) DQ.push_front( t->right );
                if( t->left ) DQ.push_front( t->left );
            }
            ans.push_back( v );
            
        }
        
        return ans;
    }
};
