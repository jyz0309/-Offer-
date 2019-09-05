class Solution {
public:
    vector<string> ans;
    void back(int n,string s,int left,int right){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(left<n){
            
            back(n,s+"(",left+1,right);
        }
        if(left>right){
           
            back(n,s+")",left,right+1);
        }  
    }
    vector<string> generateParenthesis(int n) {
        back(n,"",0,0);
        return ans;
    }
};
