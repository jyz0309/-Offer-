class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& points) {
        int visited = 0;
        vector<int> point(numCourses);
        vector<int> result;
        for(int i=0;i<points.size();i++){
            point[points[i][0]]++;
        }
        auto iter = find(point.begin(), point.end(), 0);
        while(iter!=point.end()){
            visited++;
            result.push_back(&*iter-&point[0]);
            for(int j=0;j<points.size();j++){
                if(points[j][1]==&*iter-&point[0]){
                    point[points[j][0]]--;
                }
            }
            *iter = -1;
            numCourses--;
            iter = find(point.begin(),point.end(),0);
        }
        if(numCourses<visited){return result;}
        else {
            vector<int> cur;
            return cur;
            }
    }
};
