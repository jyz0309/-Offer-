class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stack1;
        int i=0;
        for(int j=0;j<popV.size();j++){
            while(stack1.empty()||stack1.top()!=popV[j]){
                stack1.push(pushV[i++]);
                if(i > pushV.size()) return false;
            }
            stack1.pop();
        }
        if(!stack1.empty()) return false;
        else return true;
    }
};
