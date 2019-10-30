class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& points) {
        int visited = 0;
        vector<int> point(numCourses);
        for(int i=0;i<points.size();i++){
            point[points[i][1]]++;
        }
        auto iter = find(point.begin(), point.end(), 0);
        while(iter!=point.end()){
            visited++;
            for(int j=0;j<points.size();j++){
                if(points[j][0]==&*iter-&point[0]){ //查找元素下标的方式。
                    point[points[j][1]]--;
                }
            }
            *iter = -1;
            numCourses--;
            iter = find(point.begin(),point.end(),0);
        }
        if(numCourses<visited){return true;}
        else {return false;}
    }
};
