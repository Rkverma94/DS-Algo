#include<bits/stdc++.h>
using namespace std;
class CourseSchedule2BFS {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> g(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        vector<bool> visited(numCourses, false);
        // if(prerequisites.size() == 0) {
        //     vector<int> noPrerequisites(numCourses);
        //     for(int i=0; i<numCourses; i++) {
        //         noPrerequisites[i] = i;
        //     }
        //     return noPrerequisites;
        // }
        for(int i=0; i<prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[b].push_back(a);
            inDegree[a]++;
        }
        for(auto i=0; i<numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int topEle = q.front();q.pop();
            ans.push_back(topEle);
            for(auto it=g[topEle].begin(); it!=g[topEle].end(); it++) {
                inDegree[*it]--;
                if(inDegree[*it] == 0) q.push(*it);
            }
            
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};

int main() {
    int vertices = 4;
    vector<vector<int>> edges = {{1,0}, {2,0}, {3,1}, {3,2}};
    CourseSchedule2BFS cs2;
    vector<int> orderOfCourses = cs2.findOrder(vertices, edges);
    for(auto i : orderOfCourses) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}