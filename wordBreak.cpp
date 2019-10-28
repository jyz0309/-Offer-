class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> result(s.size()+1,0);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size()+1;j++){
                if(i>0&&result[i]!=1){
                    break;
                }
                else{
                    auto iter = find(wordDict.begin(),wordDict.end(),s.substr(i,j-i));
                    if(iter!=wordDict.end()){
                        result[j] = 1;
                    }
                }
            }
        }
        if(result[s.size()]==1){
            return true;
        }
        else{
            return false;
        }
    }
};
