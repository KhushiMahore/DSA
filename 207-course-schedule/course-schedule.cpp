class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited, vector<int>& path) {

        visited[node] = 1;
        path[node] = 1;

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];

            if (!visited[next]) {
                if (dfs(next, graph, visited, path))
                    return true;
            }
            else if (path[next])
                return true;
        }

        path[node] = 0; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, path))
                    return false;
            }
        }
        return true;
    }
};