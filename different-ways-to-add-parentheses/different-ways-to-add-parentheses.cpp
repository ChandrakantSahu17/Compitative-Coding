class Solution {
public:
    
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        
        for( int i=0; i < exp.length(); i++ ){
            if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ){
                vector<int> leftSol = diffWaysToCompute( exp.substr(0, i));
                vector<int> rightSol = diffWaysToCompute( exp.substr(i+1) );
                for( int x : leftSol ){
                    for( int y : rightSol ){
                        switch( exp[i] ){
                            case '+':{
                                ans.push_back( x+y );
                                break;
                            }
                            case '-':{
                                ans.push_back( x-y );
                                break;
                            }
                            case '*':{
                                ans.push_back( x*y );
                                break;
                            }
                        }
                    }
                }    
            }
            
        }
        if( ans.size() == 0 )
            ans.push_back( stoi(exp) );
        
        return ans;
        
    }
};