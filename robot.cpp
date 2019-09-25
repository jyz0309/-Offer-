class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        if(obstacles.size()==0||(x==0&&y==0)) return true;
        int cor_x = 0;
        int cor_y = 0;
        int i = 0;
        map<int,vector<int>> dic;
        for(int j=0;j<obstacles.size();j++){
            int index1 = obstacles[j][0];
            int index2 = obstacles[j][1];
            dic[index1].push_back(index2);
        }
        while(x!=cor_x||y!=cor_y){
            if(command[i%command.size()]=='U'){
                cor_y += 1;
            }
            else if(command[i%command.size()]=='R'){
                cor_x += 1;
            }
            if(cor_x>x||cor_y>y){
                return false;
            }
            
            if(dic.find(cor_x)!=dic.end()){
                if(find(dic[cor_x].begin(),dic[cor_x].end(),cor_y)!=dic[cor_x].end()){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};
