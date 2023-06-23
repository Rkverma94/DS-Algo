#include<bits/stdc++.h>
using namespace std;
class CourseSchedule2 {
public:
    stack<int> orderOfCourses;
    bool dfs(int node, vector<list<int>> &g, vector<bool> &visited, vector<bool> &currRec) {
        visited[node] = 1;
        currRec[node] = 1;
        list<int> :: iterator it;
        for(it = g[node].begin(); it != g[node].end(); it++) {
            if(!visited[*it]) {
                if(dfs(*it, g, visited, currRec)) return true;
            } else if(visited[*it] && currRec[*it]) return true;
        }
        currRec[node] = 0;
        cout<<"node is pushing in to the stack is : "<<node<<endl;
        orderOfCourses.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> g(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> currVisitedStack(numCourses, false);
        for(int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[b].push_back(a);
        }

        for(int i=0; i<numCourses; i++) {
            if(!visited[i] && dfs(i, g, visited, currVisitedStack)) {
                return vector<int>{};
            }
        }
        vector<int> ans;
        while(!orderOfCourses.empty()) {
            ans.push_back(orderOfCourses.top());
            orderOfCourses.pop();
        }
        return ans;
    }
};

int main() {
    int vertices = 4;
    vector<vector<int>> edges = {{1,0}, {2,0}, {3,1}, {3,2}};
    CourseSchedule2 cs2;
    vector<int> orderOfCourses = cs2.findOrder(vertices, edges);
    for(auto i : orderOfCourses) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}