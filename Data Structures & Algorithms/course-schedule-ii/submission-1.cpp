class Solution {
public:
    vector<int> listPre;
    unordered_set<int> taken;
    bool dfs(vector<vector<int>> preList, vector<int> state, int course){
        // 0 is unvisited, 1 is currently visiting, 2 is fully visited
        if(state[course] == 2){
            return true;
        }
        if(state[course] == 1){
            return false;
        }
        state[course] = 1;
        for(int i : preList[course]){
            if(!dfs(preList, state, i)){
                return false;
            }
        }
        if(!taken.count(course)){
            taken.insert(course);
            listPre.push_back(course);
        }
        state[course] = 2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        for(auto& pre : prerequisites){
            preList[pre[0]].push_back(pre[1]);
        }
        vector<int> state(numCourses);
        for(int i = 0; i < numCourses; i++){
            state[i] = 0;
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(preList, state, i)){
                return {};
            }
            if(!taken.count(i)){
                taken.insert(i);
                listPre.push_back(i);
            }
        }
        return listPre;


    }
};
