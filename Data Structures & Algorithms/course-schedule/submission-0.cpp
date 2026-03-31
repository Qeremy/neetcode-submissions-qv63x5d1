class Solution {
public:
    bool dfs(int course, vector<vector<int>>& pre, vector<int>& state) {
        if (state[course] == 1) return false; // cycle found
        if (state[course] == 2) return true;  // already checked

        state[course] = 1; // mark as visiting

        for (int prereq : pre[course]) {
            if (!dfs(prereq, pre, state)) {
                return false;
            }
        }

        state[course] = 2; // done exploring
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);

        for (auto& p : prerequisites) {
            pre[p[0]].push_back(p[1]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, pre, state)) {
                return false;
            }
        }

        return true;
    }
};