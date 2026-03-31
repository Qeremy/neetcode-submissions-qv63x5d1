class Solution {
public:
    bool dfs(int courseNum, vector<vector<int>>& preList, vector<int>& state){
        if(state[courseNum] == 1) return false;
        if(state[courseNum] == 2) return true;

        state[courseNum] = 1; // mark as visiting

        for(int i = 0; i < preList[courseNum].size(); i++){
            if(!dfs(preList[courseNum][i], preList, state)) return false;
        }
        state[courseNum] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        for(vector<int>& pre : prerequisites){
            preList[pre[0]].push_back(pre[1]);
        }
        vector<int> state(numCourses);
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, preList, state)){
                return false;
            }
        }
        return true;
    }
};
